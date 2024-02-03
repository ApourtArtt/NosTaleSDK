module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTLBSWidget;
import WrapperTObject;
import TLBSWidget;
import VTableProvider;
import TLBSWidgetList;
import Cursor;
import Border;
import Position;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTLBSWidget : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidget, WrapperTObject, TLBSWidget)
	public:
		void SetWidgetType(const uintptr_t VT) const { obj_->widgetType = static_cast<int8_t>(VT); }
		uintptr_t GetWidgetType() const { return static_cast<uintptr_t>(obj_->widgetType); }

		void SetPosition(const int16_t X, const int16_t Y) const
		{
			obj_->border.botRightX = X + (obj_->border.botRightX - obj_->border.topLeftX);
			obj_->border.topLeftX = X;
			
			obj_->border.botRightY = Y + (obj_->border.botRightY - obj_->border.topLeftY);
			obj_->border.topLeftX = Y;
		}
		Entwell::Properties::Logical::Position GetPosition() const
		{
			return Entwell::Properties::Logical::Position(
					obj_->border.topLeftX,
					obj_->border.topLeftY
				);
		}
		
		void SetSize(const int16_t Width, const int16_t Height) const
		{
			obj_->border.botRightX = obj_->border.topLeftX + Width;
			obj_->border.botRightY = obj_->border.topLeftY + Height;
		}
		int16_t GetWidth() const { return obj_->border.botRightX - obj_->border.topLeftX; }
		int16_t GetHeight() const { return obj_->border.botRightY - obj_->border.topLeftY; }

		void SetParent(TLBSWidget* Widget) const { obj_->parent = Widget; }
		TLBSWidget* GetParent() const { return obj_->parent; }

	private:
		void initObject()
		{
			obj_->isVisible = true;
			if (!obj_->children)
				obj_->children = new TLBSWidgetList();
			obj_->isHandlingClick = true;
			obj_->cursor = Entwell::Enumerations::Cursor::NORMAL;
			obj_->widgetType = 4;
		}
	};
}