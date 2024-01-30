module;
#include <stdint.h>
export module TNTNewServerSelectWidget2;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewServerSelectWidget2 : public TEWControlWidgetEX
	{
		struct TEWCustomPanelWidget* unknown20;			// 0x068 
		struct TEWLabel* unknown21;						// 0x06C
		struct TEWListView* unknown22;					// 0x070
		struct TEWGraphicButtonWidget* unknown23;		// 0x074
		struct TEWCustomPanelWidget* unknown24;			// 0x078
		uint32_t unknown25;								// 0x07C
		struct TEWControlWidgetEX* serverTrackerWidget;	// 0x080
		char unknown26[100];							// 0x084
		uint32_t unknown27;								// 0x0E8
		struct TEWCustomPanelWidget* unknown28;			// 0x0EC
		struct TEWCustomPanelWidget* unknown29;			// 0x0F0
		struct TEWLabel* unknown30;						// 0x0F4
		struct TEWLabel* unknown31;						// 0x0F8
		struct TEWListView* unknown32;					// 0x0FC
		struct TEWListView* unknown33;					// 0x100
		struct TEWGraphicButtonWidget* unknown34;		// 0x104
		struct TEWGraphicButtonWidget* unknown35;		// 0x108
		struct TEWCustomPanelWidget* unknown36;			// 0x10C
		struct TEWCustomPanelWidget* unknown37;			// 0x110
		uint32_t unknown38;								// 0x114
		uint32_t unknown39;								// 0x118
		struct TEWControlWidgetEX* unknown40;			// 0x11C
		struct TEWButtonWidget* unknown41;				// 0x120
		uint8_t unknown42;								// 0x124
		char unknown43[77];								// 0x125
		uint32_t unknown44;								// 0x172
		uint32_t unknown45;								// 0x176
		uint16_t unknown46;								// 0x17A
		uint8_t unknown47;								// 0x17C
		uint32_t unknown48;								// 0x17D
		uint32_t unknown49;								// 0x181
		uint16_t unknown50;								// 0x185
		uint8_t unknown51;								// 0x187
		uint32_t unknown52;								// 0x188
		uint32_t unknown53;								// 0x18C
		uint16_t unknown54;								// 0x190
		uint8_t unknown55;								// 0x192
		uint16_t unknown56;								// 0x193
		uint16_t unknown57;								// 0x195
		uint32_t unknown58;								// 0x197
		uint32_t unknown60;								// 0x19B
		uint32_t unknown61;								// 0x19F
		char unknown62;									// 0x1A3
		uint32_t unknown63;								// 0x1A4
		uint32_t unknown64;								// 0x1A8
		uint32_t unknown65;								// 0x1AC
		char unknown66[8];								// 0x1B0
		uint32_t unknown67;								// 0x1B8
		uint32_t unknown68;								// 0x1BC
		uint32_t unknown69;								// 0x1C0
		char unknown70[140];							// 0x1C4
		uint8_t unknown71;								// 0x250
		char unknown72[3];								// 0x251
		uint32_t unknown73;								// 0x254
		uint32_t unknown74;								// 0x258
		uint32_t unknown75;								// 0x25C
		int16_t unknown76;								// 0x260
		uint16_t unknown77;								// 0x260
	};
	static_assert(sizeof(TNTNewServerSelectWidget2) == 0x264, "TNTPartySummaryInfoWidget size isn't 0x264.");
	static_assert(sizeof(TNTNewServerSelectWidget2) <= 0x264, "TNTPartySummaryInfoWidget size is upper than 0x264.");
	static_assert(sizeof(TNTNewServerSelectWidget2) >= 0x264, "TNTPartySummaryInfoWidget size is lower than 0x264.");
#pragma pack(pop)
}