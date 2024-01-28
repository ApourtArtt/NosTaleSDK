module;
#include <Windows.h>
#include <Psapi.h>
#include <stdint.h>
export module MemoryUtils;

namespace NosTaleSDK::Utils
{
    export const MODULEINFO GetModuleInfo()
    {
        MODULEINFO modinfo = { 0 };
        HMODULE hModule = GetModuleHandleW(nullptr);
        if (hModule == 0)
            return modinfo;
        K32GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
        return modinfo;
    }

    export uintptr_t PatternScan(const char* Pattern, const char* Mask, int32_t Offset = 0, uint32_t Start = 0)
    {
        static MODULEINFO mInfo = GetModuleInfo();
        static auto base = (uint32_t)mInfo.lpBaseOfDll;
        static auto size = (uint32_t)mInfo.SizeOfImage;
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
                return base + i + Offset;
        }

        return 0;
    }
}
