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
import DelphiArray;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTStringList : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTStringList, WrapperTObject, TStringList)
	public:
		std::string GetStringAt(const uint16_t Index) const
		{
			if (Index >= obj_->length)
				return "";
			const auto delphiString = obj_->items[Index * 2];
			auto arr = Entwell::Properties::Logical::DelphiArrayRefCounted(delphiString, 12);
			auto data = arr.GetData();
			return std::string(data.begin(), data.end());
		}

		uint32_t GetLength() const { return obj_->length; }

	private:
		// ReSharper disable once CppMemberFunctionMayBeStatic
		// ReSharper disable once CppHiddenFunction
		void initObject() const
		{
			
		}
	};
}