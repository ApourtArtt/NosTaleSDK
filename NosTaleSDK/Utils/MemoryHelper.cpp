#include "MemoryHelper.hpp"

namespace NosTaleSDK::Utils
{

    MODULEINFO GetModuleInfo()
    {
        MODULEINFO modinfo = { nullptr };
        const HMODULE hModule = GetModuleHandleW(nullptr);
        if (hModule == nullptr)
            return modinfo;
        K32GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
        return modinfo;
    }

    uintptr_t PatternScan(const char* Pattern, const char* Mask, int32_t Offset, uint32_t Start)
    {
        auto [lpBaseOfDll, SizeOfImage, EntryPoint] = GetModuleInfo();
        static auto base = reinterpret_cast<uint32_t>(lpBaseOfDll);
        static auto size = static_cast<uint32_t>(SizeOfImage);
        const uint32_t patternLength = strlen(Mask);

        auto i = Start;
        if (i > base)
            i -= base;

        for (; i < size - patternLength; i++)
        {
            bool found = true;
            for (DWORD j = 0; j < patternLength && found; j++)
                found &= Mask[j] == '?' || Pattern[j] == *reinterpret_cast<char*>(base + i + j);
            if (found)
                return base + i + Offset;
        }

        return 0;
    }
}
