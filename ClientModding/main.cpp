#include "Example.h"

void Start(HMODULE hModule)
{
    ClientModdingConfig config =
    {
        .DiscordConfig =
        {
            .Active = true,
            .ApplicationId = 858502310669582346,
            .ApplicationName = "App Name",
            .ImageName = "logo",
        },
        .WingsConfig = {
            .AdditionalWings = wingsMap
            {
                { 25, levelToId
                    {
                        { 1, 1209 },
                        { 2, 1208 },
                        { 3, 1202 },
                        { 4, 1202 },
                        { 5, 1202 },
                        { 6, 1202 },
                        { 7, 1202 },
                        { 8, 1202 },
                        { 9, 1202 },
                        { 10, 1202 },
                        { 11, 1202 },
                        { 12, 1202 },
                        { 13, 1202 },
                        { 14, 1202 },
                        { 15, 1202 },
                        { 16, 1202 },
                        { 17, 1202 },
                        { 18, 1202 },
                        { 19, 1202 },
                        { 20, 1202 },
                    }
                }
            },
            .AdditionalAuras = levelToId
            {
                { 20, 7907 },
            },
        },
        .EventLoopDelay = 1000,
    };

    Example example(config);
    if (!example.Initialize())
    {
        Logger::Log("Failed initializing ClientModding");
        return;
    }
    Logger::Log("Client Modding successfully initialized");

    example.Run();
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    Logger::Load();
    Logger::Log("Dll injected successfully");

    Start(hModule);

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