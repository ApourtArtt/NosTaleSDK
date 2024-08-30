#pragma once
#include <vector>
#include <memory>
#include <format>
#include <Windows.h>
#include <algorithm>
#include "Interfaces/Logger.hpp"
#include "Interfaces/AddressProvider.hpp"
#include "Interfaces/VTableProvider.hpp"
#include "Interfaces/Plugin.hpp"

namespace NosTaleSDK
{
	class Runtime
	{
	public:
		Runtime(
			std::shared_ptr<Interfaces::Logger> Logger,
			std::shared_ptr<Interfaces::AddressProvider> AddressProvider,
			std::shared_ptr<Interfaces::VTableProvider> VTableProvider,
			const std::vector<std::shared_ptr<Interfaces::Plugin>>& Plugins
		);

		~Runtime();

		void OnShowNostaleSplash();
		void OnFreeNostaleSplash();
		[[nodiscard]] bool Initialize();
		void Run();


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