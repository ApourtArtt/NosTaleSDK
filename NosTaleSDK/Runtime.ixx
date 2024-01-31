module;
#include <vector>
#include <set>
#include <memory>
#include <string>
#include <format>
#include <Windows.h>
#include <iostream>
export module Runtime;
import Plugin;
import AddressProvider;
import VTableProvider;
import Logger;
import WrapperTLBSWidget;
import WrapperTLBSWidgetHandler;

namespace NosTaleSDK
{
	using namespace NosTaleSDK;

	export class Runtime
	{
	public:
		Runtime(
			std::shared_ptr<Interfaces::Logger> Logger,
			std::shared_ptr<Interfaces::AddressProvider> AddressProvider,
			std::shared_ptr<Interfaces::VTableProvider> VTableProvider
		)
			: logger(Logger)
			, addressProvider(AddressProvider)
			, vTableProvider(VTableProvider)
		{}

		~Runtime()
		{

		}

		bool Initialize()
		{
			if (isInit) return true;
			isInit = true;

			if (!logger->Load())
				return false;

			logger->Info("Initializing the runtime");

			logger->Info("Loading the AddressProvider");
			if (!addressProvider->Load())
				return false;

			logger->Info("Loading the VTableProvider");
			if (!vTableProvider->Load())
				return false;
		}

		void RegisterPlugin(std::shared_ptr<Plugin::Plugin> Plugin)
		{
			logger->Info(std::format("Registering plugin: {}", Plugin->GetName()));
			plugins.push_back(std::reference_wrapper(Plugin));
		}

		void OnShowNostaleSplash()
		{
			logger->Info("OnShowNostaleSplash");
		}

		void OnFreeNostaleSplash()
		{
			logger->Info("OnFreeNostaleSplash");
		}

		void Run()
		{
			logger->Info("Run();");

			Sleep(5000);

			//NosTaleSDK::Wrappers::Classes::WrapperTLBSWidget wWidget(vTableProvider);
			//wWidget.SetEvenThing(4);

			NosTaleSDK::Wrappers::Classes::WrapperTLBSWidgetHandler wHandler = NosTaleSDK::Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider);
			logger->Info(std::format("vTable: {}", wHandler.GetInternal()->vTable));
			logger->Info(std::format("add: {}", (uintptr_t)wHandler.GetInternal()));
			while (true)
			{
				Sleep(50);
			}
		}

	private:
		std::shared_ptr<Interfaces::Logger> logger;
		std::shared_ptr<Interfaces::AddressProvider> addressProvider;
		std::shared_ptr<Interfaces::VTableProvider> vTableProvider;

		std::vector<std::shared_ptr<Plugin::Plugin>> plugins;
		bool isInit{ false };
	};
}