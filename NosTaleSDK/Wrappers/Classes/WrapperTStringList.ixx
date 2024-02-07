module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
export module WrapperTStringList;
import WrapperTObject;
import TStringList;
import VTableProvider;
import DelphiString;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTStringList : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTStringList, WrapperTObject, TStringList<Entwell::Properties::Logical::DelphiStringFollowedBy4Zeros>)
	public:
		const std::string& GetStringAt(uint16_t Index)
		{
			if (Index >= obj_->length || Index < 0)
				return "";
			std::wstring ws(obj_->items[Index]);
			return std::string(ws.begin(), ws.end());
		}

	private:
		// ReSharper disable once CppMemberFunctionMayBeStatic
		// ReSharper disable once CppHiddenFunction
		void initObject() const
		{
			
		}
	};
}