module;
#include <stdint.h>
export module TNTNosMallBoughtListWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallBoughtListWidget : public TEWControlWidgetEX
	{
		uint32_t unknown20;							// 0x068
		uint32_t unknown21;							// 0x06C
		struct TEWCustomPanelWidget* unknown22;		// 0x070
		struct TEWCustomPanelWidget* unknown23;		// 0x074
		struct TEWControlWidgetEX* unknown24;		// 0x078
		struct TEWLabel* unknown25;					// 0x07C
		struct TEWLabel* unknown26;					// 0x080
		struct TEWLabel* unknown27;					// 0x084
		struct TEWLabel* unknown28;					// 0x088
		struct TEWLabel* unknown29;					// 0x08C
		struct TNTNosMallItemListWidget* unknown30;	// 0x090
		struct TEWGraphicButtonWidget* unknown31;	// 0x094
		struct TEWGraphicButtonWidget* unknown32;	// 0x098
		uint32_t unknown33;							// 0x09C
		char unknown34[28];							// 0x0A0
		struct TEWCustomPanelWidget* unknown35;		// 0x0BC
		struct TEWCustomPanelWidget* unknown36;		// 0x0C0
		struct TEWControlWidgetEX* unknown37;		// 0x0C4
		struct TEWLabel* unknown38;					// 0x0C8
		struct TEWLabel* unknown39;					// 0x0CC
		struct TEWLabel* unknown40;					// 0x0D0
		struct TNTNosMallItemListWidget* unknown41;	// 0x0D4
		struct TEWCustomPanelWidget* unknown42;		// 0x0D8
		struct TEWControlWidgetEX* unknown43;		// 0x0DC
		struct TNTNosMallItemListWidget* unknown44;	// 0x0E0
		struct TEWLabel* unknown45;					// 0x0E4
		uint8_t unknown46;							// 0x0E8
		char unknown47[3];							// 0x0E9
	};
	static_assert(sizeof(TNTNosMallBoughtListWidget) == 0xEC, "TNTNosMallBoughtListWidget size isn't 0xEC.");
	static_assert(sizeof(TNTNosMallBoughtListWidget) <= 0xEC, "TNTNosMallBoughtListWidget size is upper than 0xEC.");
	static_assert(sizeof(TNTNosMallBoughtListWidget) >= 0xEC, "TNTNosMallBoughtListWidget size is lower than 0xEC.");
#pragma pack(pop)
}