module;
#include <stdint.h>
export module TNTSPCardUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSPCardUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TEWLabel* title;						// 0x0C0
		struct TEWGraphicButtonWidget* helpBtn;		// 0x0C4
		struct TEWGraphicButtonWidget* closeBtn;	// 0x0C8
		struct TEWCustomPanelWidget* bgPanel;		// 0x0CC
		struct TNTIconWidget* spIcon;				// 0x0D0
		struct TEWLabel* cardLabel;					// 0x0D4
		struct TEWLabel* successLabel;				// 0x0D8
		struct TEWLabel* destroyLabel;				// 0x0DC
		struct TEWLabel* failLabel;					// 0x0E0
		struct TEWControlWidgetEX* plusIcon;		// 0x0E4
		struct TNTIconWidget* goldIcon;				// 0x0E8
		struct TNTIconWidget* reqIcon[3];			// 0x0EC
		struct TNTItemList* itemList;				// 0x0F0
		struct TEWLabel* goldDemandLabel;			// 0x0F4
		struct TEWLabel* reqDemandLabel[3];			// 0x100
		struct TEWLabel* goldQuantityLabel;			// 0x10C
		struct TEWLabel* reqQuantityLabel[3];		// 0x110
		struct TEWGraphicButtonWidget* upgradeBtn;	// 0x11C
		struct TEWLabel* upgradeBtnLabel;			// 0x120
		int8_t unknown39;							// 0x124
		int8_t unknown40;							// 0x125
		int16_t unknown41;							// 0x126
		uint32_t goldQuantity;						// 0x128
		uint32_t reqQuantity[3];					// 0x12C
		uint32_t thirdReqIconId;					// 0x138
		uint32_t currentGoldAmount;					// 0x13C
	};
	static_assert(sizeof(TNTSPCardUpgradeWidget) == 0x140, "TNTSPCardUpgradeWidget size isn't 0x140.");
	static_assert(sizeof(TNTSPCardUpgradeWidget) <= 0x140, "TNTSPCardUpgradeWidget size is upper than 0x140.");
	static_assert(sizeof(TNTSPCardUpgradeWidget) >= 0x140, "TNTSPCardUpgradeWidget size is lower than 0x140.");
#pragma pack(pop)
}