#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <stdint.h>

namespace NosTaleSDK::Utils
{
    MODULEINFO GetModuleInfo();
    uintptr_t PatternScan(const char* Pattern, const char* Mask, int32_t Offset = 0, uint32_t Start = 0);
}