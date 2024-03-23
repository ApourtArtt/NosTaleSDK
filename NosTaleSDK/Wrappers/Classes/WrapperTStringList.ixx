module;
#include "MacroWrapperDef.h"
#include <memory>
#include <string>
#include <vector>
export module WrapperTStringList;
import WrapperTObject;
import TStringList;
import VTableProvider;
import DelphiArray;
import DelphiArray;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	// ReSharper disable once CppClassCanBeFinal
	// ReSharper disable once CppInconsistentNaming
	export class WrapperTStringList : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTStringList, WrapperTObject, TStringList);
	public:
		std::string GetStringAt(const uint16_t Index) const
		{
			if (Index >= obj_->length)
				return "";

			Entwell::Properties::Logical::DelphiArrayRefCounted<char>* item = obj_->items[Index * 2];
			Entwell::Properties::Logical::DelphiArrayRefCountedHandler<char> arr(item);
			std::vector<char> data = arr.GetData();

			auto endPos = -1;
			for (auto i = 0; i < data.size(); i++)
			{
				if (data[i] == 0x1)
				{
					endPos = i;
					break;
				}
			}

			data.resize(endPos);

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