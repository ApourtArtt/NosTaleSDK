module;
#include <stdint.h>
export module TNTTatooUpgradeWidget;
import TEWCustomFormWidget;
import TEWLabel;
import TEWGraphicButtonWidget;
import TNTIconWidget;
import TNTItemList;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTatooUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown22[4];							//0xBC
		TEWLabel* title;							//0xC0
		TEWGraphicButtonWidget* helpButton;			//0xC4
		TEWGraphicButtonWidget* closeButton;		//0xC8
		TNTIconWidget* iconSelectedTattoo;			//0xCC
		TEWLabel* nameUpgradeSelectedTattoo;		//0xD0
		TEWLabel* successRate;						//0xD4
		TEWLabel* majorFailRate;					//0xD8
		TEWLabel* failRate;							//0xDC
		TEWControlWidgetEX* plusIcon;				//0xE0
		TNTIconWidget* firstIcon;					//0xE4
		TNTIconWidget* secondIcon;					//0xE8
		TNTIconWidget* thirdIcon;					//0xEC
		TNTIconWidget* fourthIcon;					//0xF0
		TNTIconWidget* fifthIcon;					//0xF4
		TNTIconWidget* sixthIcon;					//0xF8
		TNTItemList* itemList;						//0xFC
		TEWLabel* firstAsk;							//0x100
		TEWLabel* secondAsk;						//0x104
		TEWLabel* thirdAsk;							//0x108
		TEWLabel* fourthAsk;						//0x10C
		TEWLabel* fifthAsk;							//0x110
		TEWLabel* sixthAsk;							//0x114
		TEWLabel* firstQuantity;					//0x118
		TEWLabel* secondQuantity;					//0x11C
		TEWLabel* thirdQuantity;					//0x120
		TEWLabel* fourthQuantity;					//0x124
		TEWLabel* fifthQuantity;					//0x128
		TEWLabel* sixthQuantity;					//0x12C
		TEWGraphicButtonWidget* upgradeButton;		//0x130
		TEWLabel* upgradeButtonText;				//0x134
		TEWGraphicButtonWidget* removeTatooButton;	//0x138
		TEWLabel* removeTatooButtonText;			//0x13C
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