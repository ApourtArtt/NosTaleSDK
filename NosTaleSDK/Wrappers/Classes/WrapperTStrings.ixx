module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
export module WrapperTStrings;
import WrapperTObject;
import TStrings;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTStrings : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTStrings, WrapperTObject, TStrings);
	public:

	private:
		// ReSharper disable once CppMemberFunctionMayBeStatic
		// ReSharper disable once CppHiddenFunction
		void initObject() const
		{
			
		}
	};
}