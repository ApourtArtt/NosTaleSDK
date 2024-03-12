#pragma once

#include <chrono>
import Plugin;
import WrapperTEWCustomPanelWidget;
import WrapperTGameRootWidget;
import WrapperTEWLabel;
import WrapperTNTNewServerSelectWidget2;
import AddressProvider;
import VTableProvider;

namespace NosTaleSDK::Plugins
{
    class ClockPlugin final : public Interfaces::Plugin
    {
    public:
        // ReSharper disable once CppPassValueParameterByConstReference
        explicit ClockPlugin(std::shared_ptr<Interfaces::VTableProvider> VTableProvider, std::shared_ptr<Interfaces::AddressProvider> AddressProvider)
            : Plugin("ClockPlugin")
            , vTableProvider_(VTableProvider)
            , addressProvider_(AddressProvider)
        {}

        void BeforeRuntimeRun() override;
        void CreatePanel(Wrappers::Classes::WrapperTGameRootWidget* GameRootWrapper);
        void CreateTexts();
        void RefreshTime();
        void RefreshServer();
        void RefreshChannel();
        void OnRuntimeTick() override;

    private:
        std::shared_ptr<Wrappers::Classes::WrapperTNTNewServerSelectWidget2> serverSelectWrapper_{ nullptr };

        std::shared_ptr<Wrappers::Classes::WrapperTEWCustomPanelWidget> panelWrapper_{ nullptr };

        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> timeWrapper_{ nullptr };
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> serverWrapper_{ nullptr };
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> channelWrapper_{ nullptr };

        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };

        // Store all values to avoid useless UI update.
        std::chrono::time_point<std::chrono::utc_clock, std::chrono::seconds> currentTime_;
        int16_t currentChannelDisplayed_{ -1 };
        int16_t* currentChannel_{ nullptr };
        int16_t currentServerDisplayed_{ -1 };
        int16_t* currentServerId_{ nullptr };
    };
}
