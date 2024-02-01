module;
#include <stdint.h>
export module TNTIndividualShop;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIndividualShop : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		uint8_t unknown39;							// 0x0C0
		uint8_t unknown40;							// 0x0C1
		int16_t unknown41;							// 0x0C2
		struct TEWControlWidgetEx* unknown42;		// 0x0C4
		struct TEWStringListView* unknown43;		// 0x0C8
		struct TEWScrollBar* unknown44;				// 0x0CC
		uint8_t unknown45;							// 0x0D0
		char unknown46[3];							// 0x0D1
		struct TEWGraphicButtonWidget* unknown47;	// 0x0D4
		struct TEWEditWidget* unknown48;			// 0x0D8
		struct TEWLabel* unknown49;					// 0x0DC
		uint32_t unknown50;							// 0x0E0
		uint8_t unknown51;							// 0x0E4
		char unknown52[83];							// 0x0E5
		TEWCustomPanelWidget* unknown53;			// 0x138
		char unknown54[80];							// 0x13C
	};
	static_assert(sizeof(TNTIndividualShop) == 0x18C, "TNTIndividualShop size isn't 0x18C.");
	static_assert(sizeof(TNTIndividualShop) <= 0x18C, "TNTIndividualShop size is upper than 0x18C.");
	static_assert(sizeof(TNTIndividualShop) >= 0x18C, "TNTIndividualShop size is lower than 0x18C.");
#pragma pack(pop)
}