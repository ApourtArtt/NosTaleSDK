module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWMoveWidget;
import WrapperTObject;
import TEWMoveWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWMoveWidget final : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWMoveWidget, WrapperTObject, TEWMoveWidget)
    public:

    private:
        void initObject()
        {

        }
    };
}