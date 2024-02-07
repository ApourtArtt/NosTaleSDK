module;
#include <chrono>
#include <memory>
#include <string>
export module ClockPlugin;
import Plugin;
import WrapperTEWCustomPanelWidget;
import WrapperTLBSWidgetHandler;
import WrapperTGameRootWidget;
import WrapperTEWLabel;
import WrapperTNTNewServerSelectWidget2;
import WrapperTNTLoginWidget;
import TNTLoginWidget;
import AddressProvider;
import VTableProvider;

namespace NosTaleSDK::Entwell::Classes
{
    struct TNTNewServerSelectWidget2;
}

namespace NosTaleSDK::Plugins
{
    export class ClockPlugin final : public Interfaces::Plugin
    {
    public:
        // ReSharper disable once CppPassValueParameterByConstReference
        explicit ClockPlugin(std::shared_ptr<Interfaces::VTableProvider> VTableProvider, std::shared_ptr<Interfaces::AddressProvider> AddressProvider)
            : Plugin("ClockPlugin")
            , vTableProvider_(VTableProvider)
            , addressProvider_(AddressProvider)
        {}

        void BeforeRuntimeRun() override
        {
            const auto widgetHandlerWrapper = Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider_);
            const auto gameRootWrapper = widgetHandlerWrapper.GetGameRootWidgetWrapper();
            const auto classes = gameRootWrapper->FindClassByName("TNTLoginWidget", vTableProvider_);
            if (classes.size() == 0)
                return;

            auto loginWidget = std::make_shared<Wrappers::Classes::WrapperTNTLoginWidget>(reinterpret_cast<Entwell::Classes::TNTLoginWidget*>(classes[0]));
            serverSelectWrapper_ = loginWidget->GetServerSelectWidget();
            
            CreatePanel(gameRootWrapper);
            if (!panelWrapper_)
                return;

            CreateTexts();
        }

        void CreatePanel(Wrappers::Classes::WrapperTGameRootWidget* GameRootWrapper)
        {
            panelWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWCustomPanelWidget>(vTableProvider_);
            panelWrapper_->SetParent(GameRootWrapper);
            panelWrapper_->SetSize(125, 83);
            panelWrapper_->SetPosition(
                GameRootWrapper->GetWidth() - 205 - panelWrapper_->GetWidth(),
                5
            );
            panelWrapper_->SetImageName(1593835569);
            panelWrapper_->SetComplexViews(
                {470, 30, 20, 20},
                {450, 1, 20, 20},
                {473, 1, 20, 20},
                {490, 1, 20, 20},
                {490, 9, 20, 82},
                {490, 78, 20, 20},
                {473, 78, 20, 20},
                {450, 78, 20, 20},
                {450, 9, 20, 82}
            );
        }

        void CreateTexts()
        {
            //Create time text
            timeWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
            timeWrapper_->SetParent(panelWrapper_.get());
            timeWrapper_->SetSize(panelWrapper_->GetWidth(), panelWrapper_->GetHeight() / 3);
            timeWrapper_->Centered();
            
            timeWrapper_->SetText("00:00:00");

            //Create server name text
            serverWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
            serverWrapper_->SetParent(panelWrapper_.get());
            serverWrapper_->SetPosition(0, panelWrapper_->GetHeight() / 3);
            serverWrapper_->SetSize(panelWrapper_->GetWidth(), panelWrapper_->GetHeight() / 3);
            serverWrapper_->Centered();
            
            serverWrapper_->SetText("Server");

            //Create channel text
            channelWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
            channelWrapper_->SetParent(panelWrapper_.get());
            channelWrapper_->SetPosition(0, panelWrapper_->GetHeight() / 3 * 2);
            channelWrapper_->SetSize(panelWrapper_->GetWidth(), panelWrapper_->GetHeight() / 3);
            channelWrapper_->Centered();
            
            channelWrapper_->SetText("Channel 0");
        }

        void RefreshTime()
        {
            const std::chrono::time_point now = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::utc_clock::now());
            if (now == currentTime_ || !timeWrapper_)
                return;

            currentTime_ = now;
            timeWrapper_->SetText(std::format("{0:%T}", now));
        }

        void RefreshServer()
        {
            if (!serverSelectWrapper_)
                return;
            auto serverName = serverSelectWrapper_->GetCurrentServerName();
            
            if (serverName == currentServer_ || !serverWrapper_)
                return;

            currentServer_ = serverName;
            serverWrapper_->SetText(std::format("{}", serverName));
        }

        void RefreshChannel()
        {
            if (!serverSelectWrapper_)
                return;
            const auto channelId = serverSelectWrapper_->GetCurrentChannelId();
            
            if (channelId == currentChannel_ || ! channelWrapper_)
                return;

            currentServer_ = channelId;
            channelWrapper_->SetText(std::format("Channel {}", channelId + 1));
        }
        
        void OnRuntimeTick() override
        {
            RefreshTime();
            RefreshServer();
            RefreshChannel();
        }
        
    private:
        std::shared_ptr<Wrappers::Classes::WrapperTNTNewServerSelectWidget2> serverSelectWrapper_{ nullptr };
        
        std::shared_ptr<Wrappers::Classes::WrapperTEWCustomPanelWidget> panelWrapper_{ nullptr };
        
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> timeWrapper_{ nullptr };
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> serverWrapper_{ nullptr };
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> channelWrapper_{ nullptr };
        
        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };

        std::chrono::time_point<std::chrono::utc_clock, std::chrono::seconds> currentTime_;
        int32_t currentChannel_{ -1 };
        std::string currentServer_ = "";
    };
}
