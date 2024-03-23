module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>
export module WrapperTEWLabels;
import WrapperTEWControlWidgetEX;
import TEWControlWidgetEX;
import TEWLabels;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWLabels : public WrapperTEWControlWidgetEX
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWLabels, WrapperTEWControlWidgetEX, TEWLabels);
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}