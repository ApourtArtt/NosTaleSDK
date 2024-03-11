module;
#include "MacroWrapperDef.h"
#include <memory>
#include <vector>
export module WrapperTNosRevCmd;
import WrapperTObject;
import TNosRevCmd;
import VTableProvider;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	export class WrapperTNosRevCmd : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTNosRevCmd, WrapperTObject, TNosRevCmd)
	public:

	private:
		void initObject() const
		{

		}
	};
}