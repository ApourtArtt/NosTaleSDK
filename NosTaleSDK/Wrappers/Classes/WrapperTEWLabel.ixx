module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTEWLabel;
import WrapperTEWControlWidgetEX;
import TEWControlWidgetEX;
import TEWLabel;
import VTableProvider;
import TextStyle;
import TextPosition;
import FontStyle;
import TextShadowOrientation;
import TextAlignment;
import Bgra;
import Position;
import WideString;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWLabel : public WrapperTEWControlWidgetEX
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWLabel, WrapperTEWControlWidgetEX, TEWLabel)
    public:

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            obj_->textStyle = Entwell::Properties::Graphical::TextStyle(
                Entwell::Enumerations::FontStyle::NORMAL,
                Entwell::Enumerations::TextShadowOrientation::SHADOW_NONE,
                Entwell::Properties::Graphical::Bgra(255, 255, 255, 255),
                Entwell::Properties::Graphical::Bgra(0, 0, 0, 0),
                Entwell::Enumerations::TextAlignment::CENTERED_CENTERED
            );

            obj_->textPosition = Entwell::Properties::Graphical::TextPosition(
                Entwell::Properties::Logical::Position(0, 0),
                0,
                0,
                nullptr,
                true,
                ""
            );
        }
    };
}