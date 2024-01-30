module;
#include <stdint.h>
export module TNTNosMallPostWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallPostWidget : public TEWControlWidgetEX
	{
		struct TEWCustomPanelWidget* unknown20;		// 0x068
		struct TEWCustomPanelWidget* unknown21;		// 0x06C
		struct TEWControlWidgetEX* unknown22;		// 0x070
		struct TEWLabel* unknown23;					// 0x074
		struct TEWLabel* unknown24;					// 0x078
		struct TNTNosMallItemListWidget* unknown25;	// 0x07C
		struct TNTNosMallPostItemList* unknown26;	// 0x080
		struct TEWCustomPanelWidget* unknown27;		// 0x084
		struct TEWControlWidgetEX* unknown28;		// 0x088
		struct TEWLabel* unknown29;					// 0x08C
		struct TNTNosMallItemListWidget* unknown30;	// 0x090
		struct TNTNosMallPostItemList* unknown31;	// 0x094
		struct TEWCustomPanelWidget* unknown32;		// 0x098
		struct TEWControlWidgetEX* unknown33;		// 0x09C
		struct TEWLabel* unknown34;					// 0x0A0
		struct TEWLabel* unknown35;					// 0x0A4
		struct TEWGraphicButtonWidget* unknown36;	// 0x0A8
		struct TNTNosMallItemListWidget* unknown37;	// 0x0AC
		struct TNTNosMallSlipItemList* unknown38;	// 0x0B0
		struct TEWCustomPanelWidget* unknown39;		// 0x0B4
		struct TEWControlWidgetEX* unknown40;		// 0x0B8
		struct TEWLabel* unknown41;					// 0x0BC
		struct TEWLabel* unknown42;					// 0x0C0
		struct TNTNosMallItemListWidget* unknown43;	// 0x0C4
		struct TNTNosMallSlipItemList* unknown44;	// 0x0C8
	};
	static_assert(sizeof(TNTNosMallPostWidget) == 0xCC, "TNTNosMallPostWidget size isn't 0xCC.");
	static_assert(sizeof(TNTNosMallPostWidget) <= 0xCC, "TNTNosMallPostWidget size is upper than 0xCC.");
	static_assert(sizeof(TNTNosMallPostWidget) >= 0xCC, "TNTNosMallPostWidget size is lower than 0xCC.");
#pragma pack(pop)
}