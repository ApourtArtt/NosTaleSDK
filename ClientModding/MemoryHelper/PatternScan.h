#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <stdint.h>

/**
 * @brief Get all module related information.
 * 
 * @return MODULEINFO with the module information
 */
static MODULEINFO GetModuleInfo()
{
    MODULEINFO modinfo = { 0 };
    HMODULE hModule = GetModuleHandle(NULL);
    if (hModule == 0)
        return modinfo;
    GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
    return modinfo;
}

/**
 * @brief Scan for a certain address in memory.
 * 
 * @param Pattern A scheme of the bytes we are looking for
 * @param Mask The mask of the bytes we are looking for
 * @param Offset Added to final pattern scan result
 * @return Address found + offset
 */
static void* PatternScan(const char* Pattern, const char* Mask, uint32_t Offset = 0, uint32_t Start = 0)
{
    MODULEINFO mInfo = GetModuleInfo();
	auto base = (uint32_t)mInfo.lpBaseOfDll;
	auto size = (uint32_t)mInfo.SizeOfImage;
    uint32_t patternLength = strlen(Mask);

    auto i = Start;
    if (i > base)
        i -= base;

    for (; i < size - patternLength; i++)
    {
        bool found = true;
        for (DWORD j = 0; j < patternLength && found; j++)
            found &= Mask[j] == '?' || Pattern[j] == *(char*)(base + i + j);
        if (found)
            return (void*)(base + i + Offset);
    }

    return nullptr;
}