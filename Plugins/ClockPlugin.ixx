module;
#include <memory>
export module ClockPlugin;
import Plugin;
import WrapperTEWCustomPanelWidget;
import WrapperTLBSWidgetHandler;
import WrapperTGameRootWidget;
import WrapperTEWLabel;
import AddressProvider;
import VTableProvider;

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
            timeWrapper_ = std::make_shared<Wrappers::Classes::WrapperTEWLabel>(vTableProvider_);
            timeWrapper_->SetParent(panelWrapper_.get());
            timeWrapper_->SetSize(panelWrapper_->GetWidth(), panelWrapper_->GetHeight());
        }
        
    private:
        std::shared_ptr<Wrappers::Classes::WrapperTEWCustomPanelWidget> panelWrapper_{ nullptr };
        std::shared_ptr<Wrappers::Classes::WrapperTEWLabel> timeWrapper_{ nullptr };
        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };
    };
}
