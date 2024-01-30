module;
#include <stdint.h>
export module TNTNosMallItemListWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallItemListWidget : public TEWControlWidgetEX
	{
		float unknown20;									// 0x068
		uint32_t unknown21;									// 0x06C
		uint32_t unknown22;									// 0x070
		uint32_t unknown23;									// 0x074
		uint32_t unknown24;									// 0x078
		uint8_t unknown25;									// 0x07C
		uint8_t unknown26;									// 0x07D
		char unknown27[2];									// 0x07E
		struct TEWScrollBar* scrollBar;						// 0x080
		uint32_t unknown28;									// 0x084
		struct TNTNosMallSelectedItemList* unknown29;		// 0x088
		struct TNTNosMallStringList* unknown30;				// 0x08C
		uint32_t unknown31;									// 0x090
		struct TNTNosMallGroupItemSelectWidget* unknown32;	// 0x094
	};
	static_assert(sizeof(TNTNosMallItemListWidget) == 0x98, "TNTNosMallItemListWidget size isn't 0x98.");
	static_assert(sizeof(TNTNosMallItemListWidget) <= 0x98, "TNTNosMallItemListWidget size is upper than 0x98.");
	static_assert(sizeof(TNTNosMallItemListWidget) >= 0x98, "TNTNosMallItemListWidget size is lower than 0x98.");
#pragma pack(pop)
}