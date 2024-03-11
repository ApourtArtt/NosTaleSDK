module;
#include <memory>
#include <string>
#include <format>
export module PacketLoggerPlugin;
import Plugin;
import WrapperTLBSWidgetHandler;
import WrapperTGameRootWidget;
import WrapperTNosRevCmdList;
import WrapperTNTClient;
import TNosRevCmdList;
import AddressProvider;
import VTableProvider;

namespace NosTaleSDK::Plugins
{
    export class PacketLoggerPlugin final : public Interfaces::Plugin
    {
    public:
        // ReSharper disable once CppPassValueParameterByConstReference
        explicit PacketLoggerPlugin(std::shared_ptr<Interfaces::VTableProvider> VTableProvider, std::shared_ptr<Interfaces::AddressProvider> AddressProvider)
            : Plugin("PacketLoggerPlugin")
            , vTableProvider_(VTableProvider)
            , addressProvider_(AddressProvider)
        {}

        void BeforeRuntimeRun() override
        {
            const Wrappers::Classes::WrapperTNTClient tntClientWrapper = Wrappers::Classes::WrapperTNTClient::GetNtInstance(addressProvider_);
            nosRevCmdList_ = tntClientWrapper.GetNosRevCmdList();

            
        }

    private:
        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };

        NosTaleSDK::Wrappers::Classes::WrapperTNosRevCmdList nosRevCmdList_{ nullptr };
    };
}
