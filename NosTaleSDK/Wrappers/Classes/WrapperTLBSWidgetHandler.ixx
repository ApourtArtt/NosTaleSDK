module;
#include "MacroWrapperDef.h"
#include <memory>
export module Wrapper:WTLBSWidgetHandler;
import :WTObject;
import :WTGameRootWidget;
import TLBSWidgetHandler;
import VTableProvider;
import AddressProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    // ReSharper disable once CppInconsistentNaming
    export class WrapperTLBSWidgetHandler final : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidgetHandler, WrapperTObject, TLBSWidgetHandler)
    public:
        static WrapperTLBSWidgetHandler& GetNtInstance(const std::shared_ptr<Interfaces::AddressProvider>& Provider, const bool Refresh = false)
        {
            static WrapperTLBSWidgetHandler* wrapper = nullptr;

            if (Refresh || wrapper == nullptr)
            {
                const uintptr_t ptr = Provider->GetOne("NosTaleSDK::Entwell::Classes::TLBSWidgetHandler::Singleton");
                const auto widgetHandler = reinterpret_cast<TLBSWidgetHandler*>(ptr);
                wrapper = new WrapperTLBSWidgetHandler(widgetHandler);
            }

            return *wrapper;
        }

        WrapperTGameRootWidget* GetGameRootWidget() const
        {
            return new WrapperTGameRootWidget(obj->gameRootWidget);
        }

    private:
        static void initObject()
        {

        }
    };
}