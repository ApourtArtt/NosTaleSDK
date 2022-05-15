#include "ClientModding.h"
#include "Utils/Logger.h"
#include <string>
#include "Api/PacketManager/PacketManager.h"
#include "Api/CustomClasses/Connection/Connection.h"
#include "Api/CustomClasses/MapCommon/MapCommon.h"
#include "Api/DiscordManager/DiscordManager.h"
#include "Utils/Split.h"
#include "Api/CustomClasses/Wrappers/Widgets/NewCharacterStandardInfoWidget.h"
#include "Api/CustomClasses/Wrappers/Game/SceneManager.h"
#include "Api/CustomClasses/Wrappers/Widgets/GameOptionWidget.h"
#include "Api/CustomClasses/UI/UI.h"
#include "MemoryHelper/HwndGetter.h"
#include "Api/CustomClasses/Wrappers/Widgets/GameRootWidget.h"
#include "Api/CustomClasses/Wrappers/Widgets/QuickSlotWidget.h"
#include "Api/CustomClasses/Wrappers/Widgets/NewCharacterSkillInfoWidget.h"
#include "Api/CustomClasses/Wrappers/Widgets/MonsterSummaryInfoWidget.h"
#include "Api/CustomClasses/UI/KeyBindManager.h"
#include "Api/CustomClasses/UI/KeyBindWidget.h"

#include <iostream>

void EventLoop(HMODULE hModule)
{
    HWND hwnd = getHwnd();
    ClientModding clientModding;

    Connection conn;
    MapCommon mapCom;
    PacketManager pm;

    DiscordManager dm;
    NewCharacterStandardInfoWidget::getInstance();
    SceneManager::getInstance();
    GameOptionWidget::getInstance();
    QuickSlotWidget::getInstance();
    NewCharacterSkillInfoWidget::getInstance();
    MonsterSummaryInfoWidget::getInstance();
    //KeyBindManager::getInstance();
    //UI::getInstance();
    //KeyBindWidget::getInstance();

    dm.Start();
    
    // Example of how to do an action on a packet
    pm.Subscribe(PacketType::RCVD, "tit", [&](std::string& packet)
    {
        std::cout << packet;
        auto words = Split(packet, " ");
        std::string pseudo = words[2];
        dm.SetPseudonym(pseudo);
        dm.SetChannel(conn.servChan.GetChannel());
    });
    
    while (true)
    {
        if (GetAsyncKeyState(VK_F9) & 1)
            break;
        if (GetAsyncKeyState(VK_F8) & 1)
        {
            Logger::log("Serv : %d %d\n", conn.servChan.GetServer(), conn.servChan.GetChannel());
        }
        if (GetAsyncKeyState(VK_F7) & 1)
        {
            // Example of changing map for color
            mapCom.fog.SetFirstFog(40.);
            mapCom.fog.SetSecondFog(44.);
            mapCom.fog.SetBlue(255);
        }
        if (GetAsyncKeyState(VK_F6) & 1)
        {
            // Example of changing the colors of the objects composing the map
            mapCom.object.color.SetGreen(0.);
        }
        if (GetAsyncKeyState(VK_F5) & 1)
        {
            // Example of how to send/receive a packet
            pm.Send("preq");
        }

        if (GetAsyncKeyState(VK_F10) & 1)
        {
           
        }

        if (GetAsyncKeyState(VK_F11) & 1)
        {

        }

        // Automatically turn off the game render when window is minimized
        if (!IsWindowVisible(hwnd))
            GameRootWidget::getInstance().toggleOff();
        else
            GameRootWidget::getInstance().toggleOn();
        
        Sleep(10);
    }
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    Logger::load();
    Logger::log("[ClientModdingApi]: Dll injected successfully\n\n");

    EventLoop(hModule);

    Logger::unload();
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