module;
#include <stdint.h>
export module TNTCostumeInventoryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCostumeInventoryInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		struct TEWCustomPanelWidget* unknown39;				// 0x0C0
		struct TEWScrollBar* scrollBar;						// 0x0C4
		struct TNTIconWidget* icons[60];					// 0x0C8
		struct TNTItemList* items;							// 0x1B8
		struct TNTCharacterInventoryInfoWidget* inventory;	// 0x1BC
		uint32_t unknown41;									// 0x1C0
		char unknown42[4];									// 0x1C4
		struct TEWRollOverButtonWidget* unknown43;			// 0x1C8
		struct TEWCustomPanelWidget* unknown44;				// 0x1CC
		struct TEWLabel* unknown45;							// 0x1D0
	};
	static_assert(sizeof(TNTCostumeInventoryInfoWidget) == 0x1D4, "TNTCostumeInventoryInfoWidget size isn't 0x1D4.");
	static_assert(sizeof(TNTCostumeInventoryInfoWidget) <= 0x1D4, "TNTCostumeInventoryInfoWidget size is upper than 0x1D4.");
	static_assert(sizeof(TNTCostumeInventoryInfoWidget) >= 0x1D4, "TNTCostumeInventoryInfoWidget size is lower than 0x1D4.");
#pragma pack(pop)
}