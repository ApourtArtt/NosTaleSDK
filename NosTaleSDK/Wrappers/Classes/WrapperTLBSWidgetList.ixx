module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTLBSWidgetList;
import WrapperTList;
import TLBSWidgetList;
import VTableProvider;
import TLBSWidget;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTLBSWidgetList : public WrapperTList<TLBSWidget*>
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidgetList, WrapperTList<TLBSWidget*>, TLBSWidgetList)
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {

        }
    };
}