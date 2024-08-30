#include <Windows.h>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include "TODO_TO_MOVE/PatternAddressProvider.hpp"
#include "TODO_TO_MOVE/ClassSearcherVTableProvider.hpp"
#include "TODO_TO_MOVE/ConsoleLogger.hpp"
#include "NosTaleSDK/Runtime.hpp"

NosTaleSDK::Runtime* runtime{ nullptr };
std::thread* thread{ nullptr };

void initRuntime()
{
	auto logger = std::make_shared<ConsoleLogger>();
	if (!logger->Load())
		return;

	logger->Flush();
	auto vTableProvider = std::make_shared<ClassSearcherVTableProvider>(logger);
	auto patternProvider = std::make_shared<PatternAddressProvider>(logger);
	std::vector<std::shared_ptr<NosTaleSDK::Interfaces::Plugin>> plugins;

	runtime = new NosTaleSDK::Runtime(logger, patternProvider, vTableProvider, plugins);
	if (!runtime->Initialize())
		return;

	thread = new std::thread([]
		{
			runtime->Run();
		});
	thread->detach();
}

void InitRuntime()
{
	std::once_flag init;
	std::call_once(init, initRuntime);
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