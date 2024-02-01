module;
#include <stdint.h>
export module TNTCardInventoryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCardInventoryInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		TEWCustomPanelWidget* unknown39;					// 0x0C0
		struct TEWScrollBar* scrollBar;						// 0x0C4
		struct TNTIconWidget* icons[46];					// 0x0C8
		struct TNTItemList* items;							// 0x180
		uint32_t unknown41;									// 0x184
		struct TNTCharacterInventoryInfoWidget* inventory;	// 0x188
		struct TEWRollOverButtonWidget* unknown43;			// 0x18C
		TEWCustomPanelWidget* unknown44;					// 0x190
		struct TEWLabel* unknown45;							// 0x194
	};
	static_assert(sizeof(TNTCardInventoryInfoWidget) == 0x198, "TNTCardInventoryInfoWidget size isn't 0x198.");
	static_assert(sizeof(TNTCardInventoryInfoWidget) <= 0x198, "TNTCardInventoryInfoWidget size is upper than 0x198.");
	static_assert(sizeof(TNTCardInventoryInfoWidget) >= 0x198, "TNTCardInventoryInfoWidget size is lower than 0x198.");
#pragma pack(pop)
}