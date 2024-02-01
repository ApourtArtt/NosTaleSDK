module;
#include <stdint.h>
export module TNTItemUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown38[4];								// 0x0BC
		struct TEWLabels* allLabels;					// 0x0C0
		struct TNTIconWidget* eqIcon;					// 0x0C4
		TNTIconWidget* requirementIcons[3];				// 0x0C8
		char unknown39[8];								// 0x0D4
		int32_t unknown40;								// 0x0DC
		void* eqItem;									// 0x0E0
		uint16_t eqItemId;								// 0x0E4
		char unknown41[58];								// 0x0E6
		void* firstReqItem;								// 0x120
		uint16_t firstReqItemId;						// 0x124
		char unknown42[58];								// 0x126
		void* secondReqItem;							// 0x160
		uint16_t secondReqItemId;						// 0x164
		char unknown43[58];								// 0x166
		void* thirdReqItem;								// 0x1A0
		uint16_t thirdReqItemId;						// 0x1A4
		char unknown44[50];								// 0x1A6
		struct TEWGraphicButtonWidget* reinforceBtn;	// 0x1D8
		char unknown45[4];								// 0x1DC
		char unknown46[4];								// 0x1E0
	};
	static_assert(sizeof(TNTItemUpgradeWidget) == 0x1E4, "TNTItemUpgradeWidget size isn't 0x1E4.");
	static_assert(sizeof(TNTItemUpgradeWidget) <= 0x1E4, "TNTItemUpgradeWidget size is upper than 0x1E4.");
	static_assert(sizeof(TNTItemUpgradeWidget) >= 0x1E4, "TNTItemUpgradeWidget size is lower than 0x1E4.");
#pragma pack(pop)
}