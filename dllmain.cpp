#include <Windows.h>
#include <iostream>
#include <memory>
import Runtime;
import PatternAddressProvider;
import ClassSearcherVTableProvider;
import ConsoleLogger;

NosTaleSDK::Runtime* runtime{ nullptr };

void InitRuntime()
{
    static bool init = false;
    if (init) return;
    init = true;

    auto logger = std::make_shared<ConsoleLogger>();
    logger->Load();
    logger->Flush();
    auto patternProvider = std::make_shared<PatternAddressProvider>(logger);
    auto vTableProvider = std::make_shared<ClassSearcherVTableProvider>(logger);

    runtime = new NosTaleSDK::Runtime(logger, patternProvider, vTableProvider);
    runtime->Initialize();
}

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
    __asm
    {
        pushad;
        pushfd;
    }

    runtime->OnShowNostaleSplash();

    __asm
    {
        popfd;
        popad;
        ret;
    }
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash() noexcept
{
    __asm
    {
        pushad;
        pushfd;
    }

    runtime->OnFreeNostaleSplash();

    __asm
    {
        popfd;
        popad;

        xor eax, eax;
        ret;
    }
}

BOOL APIENTRY DllMain(HMODULE HModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    InitRuntime();
    return TRUE;
}