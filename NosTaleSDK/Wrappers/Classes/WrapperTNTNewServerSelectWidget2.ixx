module;
#include "MacroWrapperDef.h"
#include <memory>
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

        int32_t GetSelectedServerId() const { return obj_->selectedServerId; }
        int32_t GetCurrentServerId()
        {
            if (obj_->selectedServerId != -1)
                currentServerId_ = obj_->selectedServerId;
            return currentServerId_;
        }
        int32_t GetCurrentChannelId() const { return obj_->currentChannelId; }

        std::string GetCurrentServerName() const
        {
            int serverIndex = -1;
            
            for(int i = 0; i < 50; i++)
            {
                if (obj_->serversId[i] == currentServerId_)
                {
                    serverIndex = i;
                    break;
                }
            }

            if (serverIndex == -1)
                return "";

            auto listView = new WrapperTEWListView(obj_->serversNames);
            auto stringList = listView->GetLines();
            return stringList->GetStringAt(serverIndex);
        }
        
    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }

        int32_t currentServerId_ = -1;
    };
}