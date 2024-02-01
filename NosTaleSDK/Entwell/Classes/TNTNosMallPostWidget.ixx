module;
export module TNTNosMallPostWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallPostWidget : public TEWControlWidgetEX
	{
		struct TEWCustomPanelWidget* unknown20;		// 0x068
		TEWCustomPanelWidget* unknown21;			// 0x06C
		TEWControlWidgetEX* unknown22;				// 0x070
		struct TEWLabel* unknown23;					// 0x074
		TEWLabel* unknown24;						// 0x078
		struct TNTNosMallItemListWidget* unknown25;	// 0x07C
		struct TNTNosMallPostItemList* unknown26;	// 0x080
		TEWCustomPanelWidget* unknown27;			// 0x084
		TEWControlWidgetEX* unknown28;				// 0x088
		TEWLabel* unknown29;						// 0x08C
		TNTNosMallItemListWidget* unknown30;		// 0x090
		TNTNosMallPostItemList* unknown31;			// 0x094
		TEWCustomPanelWidget* unknown32;			// 0x098
		TEWControlWidgetEX* unknown33;				// 0x09C
		TEWLabel* unknown34;						// 0x0A0
		TEWLabel* unknown35;						// 0x0A4
		struct TEWGraphicButtonWidget* unknown36;	// 0x0A8
		TNTNosMallItemListWidget* unknown37;		// 0x0AC
		struct TNTNosMallSlipItemList* unknown38;	// 0x0B0
		TEWCustomPanelWidget* unknown39;			// 0x0B4
		TEWControlWidgetEX* unknown40;				// 0x0B8
		TEWLabel* unknown41;						// 0x0BC
		TEWLabel* unknown42;						// 0x0C0
		TNTNosMallItemListWidget* unknown43;		// 0x0C4
		TNTNosMallSlipItemList* unknown44;			// 0x0C8
	};
	static_assert(sizeof(TNTNosMallPostWidget) == 0xCC, "TNTNosMallPostWidget size isn't 0xCC.");
	static_assert(sizeof(TNTNosMallPostWidget) <= 0xCC, "TNTNosMallPostWidget size is upper than 0xCC.");
	static_assert(sizeof(TNTNosMallPostWidget) >= 0xCC, "TNTNosMallPostWidget size is lower than 0xCC.");
#pragma pack(pop)
}