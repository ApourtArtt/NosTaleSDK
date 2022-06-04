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
        .WingsConfig =
        {
            .AdditionalWings = wingsMap
            {
                { 25, levelToId
                    {
                        { 1, 1346 },
                        { 2, 1347 },
                        { 3, 1348 },
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
                    },
                },
            },
            .AdditionalAuras = levelToId
            {
                { 20, 7907 },
            },
        },
        .StuffConfig =
        {
            .AdditionalWeaponsGlow = glowsMap
            {
                { 9, upgradeToGlow
                    {
                        { 100, WeaponGlow
                            {
                                .SecondaryGlowColor = Bgra(255, 0, 0, 255),
                                .SecondaryGlowSize = 1.5,
                                .SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
                                .PrimaryGlowColor = Bgra(0, 0, 255, 255),
                                .PrimaryGlowSize = 2.,
                                .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
                            },
                        },
                    },
                },
            },
        },
        .UIConfig =
        {
            .SpyHpMpConfig =
            {
                .Activate = true,
            },
        },
        .EventLoopDelay = 1000,
    };

    Example example(config);
    if (!example.Initialize())
    {
        Logger::Error("Failed initializing Example");
        return;
    }
    Logger::Success("Client Modding successfully Example");

    example.Run();
    Sleep(5000);
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    Logger::Load("test.txt");
    Logger::IndentModuleName("   ");
    Sleep(1000);
    Logger::Success("Dll successfully injected");

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