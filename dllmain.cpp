#include <Windows.h>
#include <iostream>
import Runtime;
import PatternAddressProvider;
import ClassSearcherVTableProvider;
import ConsoleLogger;

NosTaleSDK::Runtime* runtime;

void InitRuntime()
{
    static bool init = false;
    if (init) return;
    init = true;

    ConsoleLogger cl;
    PatternAddressProvider patternProvider;
    ClassSearcherVTableProvider vTableProvider;
    runtime = new NosTaleSDK::Runtime(patternProvider, vTableProvider);
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
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "DLL_PROCESS_ATTACH" << std::endl;
        break;
    case DLL_THREAD_ATTACH:
        std::cout << "DLL_THREAD_ATTACH" << std::endl;
        break;
    case DLL_THREAD_DETACH:
        std::cout << "DLL_THREAD_DETACH" << std::endl;
        break;
    case DLL_PROCESS_DETACH:
        std::cout << "DLL_PROCESS_DETACH" << std::endl;
        break;
    }
    return TRUE;
}