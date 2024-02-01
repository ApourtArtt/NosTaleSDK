module;
#include <stdint.h>
export module TNTItemZillerWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemZillerWidget : public TEWCustomFormWidget
	{
		char unknown38[4];						// 0x0BC
		struct TEWLabels* allLabels;			// 0x0C0
		struct TNTIconWidget* eqIcon;			// 0x0C4
		TNTIconWidget* goldIcon;				// 0x0C8
		TNTIconWidget* cellaIcon;				// 0x0CC
		char unknown39[8];						// 0x0D0
		void* eqItem;							// 0x0D8
		char unknown40[32];						// 0x0DC
		void* unknown41;						// 0x0FC
		char unknown42[24];						// 0x100
		void* goldItem;							// 0x118
		uint16_t goldItemId;					// 0x11C
		char unknown43[58];						// 0x11E
		void* cellaItem;						// 0x158
		uint16_t cellaItemId;					// 0x15C
		char unknown44[50];						// 0x15E
		struct TEWGraphicButtonWidget* betBtn;	// 0x190
		uint32_t currentGoldAmount;				// 0x194
		char unknown45[4];						// 0x198
	};
	static_assert(sizeof(TNTItemZillerWidget) == 0x19C, "TNTItemZillerWidget size isn't 0x19C.");
	static_assert(sizeof(TNTItemZillerWidget) <= 0x19C, "TNTItemZillerWidget size is upper than 0x19C.");
	static_assert(sizeof(TNTItemZillerWidget) >= 0x19C, "TNTItemZillerWidget size is lower than 0x19C.");
#pragma pack(pop)
}