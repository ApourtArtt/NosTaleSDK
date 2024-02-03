module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWControlWidget;
import WrapperTLBSWidget;
import TEWControlWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWControlWidget : public WrapperTLBSWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWControlWidget, WrapperTLBSWidget, TEWControlWidget)
    public:

    private:
        void initObject()
        {

        }
    };
}