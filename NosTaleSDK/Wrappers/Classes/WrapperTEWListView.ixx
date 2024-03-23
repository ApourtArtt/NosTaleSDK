module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>
export module WrapperTEWListView;
import WrapperTEWStringListView;
import TEWStringListView;
import TEWListView;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWListView : public WrapperTEWStringListView
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWListView, WrapperTEWStringListView, TEWListView);
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}