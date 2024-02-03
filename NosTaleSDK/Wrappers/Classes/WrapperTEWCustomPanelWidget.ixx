module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWCustomPanelWidget;
import WrapperTEWControlWidgetEvent;
import TEWCustomPanelWidget;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWCustomPanelWidget : public WrapperTEWControlWidgetEvent
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWCustomPanelWidget, WrapperTEWControlWidgetEvent, TEWCustomPanelWidget)
    public:

    private:
        void initObject()
        {

        }
    };
}