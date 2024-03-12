#include "PacketLoggerPlugin.hpp"

import WrapperTNosRevCmdList;
import WrapperTNTClient;
import TNosRevCmdList;

namespace NosTaleSDK::Plugins
{

    void PacketLoggerPlugin::BeforeRuntimeRun() override
    {
        const Wrappers::Classes::WrapperTNTClient tntClientWrapper = Wrappers::Classes::WrapperTNTClient::GetNtInstance(addressProvider_);
        nosRevCmdList_ = tntClientWrapper.GetNosRevCmdList();


    }
}