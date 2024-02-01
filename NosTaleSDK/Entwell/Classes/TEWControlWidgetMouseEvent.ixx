module;
export module TEWControlWidgetMouseEvent;
import TEWControlWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidgetMouseEvent : public TEWControlWidget
	{
		Properties::Logical::Callback unknown20;	// 0x068
		Properties::Logical::Callback unknown21;	// 0x070
		Properties::Logical::Callback unknown22;	// 0x078
		Properties::Logical::Callback unknown23;	// 0x080
		Properties::Logical::Callback unknown24;	// 0x088
		Properties::Logical::Callback unknown25;	// 0x090
		char unknown26[16];							// 0x098
	};
	static_assert(sizeof(TEWControlWidgetMouseEvent) == 0xA8, "TEWControlWidgetMouseEvent size isn't 0xA8.");
	static_assert(sizeof(TEWControlWidgetMouseEvent) <= 0xA8, "TEWControlWidgetMouseEvent size is upper than 0xA8.");
	static_assert(sizeof(TEWControlWidgetMouseEvent) >= 0xA8, "TEWControlWidgetMouseEvent size is lower than 0xA8.");
#pragma pack(pop)
}
