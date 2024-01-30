module;
export module TNTTatooUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTatooUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		struct TEWLabel* title;								// 0x0C0
		struct TEWGraphicButtonWidget* helpButton;			// 0x0C4
		struct TEWGraphicButtonWidget* closeButton;			// 0x0C8
		struct TNTIconWidget* iconSelectedTattoo;			// 0x0CC
		struct TEWLabel* nameUpgradeSelectedTattoo;			// 0x0D0
		struct TEWLabel* successRate;						// 0x0D4
		struct TEWLabel* majorFailRate;						// 0x0D8
		struct TEWLabel* failRate;							// 0x0DC
		struct TEWControlWidgetEX* plusIcon;				// 0x0E0
		struct TNTIconWidget* firstIcon;					// 0x0E4
		struct TNTIconWidget* secondIcon;					// 0x0E8
		struct TNTIconWidget* thirdIcon;					// 0x0EC
		struct TNTIconWidget* fourthIcon;					// 0x0F0
		struct TNTIconWidget* fifthIcon;					// 0x0F4
		struct TNTIconWidget* sixthIcon;					// 0x0F8
		struct TNTItemList* itemList;						// 0x0FC
		struct TEWLabel* firstAsk;							// 0x100
		struct TEWLabel* secondAsk;							// 0x104
		struct TEWLabel* thirdAsk;							// 0x108
		struct TEWLabel* fourthAsk;							// 0x10C
		struct TEWLabel* fifthAsk;							// 0x110
		struct TEWLabel* sixthAsk;							// 0x114
		struct TEWLabel* firstQuantity;						// 0x118
		struct TEWLabel* secondQuantity;					// 0x11C
		struct TEWLabel* thirdQuantity;						// 0x120
		struct TEWLabel* fourthQuantity;					// 0x124
		struct TEWLabel* fifthQuantity;						// 0x128
		struct TEWLabel* sixthQuantity;						// 0x12C
		struct TEWGraphicButtonWidget* upgradeButton;		// 0x130
		struct TEWLabel* upgradeButtonText;					// 0x134
		struct TEWGraphicButtonWidget* removeTatooButton;	// 0x138
		struct TEWLabel* removeTatooButtonText;				// 0x13C
		char unknown39;										// 0x140
		bool isActionBlocked;								// 0x141
		bool isActionBlocked2;								// 0x142
		char unknown40;										// 0x143
		char unknown41[4];									// 0x144
		char unknown42[28];									// 0x148
	};
	static_assert(sizeof(TNTTatooUpgradeWidget) == 0x164, "TNTTatooUpgradeWidget size isn't 0x164.");
	static_assert(sizeof(TNTTatooUpgradeWidget) <= 0x164, "TNTTatooUpgradeWidget size is upper than 0x164.");
	static_assert(sizeof(TNTTatooUpgradeWidget) >= 0x164, "TNTTatooUpgradeWidget size is lower than 0x164.");
#pragma pack(pop)
}