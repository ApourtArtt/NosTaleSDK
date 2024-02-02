module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTGameRootWidget;
import WrapperTObject;
import TGameRootWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTGameRootWidget final : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTGameRootWidget, WrapperTObject, TGameRootWidget)
    public:
        /*static WrapperTGameRootWidget& GetNtInstance(const std::shared_ptr<Interfaces::AddressProvider>& Provider, const bool Refresh = false)
        {
            static WrapperTGameRootWidget* wrapper = nullptr;

            if (Refresh || wrapper == nullptr)
            {
                auto widgetHandler = WrapperTLBSWidgetHandler.GetNtInstance();
                wrapper = new WrapperTGameRootWidget(widgetHandler->GetGameRootWidget());
            }

            return *wrapper;
        }*/

    private:
        static void initObject()
        {

        }
    };
}