#include "ClockPlugin.hpp"
#include <memory>
#include <string>
#include <format>
import WrapperTLBSWidgetHandler;
import WrapperTNTNewServerSelectWidget2;
import WrapperTNTLoginWidget;
import TNTLoginWidget;
import FontStyle;
import TextAlignment;

namespace NosTaleSDK::Plugins
{
    void ClockPlugin::BeforeRuntimeRun() override
    {
        // Get parent of all widgets (TGameRootWidget).
        const auto widgetHandlerWrapper = Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider_);
        const auto gameRootWrapper = widgetHandlerWrapper.GetGameRootWidgetWrapper();
        const auto classes = gameRootWrapper->FindClassByName("TNTLoginWidget", vTableProvider_);
        if (classes.size() == 0)
            return;

        // Get server selection widget.
        const auto loginWidget = std::make_shared<Wrappers::Classes::WrapperTNTLoginWidget>(reinterpret_cast<Entwell::Classes::TNTLoginWidget*>(classes[0]));
        if (!loginWidget)
            return;
        serverSelectWrapper_ = loginWidget->GetServerSelectWidget();

        // Get server ID from pattern.
        currentServerId_ = **reinterpret_cast<int16_t***>(addressProvider_->GetOne("NosTaleSDK::Entwell::Value::ServerId"));
        if (!currentServerId_)
            return;

        // Get channel ID from pattern (same as server with offset => /2 because x86).
        currentChannel_ = currentServerId_ + sizeof(*currentChannel_) / 2;
        if (!currentChannel_)
            return;

        // Create Clock UI.
        CreatePanel(gameRootWrapper);
        CreateTexts();
    }

    void ClockPlugin::CreatePanel(Wrappers::Classes::WrapperTGameRootWidget* GameRootWrapper)
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
            { 470, 30, 20, 20 },
            { 450, 1, 20, 20 },
            { 473, 1, 20, 20 },
            { 490, 1, 20, 20 },
            { 490, 9, 20, 82 },
            { 490, 78, 20, 20 },
            { 473, 78, 20, 20 },
            { 450, 78, 20, 20 },
            { 450, 9, 20, 82 }
        );
    }

    void ClockPlugin::CreateTexts()
    {
        //Create time text
        timeWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
        timeWrapper_->SetParent(panelWrapper_.get());
        timeWrapper_->SetSize(panelWrapper_->GetWidth(), 18);
        timeWrapper_->SetPosition(0, 13);
        timeWrapper_->SetFontStyle(Entwell::Enumerations::FontStyle::BIG);
        timeWrapper_->SetHorizontalCentered();

        //Create server name text
        serverWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
        serverWrapper_->SetParent(panelWrapper_.get());
        serverWrapper_->SetSize(panelWrapper_->GetWidth(), 18);
        serverWrapper_->SetPosition(10, 0);
        serverWrapper_->SetPositionUnder(timeWrapper_, 10);


        //Create channel text
        channelWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
        channelWrapper_->SetParent(panelWrapper_.get());
        channelWrapper_->SetSize(panelWrapper_->GetWidth(), 18);
        channelWrapper_->SetPosition(10, 0);
        channelWrapper_->SetPositionUnder(serverWrapper_);
    }

    void ClockPlugin::RefreshTime()
    {
        const std::chrono::time_point now = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::utc_clock::now());
        if (now == currentTime_ || !timeWrapper_)
            return;

        currentTime_ = now;
        timeWrapper_->SetText(std::format("{0:%T}", now));
    }

    void ClockPlugin::RefreshServer()
    {
        if (!serverSelectWrapper_ ||
            !currentServerId_ ||
            !serverWrapper_ ||
            currentServerDisplayed_ == *currentServerId_)
            return;

        if (*currentServerId_ == 0)
        {
            serverWrapper_->SetText("Connecting...");
            return;
        }

        currentServerDisplayed_ = *currentServerId_;
        auto serverName = serverSelectWrapper_->GetServerNameById(*currentServerId_);
        const auto serverNameStr = std::format("{}", serverName);
        serverWrapper_->SetText(serverNameStr);
    }

    void ClockPlugin::RefreshChannel()
    {
        if (!serverSelectWrapper_ ||
            !currentChannel_ ||
            !channelWrapper_ ||
            currentChannelDisplayed_ == *currentChannel_)
            return;

        if (*currentChannel_ == 0)
        {
            channelWrapper_->SetText("");
            return;
        }

        currentChannelDisplayed_ = *currentChannel_;
        channelWrapper_->SetText(std::format("Channel {}", currentChannelDisplayed_));
    }

    void ClockPlugin::OnRuntimeTick() override
    {
        // Call all refresh functions on each tick.
        RefreshTime();
        RefreshServer();
        RefreshChannel();
    }
}
