module;
export module TMapObjFxItem;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapObjFxItem : public TObject
	{
		char unknown[8];
	};
	static_assert(sizeof(TMapObjFxItem) == 0xC, "TMapObjFxItem does not have a size of 0xC.");
#pragma pack(pop)
}