module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTLBSWidget;
import WrapperTObject;
import TLBSWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTLBSWidget : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidget, WrapperTObject, TLBSWidget)
    public:
        void SetEvenThing(uintptr_t VT) { obj->evenThing = VT; }
        uintptr_t GetEvenThing() { return obj->evenThing; }

    private:
        void initObject()
        {

        }
    };
}