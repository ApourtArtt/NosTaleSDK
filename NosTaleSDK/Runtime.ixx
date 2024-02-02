module;
#include <vector>
#include <memory>
#include <format>
#include <Windows.h>
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
			const std::shared_ptr<Interfaces::VTableProvider> VTableProvider
		)
			: logger_(Logger)
			, addressProvider_(AddressProvider)
			, vTableProvider_(VTableProvider)
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
			
			return true;
		}

		void RegisterPlugin(std::shared_ptr<Plugin::Plugin> Plugin)
		{
			logger_->Info(std::format("Registering plugin: {}", Plugin->GetName()));
			plugins_.push_back(std::reference_wrapper(Plugin));
		}

		void OnShowNostaleSplash() const
		{
			logger_->Info("OnShowNostaleSplash");
		}

		void OnFreeNostaleSplash() const
		{
			logger_->Info("OnFreeNostaleSplash");
		}

		void Run() const
		{
			Sleep(5000);
			logger_->Info("Run();");


			Wrappers::Classes::WrapperTLBSWidgetHandler wHandler = Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider_);
			logger_->Info("TLBSWidgetHandler");
			logger_->Info(std::format("vTable: {}", wHandler.GetInternal()->vTable));
			logger_->Info(std::format("add: {}", reinterpret_cast<uintptr_t>(wHandler.GetInternal())));
			
			while (true)
			{
				Sleep(50);
			}
		}

	private:
		std::shared_ptr<Interfaces::Logger> logger_;
		std::shared_ptr<Interfaces::AddressProvider> addressProvider_;
		std::shared_ptr<Interfaces::VTableProvider> vTableProvider_;

		std::vector<std::shared_ptr<Plugin::Plugin>> plugins_;
		bool isInit_{ false };
	};
}