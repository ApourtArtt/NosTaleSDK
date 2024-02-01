module;
#include <stdint.h>
export module TNTSPCardUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpCardUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown38[4];						// 0x0BC
		struct TEWLabel* title;					// 0x0C0
		struct TEWGraphicButtonWidget* helpBtn;	// 0x0C4
		TEWGraphicButtonWidget* closeBtn;		// 0x0C8
		TEWCustomPanelWidget* bgPanel;			// 0x0CC
		struct TNTIconWidget* spIcon;			// 0x0D0
		TEWLabel* cardLabel;					// 0x0D4
		TEWLabel* successLabel;					// 0x0D8
		TEWLabel* destroyLabel;					// 0x0DC
		TEWLabel* failLabel;					// 0x0E0
		struct TEWControlWidgetEX* plusIcon;	// 0x0E4
		TNTIconWidget* goldIcon;				// 0x0E8
		TNTIconWidget* reqIcon[3];				// 0x0EC
		struct TNTItemList* itemList;			// 0x0F0
		TEWLabel* goldDemandLabel;				// 0x0F4
		TEWLabel* reqDemandLabel[3];			// 0x100
		TEWLabel* goldQuantityLabel;			// 0x10C
		TEWLabel* reqQuantityLabel[3];			// 0x110
		TEWGraphicButtonWidget* upgradeBtn;		// 0x11C
		TEWLabel* upgradeBtnLabel;				// 0x120
		int8_t unknown39;						// 0x124
		int8_t unknown40;						// 0x125
		int16_t unknown41;						// 0x126
		uint32_t goldQuantity;					// 0x128
		uint32_t reqQuantity[3];				// 0x12C
		uint32_t thirdReqIconId;				// 0x138
		uint32_t currentGoldAmount;				// 0x13C
	};
	static_assert(sizeof(TNTSpCardUpgradeWidget) == 0x140, "TNTSpCardUpgradeWidget size isn't 0x140.");
	static_assert(sizeof(TNTSpCardUpgradeWidget) <= 0x140, "TNTSpCardUpgradeWidget size is upper than 0x140.");
	static_assert(sizeof(TNTSpCardUpgradeWidget) >= 0x140, "TNTSpCardUpgradeWidget size is lower than 0x140.");
#pragma pack(pop)
}