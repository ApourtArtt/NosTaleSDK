module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
export module WrapperTPersistent;
import WrapperTObject;
import TPersistent;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTPersistent : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTPersistent, WrapperTObject, TPersistent);
	public:

	private:
		// ReSharper disable once CppMemberFunctionMayBeStatic
		// ReSharper disable once CppHiddenFunction
		void initObject() const
		{
			
		}
	};
}