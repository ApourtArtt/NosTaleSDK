module;
#include <vector>
#include <memory>
#include <format>
#include <Windows.h>
#include <algorithm>
export module Runtime;
import Plugin;
import AddressProvider;
import VTableProvider;
import Logger;
import WrapperTLBSWidgetHandler;

namespace NosTaleSDK
{
	export class Runtime
	{
	public:
		Runtime(
			const std::shared_ptr<Interfaces::Logger> Logger,
			const std::shared_ptr<Interfaces::AddressProvider> AddressProvider,
			const std::shared_ptr<Interfaces::VTableProvider> VTableProvider,
			const std::vector<std::shared_ptr<Interfaces::Plugin>>& Plugins
		)
			: logger_(Logger)
			, addressProvider_(AddressProvider)
			, vTableProvider_(VTableProvider)
			, plugins_(Plugins)
		{}

		~Runtime()
		{

		}

		bool Initialize()
		{
			if (isInit_) return true;
			isInit_ = true;

			if (!logger_->Load())
				return false;

			logger_->Info("Initializing the runtime");

			logger_->Info("Loading the AddressProvider");
			if (!addressProvider_->Load())
				return false;

			logger_->Info("Loading the VTableProvider");
			if (!vTableProvider_->Load())
				return false;

			std::ranges::for_each(plugins_, [] (std::shared_ptr<Interfaces::Plugin> plugin)
			{
				plugin->AfterRuntimeInitialization();
			});
			
			return true;
		}

		void OnShowNostaleSplash()
		{
			logger_->Info("OnShowNostaleSplash");


			std::ranges::for_each(plugins_, [](std::shared_ptr<Interfaces::Plugin> plugin)
			{
				plugin->OnShowNostaleSplash();
			});

			hasShownSplashScreen_ = true;
		}

		void OnFreeNostaleSplash()
		{
			logger_->Info("OnFreeNostaleSplash");


			Wrappers::Classes::WrapperTLBSWidgetHandler wHandler = Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider_);
			logger_->Info("TLBSWidgetHandler");
			logger_->Info(std::format("vTable: {}", wHandler.GetInternal()->vTable));
			logger_->Info(std::format("add: {}", reinterpret_cast<uintptr_t>(wHandler.GetInternal())));


			std::ranges::for_each(plugins_, [](std::shared_ptr<Interfaces::Plugin> plugin)
			{
				plugin->OnFreeNostaleSplash();
			});

			hasFreedSplashScreen_ = true;
		}

		void Run() const
		{
			Sleep(5000);
			while (!hasFreedSplashScreen_)
				Sleep(50);

			logger_->Info("Run();");

			std::ranges::for_each(plugins_, [](std::shared_ptr<Interfaces::Plugin> plugin)
			{
				plugin->BeforeRuntimeRun();
			});
			
			while (true)
			{
				std::ranges::for_each(plugins_, [](std::shared_ptr<Interfaces::Plugin> plugin)
				{
					plugin->OnRuntimeTick();
				});

				Sleep(50);
			}

			std::ranges::for_each(plugins_, [](std::shared_ptr<Interfaces::Plugin> plugin)
			{
				plugin->AfterRuntimeRun();
			});
		}

	private:
		std::shared_ptr<Interfaces::Logger> logger_;
		std::shared_ptr<Interfaces::AddressProvider> addressProvider_;
		std::shared_ptr<Interfaces::VTableProvider> vTableProvider_;

		std::vector<std::shared_ptr<Interfaces::Plugin>> plugins_;
		bool isInit_{ false };
		bool hasShownSplashScreen_{ false };
		bool hasFreedSplashScreen_{ false };
	};
}