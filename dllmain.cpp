#include <Windows.h>
#include <iostream>
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

    ConsoleLogger logger;
    logger.Load();
    logger.Flush();
    PatternAddressProvider patternProvider(logger);
    ClassSearcherVTableProvider vTableProvider(logger);

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

        mov eax, 0;
        ret;
    }
}

BOOL APIENTRY DllMain(HMODULE HModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    InitRuntime();
    return TRUE;
}