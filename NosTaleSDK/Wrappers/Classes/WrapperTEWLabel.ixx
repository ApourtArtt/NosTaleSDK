module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>
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
import DelphiArray;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWLabel : public WrapperTEWControlWidgetEX
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWLabel, WrapperTEWControlWidgetEX, TEWLabel)
    public:
        void SetText(const std::string& Text) const
        {
            auto arr = Entwell::Properties::Logical::DelphiArrayHandler(std::vector<wchar_t>(Text.begin(), Text.end()));
            obj_->textPosition.text = arr.ToInternal();
        }

        void SetTextAlignment(const Entwell::Enumerations::TextAlignment TextAlignment = Entwell::Enumerations::TextAlignment::CENTERED_CENTERED) const
        {
            obj_->textStyle.textAlignment = TextAlignment;
            obj_->textPosition.pxPerLine = obj_->border.botRightX - obj_->border.topLeftX;
            obj_->textPosition.lineSpacing = obj_->border.botRightY - obj_->border.topLeftY;
        }
        void SetCentered(const bool IsCentered = true) const
        {
            obj_->textStyle.textAlignment = IsCentered ? Entwell::Enumerations::TextAlignment::CENTERED_CENTERED :
                                                         Entwell::Enumerations::TextAlignment::TOP_LEFT;
            obj_->textPosition.pxPerLine = IsCentered ? obj_->border.botRightX - obj_->border.topLeftX : 0;
            obj_->textPosition.lineSpacing = IsCentered ? obj_->border.botRightY - obj_->border.topLeftY : 0;
        }
        void SetVerticalCentered(const bool IsVerticalCentered = true) const
        {
            obj_->textStyle.textAlignment = Entwell::Enumerations::TextAlignment::CENTERED_LEFT;
            obj_->textPosition.lineSpacing = IsVerticalCentered ? obj_->border.botRightY - obj_->border.topLeftY : 0;
        }
        void SetHorizontalCentered(const bool IsHorizontalCentered = true) const
        {
            obj_->textStyle.textAlignment = Entwell::Enumerations::TextAlignment::CENTERED_CENTERED;
            obj_->textPosition.pxPerLine = IsHorizontalCentered ? obj_->border.botRightX - obj_->border.topLeftX : 0;
            obj_->textPosition.lineSpacing = IsHorizontalCentered ? 12 : 0;
        }

        void SetFontStyle(const Entwell::Enumerations::FontStyle FontStyle) const
        {
            obj_->textStyle.fontStyle = FontStyle;
        }

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
                Entwell::Enumerations::TextAlignment::TOP_LEFT
            );

            obj_->textPosition = Entwell::Properties::Graphical::TextPosition<wchar_t>(
                Entwell::Properties::Logical::Position(0, 0),
                0,
                0,
                nullptr,
                true,
                ""
            );

            obj_->isBackgroundTransparent = true;
            obj_->widgetType = 33;
            obj_->isHandlingClick = false;
        }
    };
}