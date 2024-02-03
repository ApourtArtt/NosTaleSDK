module;
export module ClockPlugin;
import Plugin;
import WrapperTEWCustomPanelWidget;
#include <memory>

namespace NosTaleSDK::Interfaces
{
    class VTableProvider;
}

namespace NosTaleSDK::Plugins
{
    export class ClockPlugin final : public Interfaces::Plugin
    {
    public:
        explicit ClockPlugin(const std::shared_ptr<Interfaces::VTableProvider> Provider)
            : Plugin("ClockPlugin")
            , provider_(Provider)
        {}

        void BeforeRuntimeRun() override
        {
            panelWrapper_ = new Wrappers::Classes::WrapperTEWCustomPanelWidget(provider_);
        }

    private:
        Wrappers::Classes::WrapperTEWCustomPanelWidget* panelWrapper_{ nullptr };
        std::shared_ptr<Interfaces::VTableProvider> provider_{ nullptr };
    };
}
