module;
#include <algorithm>

#include "MacroWrapperDef.h"
#include <memory>
#include <vector>
#include <Windows.h>
export module WrapperTNTLoginWidget;
import WrapperTLBSWidget;
import TNTLoginWidget;
import WrapperTNTNewServerSelectWidget2;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTNTLoginWidget : public WrapperTLBSWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTNTLoginWidget, WrapperTLBSWidget, TNTLoginWidget);
    public:
        std::shared_ptr<WrapperTNTNewServerSelectWidget2> GetServerSelectWidget() const { return std::make_shared<WrapperTNTNewServerSelectWidget2>(obj_->serverSelect); }

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject() const
        {
            
        }
    };
}
