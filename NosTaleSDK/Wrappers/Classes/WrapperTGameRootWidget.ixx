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
    export class WrapperTGameRootWidget : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTGameRootWidget, WrapperTObject, TGameRootWidget)
    public:

    private:
        void initObject()
        {

        }
    };
}