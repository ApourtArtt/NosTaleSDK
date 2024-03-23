module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWControlWidgetEvent;
import WrapperTEWControlWidget;
import TEWControlWidgetEvent;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWControlWidgetEvent : public WrapperTEWControlWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWControlWidgetEvent, WrapperTEWControlWidget, TEWControlWidgetEvent);
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHiddenFunction
        void initObject()
        {

        }
    };
}