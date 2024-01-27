module;
export module TMapPlayerObj;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapPlayerObj
	{
		char uselessForNow[0x1C4];
		char weaponGlow[0x12]; // 0x1C4;
		char uselessForNow2[0x31]; // 0x1D6
		char weaponRarity[1]; // 0x207
		char weaponUpgrade[1]; // 0x208
		char unknown[0x7];
	};
	static_assert(sizeof(TMapPlayerObj) == 0x210, "TMapPlayerObj does not have a size of 0x210.");
#pragma pack(pop)
}