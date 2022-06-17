#include "Example.h"

ClientModdingConfig config =
{
    .CharacterConfig =
    {
        .StuffConfig =
        {
            .WeaponConfig =
            {
                .AdditionalWeaponsGlow = glowsMap
                {
                    { RarityType(9), upgradeToGlow
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
            .SpConfig =
            {
                .AuraConfig = levelToId
                {
                    { 20, 7907 },
                },
                .WingConfig =
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
                },
            },
            .StuffRarityConfig =
            {
                .AdditionalRarityTextStyle = rarityToTextStyle
                {
                    { RarityType(9), TextStyle(2, TextShadowOrientation::ShadowAll, Bgra(255, 127, 255, 255), Bgra(255, 0, 0, 255), TextAlignment::CenteredCentered) },
                },
                .AdditionalRarityTextVnum = rarityToTextVnum
                {
                    { RarityType(9), 59 },
                }
            },
        },
        .InteractionConfig =
        {
            .NpcTalkRangeConfig =
            {
                .DefaultTalkRange = 255,
            },
        },
    },
    .ConnectionConfig =
    {

    },
    .DiscordConfig =
    {
        .Active = true,
        .ApplicationId = 858502310669582346,
        .ApplicationName = "App Name",
        .ImageName = "ditz_logo",
    },
    .MapConfig =
    {

    },
    .GameFileConfig =
    {
        .NScliConfig = {

        }
    },
    .PacketConfig =
    {

    },
    .UIConfig =
    {
        .SpyHpMpConfig =
        {
            .SpyTarget = SpyHpMpConfig
            {
                .Activate = true,
                .SpyType = SpyType::APPROXIMATION,
            },
            .SpyGroup =
            {
                .Activate = true,
                .SpyType = SpyType::APPROXIMATION,
            },
        },
    },
    .EventLoopDelay = 10,
};
Example example(config);

void Start(HMODULE hModule)
{
    if (!example.IsReady())
    {
        Logger::Error("Failed initializing Example");
        return;
    }

    Logger::Success(" -> Example-ClientModding successfully initialized");
    example.Run();

    system("pause");
}

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
    __asm
    {
        pushad;
        pushfd;
    }
    example.OnShowNostaleSplash();
    __asm
    {
        popfd;
        popad;
    }
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash()
{
    __asm
    {
        pushad;
        pushfd;
    }
    example.OnFreeNostaleSplash();
    __asm
    {
        popfd;
        popad;

        mov eax, 0;
        ret;
    }
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    Logger::Load();
    Logger::IndentModuleName("   ");
    Logger::Success("Dll successfully injected");
    Logger::Flush();

    while (!example.IsReady())
    {
        Sleep(config.EventLoopDelay * 100);
    }

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