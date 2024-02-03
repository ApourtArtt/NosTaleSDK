module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTLBSWidget;
import WrapperTObject;
import TLBSWidget;
import VTableProvider;

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

	private:
		void initObject()
		{
		}
	};
}