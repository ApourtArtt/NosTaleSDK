#pragma once

#include <memory>
import Plugin;
import WrapperTNosRevCmdList;
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

        void BeforeRuntimeRun() override;

    private:
        std::shared_ptr<Interfaces::VTableProvider> vTableProvider_{ nullptr };
        std::shared_ptr<Interfaces::AddressProvider> addressProvider_{ nullptr };

        NosTaleSDK::Wrappers::Classes::WrapperTNosRevCmdList nosRevCmdList_{ nullptr };
    };
}
