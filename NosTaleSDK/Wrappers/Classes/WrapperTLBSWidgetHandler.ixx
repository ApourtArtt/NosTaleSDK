module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTLBSWidgetHandler;
import WrapperTObject;
import TLBSWidgetHandler;
import VTableProvider;
import AddressProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTLBSWidgetHandler : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidgetHandler, WrapperTObject, TLBSWidgetHandler)
    public:
        static WrapperTLBSWidgetHandler& GetNtInstance(std::shared_ptr<NosTaleSDK::Interfaces::AddressProvider> Provider, bool Refresh = false)
        {
            static WrapperTLBSWidgetHandler* wrapper = nullptr;

            if (Refresh || wrapper == nullptr)
            {
                uintptr_t ptr = Provider->GetOne("NosTaleSDK::Entwell::Classes::TLBSWidgetHandler::Singleton");
                TLBSWidgetHandler* widgetHandler = reinterpret_cast<TLBSWidgetHandler*>(ptr);
                wrapper = new WrapperTLBSWidgetHandler(widgetHandler);
            }

            return *wrapper;
        }

    private:
        void initObject()
        {

        }
    };
}