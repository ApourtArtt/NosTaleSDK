module;
export module TMiniMapCore;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMiniMapCore : public TEWControlWidget
	{
		uint32_t unknown20;	// 0x068
		uint32_t unknown21;	// 0x06C
		uint32_t unknown22;	// 0x070
		uint32_t unknown23;	// 0x074
	};
	static_assert(sizeof(TMiniMapCore) == 0x78, "TMiniMapCore size isn't 0x78.");
	static_assert(sizeof(TMiniMapCore) <= 0x78, "TMiniMapCore size is upper than 0x78.");
	static_assert(sizeof(TMiniMapCore) >= 0x78, "TMiniMapCore size is lower than 0x78.");
#pragma pack(pop)
}