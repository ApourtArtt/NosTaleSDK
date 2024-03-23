module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWControlWidgetEX;
import WrapperTEWControlWidget;
import TEWControlWidgetEX;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWControlWidgetEX : public WrapperTEWControlWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWControlWidgetEX, WrapperTEWControlWidget, TEWControlWidgetEX);
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHiddenFunction
        void initObject()
        {

        }
    };
}