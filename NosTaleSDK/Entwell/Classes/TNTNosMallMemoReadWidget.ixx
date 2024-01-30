module;
#include <stdint.h>
export module TNTNosMallMemoReadWidget;
import TEWCustomFormWidget;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallMemoReadWidget : public TEWCustomFormWidget
	{
		char unknown38[4];						// 0x0BC
		uint32_t unknown39;						// 0x0C0
		struct TEWTextOutLabel* unknown40;		// 0x0C4
		struct TEWControlWidgetEX* unknown41;	// 0x0C8
		struct TNTIconViewer* unknown42;		// 0x0CC
		struct TEWLabels* unknown43;			// 0x0D0
		struct TEWStringListView* unknown44;	// 0x0D4
		char unknown45[8];						// 0x0D8
		uint32_t unknown46;						// 0x0E0
	};
	static_assert(sizeof(TNTNosMallMemoReadWidget) == 0xE4, "TNTNosMallMemoReadWidget size isn't 0xE4.");
	static_assert(sizeof(TNTNosMallMemoReadWidget) <= 0xE4, "TNTNosMallMemoReadWidget size is upper than 0xE4.");
	static_assert(sizeof(TNTNosMallMemoReadWidget) >= 0xE4, "TNTNosMallMemoReadWidget size is lower than 0xE4.");
#pragma pack(pop)
}