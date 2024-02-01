#include <Windows.h>
#include <iostream>
#include <memory>
#include <thread>
import Runtime;
import PatternAddressProvider;
import ClassSearcherVTableProvider;
import ConsoleLogger;
import Logger;

NosTaleSDK::Runtime* runtime{ nullptr };
std::thread* thread{ nullptr };

std::shared_ptr<PatternAddressProvider> InitPatternProvider(std::shared_ptr<NosTaleSDK::Interfaces::Logger> Logger)
{
	auto patternProvider = std::make_shared<PatternAddressProvider>(Logger);

	patternProvider->RegisterPattern("NosTaleSDK::Entwell::Classes::TLBSWidgetHandler::Singleton", {
		const_cast<char*>("\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3"),
		"xx????xxxx????x????x", 2, 0 });

	return patternProvider;
}

bool InitRuntime()
{
	static bool init = false;
	if (init)
		return false;
	init = true;

	thread = new std::thread([]
	{
		//Sleep(5000);
		
		auto logger = std::make_shared<ConsoleLogger>();
		if (!logger->Load())
			return false;

		logger->Flush();
		const auto vTableProvider = std::make_shared<ClassSearcherVTableProvider>(logger);
		const auto patternProvider = InitPatternProvider(logger);

		runtime = new NosTaleSDK::Runtime(logger, patternProvider, vTableProvider);
		if (!runtime->Initialize())
			return false;
		runtime->Run();
		
		return true;
	});
	thread->detach();
    
	return true;
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
	InitRuntime();
	return TRUE;
}