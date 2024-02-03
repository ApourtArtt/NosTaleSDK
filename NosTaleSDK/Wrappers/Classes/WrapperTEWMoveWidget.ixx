module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWMoveWidget;
import WrapperTEWControlWidgetEvent;
import TEWMoveWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWMoveWidget : public WrapperTEWControlWidgetEvent
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWMoveWidget, WrapperTEWControlWidgetEvent, TEWMoveWidget)
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject() const
        {
            obj_->isMovable = true;
            obj_->isScreenBounded = true;
        }
    };
}