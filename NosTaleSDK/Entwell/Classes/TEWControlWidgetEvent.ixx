module;
#include <stdint.h>
export module TEWControlWidgetEvent;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidgetEvent : public TEWControlWidget
	{
		uint32_t unknown20;					// 0x068
		struct TNTStarPetWidget* unknown21;	// 0x06C
	};
	static_assert(sizeof(TEWControlWidgetEvent) == 0x70, "TEWControlWidgetEvent size isn't 0x70.");
	static_assert(sizeof(TEWControlWidgetEvent) <= 0x70, "TEWControlWidgetEvent size is upper than 0x70.");
	static_assert(sizeof(TEWControlWidgetEvent) >= 0x70, "TEWControlWidgetEvent size is lower than 0x70.");
#pragma pack(pop)
}