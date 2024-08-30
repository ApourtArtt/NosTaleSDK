#include "Runtime.hpp"

namespace NosTaleSDK
{
	Runtime::Runtime(
		std::shared_ptr<Interfaces::Logger> Logger,
		std::shared_ptr<Interfaces::AddressProvider> AddressProvider,
		std::shared_ptr<Interfaces::VTableProvider> VTableProvider,
		const std::vector<std::shared_ptr<Interfaces::Plugin>>& Plugins
	)
		: logger_(Logger)
		, addressProvider_(AddressProvider)
		, vTableProvider_(VTableProvider)
		, plugins_(Plugins)
	{}

	Runtime::~Runtime()
	{

	}

	bool Runtime::Initialize()
	{
		if (isInit_) return true;
		isInit_ = true;

		logger_->Debug("Initializing the runtime");

		logger_->Debug("Loading the AddressProvider");
		if (!addressProvider_->Load())
			return false;

		logger_->Debug("Loading the VTableProvider");
		if (!vTableProvider_->Load())
			return false;

		for (auto& plugin : plugins_)
			plugin->AfterRuntimeInitialization();

		return true;
	}

	void Runtime::OnShowNostaleSplash()
	{
		logger_->Debug("OnShowNostaleSplash");

		for (auto& plugin: plugins_)
			plugin->OnShowNostaleSplash();

		hasShownSplashScreen_ = true;
	}

	void Runtime::OnFreeNostaleSplash()
	{
		logger_->Debug("OnFreeNostaleSplash");

		for (auto& plugin : plugins_)
			plugin->OnFreeNostaleSplash();

		hasFreedSplashScreen_ = true;
	}

	void Runtime::Run()
	{
		Sleep(5000);
		while (!hasFreedSplashScreen_)
			Sleep(50);

		logger_->Debug("Run();");

		for (auto& plugin : plugins_)
			plugin->BeforeRuntimeRun();

		while (true)
		{
			for (auto& plugin : plugins_)
				plugin->OnRuntimeTick();

			Sleep(50);
		}

		for (auto& plugin : plugins_)
			plugin->AfterRuntimeRun();
	}

}
