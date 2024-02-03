#include <Windows.h>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
import Runtime;
import PatternAddressProvider;
import ClassSearcherVTableProvider;
import ConsoleLogger;
import Logger;
import ClockPlugin;

NosTaleSDK::Runtime* runtime{ nullptr };
std::thread* thread{ nullptr };

std::shared_ptr<PatternAddressProvider> InitPatternProvider(std::shared_ptr<NosTaleSDK::Interfaces::Logger> Logger)
{
	auto patternProvider = std::make_shared<PatternAddressProvider>(Logger);

	patternProvider->RegisterPattern("NosTaleSDK::Entwell::Classes::TLBSWidgetHandler::Singleton", {
		"\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3",
		"xx????xxxx????x????x", 2, 0, { 0, 0 } });

	patternProvider->RegisterPattern("NosTaleSDK::Entwell::Classes::TEWRingArrayList::Singleton", {
		"\xe8\x00\x00\x00\x00\x84\xc0\x74\x00\xa1\x00\x00\x00\x00\x8b\x00\xe8\x00\x00\x00\x00\x8b\xd8\x8b\x47\x60\x89\x43\x60",
		"x????xxx?x????xxx????xxxxxxxx", 10, 0 });

	patternProvider->RegisterPattern("NosTaleSDK::Entwell::Classes::TNTCItemDataList::Singleton", {
		"\xe8\x00\x00\x00\x00\x8b\x55\xa0\x58\xe8\x00\x00\x00\x00\x75\x00\xa1\x00\x00\x00\x00\x8b\x10\xff\x52\x08\x8b\xd7\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00",
		"x????xxxxx????x?x????xxxxxxxx????x????", 17, 0 });

	patternProvider->RegisterPattern("NosTaleSDK::Entwell::Classes::TNTClient::Singleton", {
		"\x2e\x00\x00\x00\xa1\xb4\x51\x73\x00\x8b\x00\xba\x10\x5c\x6c\x00",
		"xxxx?????xxx????", 5, 0 });

	return patternProvider;
}

bool InitRuntime()
{
	static bool init = false;
	if (init)
		return false;
	init = true;

	//Sleep(5000);

	{
		auto logger = std::make_shared<ConsoleLogger>();
		if (!logger->Load())
			return false;

		logger->Flush();
		const auto vTableProvider = std::make_shared<ClassSearcherVTableProvider>(logger);
		const auto patternProvider = InitPatternProvider(logger);
		
		auto clockPlugin = new NosTaleSDK::Plugins::ClockPlugin(std::static_pointer_cast<std::shared_ptr<NosTaleSDK::Interfaces::VTableProvider>>(vTableProvider));

		runtime = new NosTaleSDK::Runtime(logger, patternProvider, vTableProvider, {
			std::shared_ptr<NosTaleSDK::Interfaces::Plugin>(clockPlugin)
		});
		if (!runtime->Initialize())
			return false;

		thread = new std::thread([]
		{
			runtime->Run();
		});
		thread->detach();
	}

    
	return true;
}

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
	__asm
	{
		pushad;
		pushfd;
	}

	InitRuntime();
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

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID)
{
	return TRUE;
}