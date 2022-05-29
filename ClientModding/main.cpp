#include "Example.h"

void EventLoop(HMODULE hModule)
{
    Example example;
    if (!example.Initialize())
    {
        Logger::Log("Failed initializing ClientModding");
        return;
    }
    Logger::Log("Client Modding successfully initialized");

    example.Run(1000);
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    Logger::Load();
    Logger::Log("Dll injected successfully");

    EventLoop(hModule);

    Logger::Unload();
    FreeLibraryAndExitThread(hModule, 0);
    return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}