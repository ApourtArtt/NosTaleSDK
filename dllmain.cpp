#include <Windows.h>
#include <iostream>
import Runtime;
import PatternAddressProvider;
import ClassSearcherVTableProvider;

HMODULE hModule;
NosTaleSDK::Runtime* runtime;

void Init()
{
    static bool init = false;
    if (init) return;
    init = true;
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    mode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, mode);
}

void InitRuntime()
{
    static bool init = false;
    if (init) return;

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

    Init();
    std::cout << "ShowNostaleSplash()" << std::endl;

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

    Init();
    std::cout << "FreeNostaleSplash()" << std::endl;

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
    Init();
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hModule = HModule;
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