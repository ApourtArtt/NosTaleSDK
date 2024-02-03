module;
#include <memory>
export module ClockPlugin;
import Plugin;
import WrapperTEWCustomPanelWidget;
import Border;
import WrapperTLBSWidgetHandler;
import PictureView;

namespace NosTaleSDK::Interfaces
{
    class AddressProvider;
    class VTableProvider;
}

namespace NosTaleSDK::Plugins
{
    export class ClockPlugin final : public Interfaces::Plugin
    {
    public:
        explicit ClockPlugin(std::shared_ptr<Interfaces::VTableProvider> VTableProvider, std::shared_ptr<Interfaces::AddressProvider> AddressProvider)
            : Plugin("ClockPlugin")
            , vTableProvider_(VTableProvider)
            , addressProvider_(AddressProvider)
        {}

        void BeforeRuntimeRun() override
        {
            const auto widgetHandlerWrapper = Wrappers::Classes::WrapperTLBSWidgetHandler::GetNtInstance(addressProvider_);
            const auto gameRootWrapper = widgetHandlerWrapper.GetGameRootWidgetWrapper();
            
            panelWrapper_ = new Wrappers::Classes::WrapperTEWCustomPanelWidget(vTableProvider_);
            panelWrapper_->SetParent(gameRootWrapper->GetInternal());
            panelWrapper_->SetSize(125, 83);
            panelWrapper_->SetPosition(
                gameRootWrapper->GetPosition().x - 205 - panelWrapper_->GetWidth(),
                5
            );
            panelWrapper_->SetImageName(1593835569);
            panelWrapper_->SetComplexViews(
                Entwell::Properties::Graphical::PictureView(470, 30, 20, 20),
                Entwell::Properties::Graphical::PictureView(450, 1, 20, 20),
                Entwell::Properties::Graphical::PictureView(473, 1, 20, 20),
                Entwell::Properties::Graphical::PictureView(490, 1, 20, 20),
                Entwell::Properties::Graphical::PictureView(490, 9, 20, 82),
                Entwell::Properties::Graphical::PictureView(490, 78, 20, 20),
                Entwell::Properties::Graphical::PictureView(473, 78, 20, 20),
                Entwell::Properties::Graphical::PictureView(450, 78, 20, 20),
                Entwell::Properties::Graphical::PictureView(450, 9, 20, 82)
            );
        }

    private:
        Wrappers::Classes::WrapperTEWCustomPanelWidget* panelWrapper_{ nullptr };
        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };
    };
}
