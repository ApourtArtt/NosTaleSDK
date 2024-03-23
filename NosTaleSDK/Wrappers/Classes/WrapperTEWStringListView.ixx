module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>
export module WrapperTEWStringListView;
import WrapperTEWStringListViewCore;
import TEWStringListViewCore;
import TEWStringListView;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWStringListView : public WrapperTEWStringListViewCore
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWStringListView, WrapperTEWStringListViewCore, TEWStringListView);
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}