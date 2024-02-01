module;
export module TNTTatooUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTatooUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TEWLabel* title;						// 0x0C0
		struct TEWGraphicButtonWidget* helpButton;	// 0x0C4
		TEWGraphicButtonWidget* closeButton;		// 0x0C8
		struct TNTIconWidget* iconSelectedTattoo;	// 0x0CC
		TEWLabel* nameUpgradeSelectedTattoo;		// 0x0D0
		TEWLabel* successRate;						// 0x0D4
		TEWLabel* majorFailRate;					// 0x0D8
		TEWLabel* failRate;							// 0x0DC
		struct TEWControlWidgetEX* plusIcon;		// 0x0E0
		TNTIconWidget* firstIcon;					// 0x0E4
		TNTIconWidget* secondIcon;					// 0x0E8
		TNTIconWidget* thirdIcon;					// 0x0EC
		TNTIconWidget* fourthIcon;					// 0x0F0
		TNTIconWidget* fifthIcon;					// 0x0F4
		TNTIconWidget* sixthIcon;					// 0x0F8
		struct TNTItemList* itemList;				// 0x0FC
		TEWLabel* firstAsk;							// 0x100
		TEWLabel* secondAsk;						// 0x104
		TEWLabel* thirdAsk;							// 0x108
		TEWLabel* fourthAsk;						// 0x10C
		TEWLabel* fifthAsk;							// 0x110
		TEWLabel* sixthAsk;							// 0x114
		TEWLabel* firstQuantity;					// 0x118
		TEWLabel* secondQuantity;					// 0x11C
		TEWLabel* thirdQuantity;					// 0x120
		TEWLabel* fourthQuantity;					// 0x124
		TEWLabel* fifthQuantity;					// 0x128
		TEWLabel* sixthQuantity;					// 0x12C
		TEWGraphicButtonWidget* upgradeButton;		// 0x130
		TEWLabel* upgradeButtonText;				// 0x134
		TEWGraphicButtonWidget* removeTatooButton;	// 0x138
		TEWLabel* removeTatooButtonText;			// 0x13C
		char unknown39;								// 0x140
		bool isActionBlocked;						// 0x141
		bool isActionBlocked2;						// 0x142
		char unknown40;								// 0x143
		char unknown41[4];							// 0x144
		char unknown42[28];							// 0x148
	};
	static_assert(sizeof(TNTTatooUpgradeWidget) == 0x164, "TNTTatooUpgradeWidget size isn't 0x164.");
	static_assert(sizeof(TNTTatooUpgradeWidget) <= 0x164, "TNTTatooUpgradeWidget size is upper than 0x164.");
	static_assert(sizeof(TNTTatooUpgradeWidget) >= 0x164, "TNTTatooUpgradeWidget size is lower than 0x164.");
#pragma pack(pop)
}