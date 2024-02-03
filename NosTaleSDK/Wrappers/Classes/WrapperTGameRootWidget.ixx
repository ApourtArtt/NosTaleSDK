module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTGameRootWidget;
import WrapperTLBSWidget;
import TGameRootWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTGameRootWidget : public WrapperTLBSWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTGameRootWidget, WrapperTLBSWidget, TGameRootWidget)
    public:

    private:
        void initObject()
        {

        }
    };
}