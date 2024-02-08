module;
#include "MacroWrapperDef.h"
#include <memory>
#include <regex>
#include <string>
#include <vector>
#include <Windows.h>
export module WrapperTNTNewServerSelectWidget2;
import WrapperTEWControlWidgetEX;
import TEWControlWidgetEX;
import TNTNewServerSelectWidget2;
import WrapperTEWListView;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTNTNewServerSelectWidget2 : public WrapperTEWControlWidgetEX
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTNTNewServerSelectWidget2, WrapperTEWControlWidgetEX, TNTNewServerSelectWidget2)
    public:
        std::string GetServerNameById(const int16_t ServerId) const
        {
            if (ServerId == -1)
                return "";
            
            int serverIndex = -1;
            
            for(int i = 0; i < 50; i++)
            {
                if (obj_->serversIdList[i] == -1 || obj_->serversIdList[i] != ServerId)
                    continue;
                
                serverIndex = i;
                break;
            }

            if (serverIndex == -1)
                return "";

            const auto listView = new WrapperTEWListView(obj_->serversNames);
            const auto stringList = listView->GetLines();
            auto serverName = stringList->GetStringAt(serverIndex);
            const std::regex regex("\\(NEW\\)| \\([0-9]{0,2}\\)");
            std::string result;
            std::regex_replace(std::back_inserter(result), serverName.begin(), serverName.end(), regex, "");
            return result;
        }

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}