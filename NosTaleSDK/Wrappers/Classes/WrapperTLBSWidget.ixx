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
		void SetUnknown(const uintptr_t VT) const { obj->unknown = VT; }
		uintptr_t GetUnknown() const { return obj->unknown; }

	private:
		static void initObject()
		{

		}
	};
}