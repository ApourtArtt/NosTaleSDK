module;
#include <stdint.h>
export module TNTSpecialCardPlusWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialCardPlusWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TEWLabel* title;						// 0x0C0
		struct TEWGraphicButtonWidget* helpBtn;		// 0x0C4
		struct TEWGraphicButtonWidget* closeBtn;	// 0x0C8
		struct TEWCustomPanelWidget* bgPanel;		// 0x0CC
		struct TNTIconWidget* spIcon;				// 0x0D0
		struct TEWLabel* cardLabel;					// 0x0D4
		struct TEWControlWidgetEX* plusIcon;		// 0x0D8
		struct TNTIconWidget* goldIcon;				// 0x0DC
		struct TNTIconWidget* jewelIcon;			// 0x0E0
		struct TNTItemList* itemList;				// 0x0E4
		struct TEWLabel* goldDemandLabel;			// 0x0E8
		struct TEWLabel* jewelDemandLabel;			// 0x0EC
		struct TEWLabel* goldQuantityLabel;			// 0x0F0
		struct TEWLabel* jewelQuantityLabel;		// 0x0F4
		struct TEWGraphicButtonWidget* upgradeBtn;	// 0x0F8
		struct TEWLabel* upgradeBtnLabel;			// 0x0FC
		char unknown39[4];							// 0x100
		uint32_t goldQuantity;						// 0x104
		uint32_t jewelQuantity;						// 0x108
		uint32_t jewelIconId;						// 0x10C
		uint32_t currentGoldAmount;					// 0x110
	};
	static_assert(sizeof(TNTSpecialCardPlusWidget) == 0x114, "TNTSpecialCardPlusWidget size isn't 0x114.");
	static_assert(sizeof(TNTSpecialCardPlusWidget) <= 0x114, "TNTSpecialCardPlusWidget size is upper than 0x114.");
	static_assert(sizeof(TNTSpecialCardPlusWidget) >= 0x114, "TNTSpecialCardPlusWidget size is lower than 0x114.");
#pragma pack(pop)
}