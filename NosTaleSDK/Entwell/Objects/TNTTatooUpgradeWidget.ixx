module;
export module TNTTatooUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTatooUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown22[4];							//0xBC
		struct TEWLabel* title;							//0xC0
		struct TEWGraphicButtonWidget* helpButton;			//0xC4
		struct TEWGraphicButtonWidget* closeButton;		//0xC8
		struct TNTIconWidget* iconSelectedTattoo;			//0xCC
		struct TEWLabel* nameUpgradeSelectedTattoo;		//0xD0
		struct TEWLabel* successRate;						//0xD4
		struct TEWLabel* majorFailRate;					//0xD8
		struct TEWLabel* failRate;							//0xDC
		struct TEWControlWidgetEX* plusIcon;				//0xE0
		struct TNTIconWidget* firstIcon;					//0xE4
		struct TNTIconWidget* secondIcon;					//0xE8
		struct TNTIconWidget* thirdIcon;					//0xEC
		struct TNTIconWidget* fourthIcon;					//0xF0
		struct TNTIconWidget* fifthIcon;					//0xF4
		struct TNTIconWidget* sixthIcon;					//0xF8
		struct TNTItemList* itemList;						//0xFC
		struct TEWLabel* firstAsk;							//0x100
		struct TEWLabel* secondAsk;						//0x104
		struct TEWLabel* thirdAsk;							//0x108
		struct TEWLabel* fourthAsk;						//0x10C
		struct TEWLabel* fifthAsk;							//0x110
		struct TEWLabel* sixthAsk;							//0x114
		struct TEWLabel* firstQuantity;					//0x118
		struct TEWLabel* secondQuantity;					//0x11C
		struct TEWLabel* thirdQuantity;					//0x120
		struct TEWLabel* fourthQuantity;					//0x124
		struct TEWLabel* fifthQuantity;					//0x128
		struct TEWLabel* sixthQuantity;					//0x12C
		struct TEWGraphicButtonWidget* upgradeButton;		//0x130
		struct TEWLabel* upgradeButtonText;				//0x134
		struct TEWGraphicButtonWidget* removeTatooButton;	//0x138
		struct TEWLabel* removeTatooButtonText;			//0x13C
		char unknown23;								// 0x140
		bool isActionBlocked;						// 0x141
		bool isActionBlocked2;						// 0x142
		char unknown24;								//0x143
		char unknown25[4];							//0x144
		char unknown26[28];							//0x148
	};
	static_assert(sizeof(TNTTatooUpgradeWidget) == 0x164, "TNTTatooUpgradeWidget does not have a size of 0x164.");
#pragma pack(pop)
}