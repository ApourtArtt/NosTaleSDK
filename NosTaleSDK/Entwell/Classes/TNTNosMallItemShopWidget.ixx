module;
#include <stdint.h>
export module TNTNosMallItemShopWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallItemShopWidget : public TEWControlWidgetEX
	{
		struct TEWCustomPanelWidget* unknown20;		// 0x068
		char unknown21[20];							// 0x06C
		uint32_t unknown22;							// 0x080
		char unknown23[16];							// 0x084
		uint32_t unknown24;							// 0x094
		uint32_t unknown25;							// 0x098
		char unknown26[4];							// 0x09C
		struct TEWGraphicButtonWidget* unknown27;	// 0x0A0
		TEWGraphicButtonWidget* unknown28;			// 0x0A4
		TEWCustomPanelWidget* unknown29;			// 0x0A8
		TEWControlWidgetEX* unknown30;				// 0x0AC
		TEWGraphicButtonWidget* unknown31;			// 0x0B0
		struct TEWLabel* unknown32;					// 0x0B4
		TEWCustomPanelWidget* unknown33;			// 0x0B8
		TEWControlWidgetEX* unknown34;				// 0x0BC
		TEWControlWidgetEX* unknown35;				// 0x0C0
		TEWCustomPanelWidget* unknown36;			// 0x0C4
		TEWControlWidgetEX* unknown37;				// 0x0C8
		TEWControlWidgetEX* unknown38;				// 0x0CC
		struct TNTNosMallItemListWidget* unknown39;	// 0x0D0
		TNTNosMallItemListWidget* unknown40;		// 0x0D4
		TNTNosMallItemListWidget* unknown41;		// 0x0D8
		uint32_t unknown42;							// 0x0DC
		char unknown43[28];							// 0x0E0
	};
	static_assert(sizeof(TNTNosMallItemShopWidget) == 0xFC, "TNTNosMallItemShopWidget size isn't 0xFC.");
	static_assert(sizeof(TNTNosMallItemShopWidget) <= 0xFC, "TNTNosMallItemShopWidget size is upper than 0xFC.");
	static_assert(sizeof(TNTNosMallItemShopWidget) >= 0xFC, "TNTNosMallItemShopWidget size is lower than 0xFC.");
#pragma pack(pop)
}