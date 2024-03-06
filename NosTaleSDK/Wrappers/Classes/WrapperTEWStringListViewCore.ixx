module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>
export module WrapperTEWStringListViewCore;
import WrapperTEWLabels;
import TEWLabels;
import TEWStringListViewCore;
import VTableProvider;
import WrapperTStringList;
import DelphiArray;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWStringListViewCore : public WrapperTEWLabels
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWStringListViewCore, WrapperTEWLabels, TEWStringListViewCore)
    public:
        std::shared_ptr<WrapperTStringList> GetLines() const
        {
            return std::make_shared<WrapperTStringList>(obj_->lines);
        } 

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}