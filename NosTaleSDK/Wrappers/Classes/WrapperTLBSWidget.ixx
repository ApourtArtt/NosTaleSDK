module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
export module WrapperTLBSWidget;
import WrapperTObject;
import TLBSWidget;
import VTableProvider;
import TLBSWidgetList;
import Cursor;
import Border;
import Position;
import WrapperTLBSWidgetList;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTLBSWidget : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTLBSWidget, WrapperTObject, TLBSWidget);
	public:
		void SetWidgetType(const uintptr_t VT) const { obj_->widgetType = static_cast<int8_t>(VT); }
		uintptr_t GetWidgetType() const { return static_cast<uintptr_t>(obj_->widgetType); }

		void SetPosition(const int16_t X, const int16_t Y) const
		{
			SetPositionX(X);
			SetPositionY(Y);
		}
		Entwell::Properties::Logical::Position GetPosition() const
		{
			return Entwell::Properties::Logical::Position(
					obj_->border.topLeftX,
					obj_->border.topLeftY
				);
		}
		void SetPositionUnder(const std::shared_ptr<WrapperTLBSWidget> Wrapper, const int16_t Padding = 0) const
		{
			auto y = Wrapper->GetPosition().y;
			auto height = Wrapper->GetHeight();
			SetPositionY(y + height + Padding);
		}
		
		void SetSize(const int16_t Width, const int16_t Height) const
		{
			obj_->border.botRightX = obj_->border.topLeftX + Width;
			obj_->border.botRightY = obj_->border.topLeftY + Height;
		}
		int16_t GetWidth() const { return obj_->border.botRightX - obj_->border.topLeftX; }
		int16_t GetHeight() const { return obj_->border.botRightY - obj_->border.topLeftY; }

		void SetParent(WrapperTLBSWidget* WidgetWrapper) const
		{
			obj_->parent = WidgetWrapper->GetInternal();
			WidgetWrapper->AddChild(obj_);
		}
		TLBSWidget* GetParent() const { return obj_->parent; }

		void AddChild(TLBSWidget* Widget) const
		{
			auto childrenWrapper = new WrapperTLBSWidgetList(obj_->children);
			childrenWrapper->pushBack(Widget);
		}

		std::vector<TLBSWidget*> FindClassByName(const std::string& Name, std::shared_ptr<Interfaces::VTableProvider> VTableProvider) const
		{
			
			if (obj_->children == nullptr)
				return {};

			const auto childrenWrapper = new WrapperTLBSWidgetList(obj_->children);

			//search
			const auto vTable = VTableProvider->Get("NosTaleSDK::Entwell::Classes::" + Name + "::VTable");

			std::vector<TLBSWidget*> widgets;

			for (auto i = 0; i < childrenWrapper->size(); i++)
			{
				const auto itemVTable = childrenWrapper->getItem(i)->vTable;
				if (itemVTable == vTable)
				{
					widgets.push_back(childrenWrapper->getItem(i));
				}
			}

			return widgets;
		}

	private:
		void SetPositionX(const int16_t X) const
		{
			obj_->border.botRightX = X + (obj_->border.botRightX - obj_->border.topLeftX);
			obj_->border.topLeftX = X;
		}
		void SetPositionY(const int16_t Y) const
		{
			obj_->border.botRightY = Y + (obj_->border.botRightY - obj_->border.topLeftY);
			obj_->border.topLeftY = Y;
		}
		
		// ReSharper disable once CppMemberFunctionMayBeStatic
		// ReSharper disable once CppHiddenFunction
		void initObject() const
		{
			obj_->isVisible = true;
			if (!obj_->children)
				obj_->children = new TLBSWidgetList();
			obj_->isHandlingClick = true;
			obj_->cursor = Entwell::Enumerations::Cursor::NORMAL;
			obj_->widgetType = 1;
		}
	};
}