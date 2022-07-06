#include "Example.h"

HMODULE hModule;

ClientModdingConfig config =
{
    .CharacterConfig =
    {
        .StuffConfig =
        {
            .WeaponConfig =
            {
                .AdditionalGlow = glowsMap
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
                },
            },
            .ArmorConfig =
            {
                .AdditionalEffects = effectsMap
                {
                    { RarityType(9), upgradeToEffectId
                        {
                            { 10, 4500 },
                        },
                    },
                },
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

        },
    },
    .PacketConfig =
    {
        .EncryptFn = [](std::string Packet)
        {
            //Logger::Log("EncryptFn: %s", Packet.c_str());
            std::string newPacket = Packet;
            for (auto i = 0; i < newPacket.size(); i++)
                newPacket[i] = newPacket[i] ^ 0x50;

            //Logger::Log("Encrypted NewPacket: %s", newPacket.c_str());
            return newPacket;
        },
        .DecryptFn = [](std::string Packet)
        {
            //Logger::Log("DecryptFn: %s", Packet.c_str());
            return Packet;
        },
    },
    .UIConfig =
    {
        .SpyHpMpConfig =
        {
            .SpyGroup =
            {
                .Activate = true,
                .SpyType = SpyType::APPROXIMATION,
            },
        },
    },
    .EventLoopDelay = 10,
};

Example* example = nullptr;

void Start(HMODULE hModule)
{
    if (!example->IsReady())
    {
        Logger::Error("Failed initializing Example");
        return;
    }

    Logger::Success(" -> Example-ClientModding successfully initialized");
    example->Run();

    system("pause");
}

void InitLogger()
{
    Logger::Load();
    Logger::IndentModuleName("   ");
}

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
    __asm
    {
        pushad;
        pushfd;
    }
    InitLogger();
    example = new Example(config);
    example->OnShowNostaleSplash();
    __asm
    {
        popfd;
        popad;
    }
}

std::thread* th = nullptr;

DWORD WINAPI MainThread(HMODULE hModule)
{
    InitLogger();

    while (!example->IsReady())
        Sleep(config.EventLoopDelay);
    // This additional sleep is to avoid calling Start so quickly that
    // not everything is initialized. Not clean needs to hook something.
    Sleep(500);

    Start(hModule);

    Logger::Unload();
    FreeLibraryAndExitThread(hModule, 0);
    return 1;
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash() noexcept
{
    __asm
    {
        pushad;
        pushfd;
    }
    example->OnFreeNostaleSplash();
    th = new std::thread([]
    {
        MainThread(hModule);
    });
    th->detach();
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
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hModule = HModule;
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}