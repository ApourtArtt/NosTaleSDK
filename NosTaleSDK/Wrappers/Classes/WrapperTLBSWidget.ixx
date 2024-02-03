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
		void SetWidgetType(const uintptr_t VT) const { obj->widgetType = static_cast<int8_t>(VT); }
		uintptr_t GetWidgetType() const { return static_cast<uintptr_t>(obj->widgetType); }

		void SetPosition(const int16_t X, const int16_t Y) const
		{
			obj->border.botRightX = X + (obj->border.botRightX - obj->border.topLeftX);
			obj->border.topLeftX = X;
			
			obj->border.botRightY = Y + (obj->border.botRightY - obj->border.topLeftY);
			obj->border.topLeftX = Y;
		}
		Entwell::Properties::Logical::Position GetPosition() const
		{
			return Entwell::Properties::Logical::Position(
					obj->border.topLeftX,
					obj->border.topLeftY
				);
		}
		
		void SetSize(const int16_t Width, const int16_t Height) const
		{
			obj->border.botRightX = obj->border.topLeftX + Width;
			obj->border.botRightY = obj->border.topLeftY + Height;
		}
		int16_t GetWidth() const { return obj->border.botRightX - obj->border.topLeftX; }
		int16_t GetHeight() const { return obj->border.botRightY - obj->border.topLeftY; }

		void SetParent(TLBSWidget* Widget) const { obj->parent = Widget; }
		TLBSWidget* GetParent() const { return obj->parent; }

	private:
		void initObject()
		{
			obj->isVisible = true;
			if (!obj->children)
				obj->children = new TLBSWidgetList();
			obj->isHandlingClick = true;
			obj->cursor = Entwell::Enumerations::Cursor::NORMAL;
			obj->widgetType = 4;
		}
	};
}