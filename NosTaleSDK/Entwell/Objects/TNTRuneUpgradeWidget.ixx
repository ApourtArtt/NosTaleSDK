module;
#include <stdint.h>
export module TNTRuneUpgradeWidget;
import TEWCustomFormWidget;
import TEWLabel;
import TNTItemList;
import TEWGraphicButtonWidget;
import TNTIconWidget;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTRuneUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown22[4];							//0xBC
		TEWLabel* title;							//0xC0
		TEWGraphicButtonWidget* helpButton;			//0xC4
		TEWGraphicButtonWidget* closeButton;		//0xC8
		TEWCustomPanelWidget* unknownPanel;			//0xCC
		TNTIconWidget* iconSelectedItem;			//0xD0
		TEWLabel* nameUpgradeSelectedItem;			//0xD4
		TEWLabel* successRate;						//0xD8
		TEWLabel* damageRate;						//0xDC
		TEWLabel* failRate;							//0xE0
		TEWControlWidgetEX* plusIcon;				//0xE4
		TNTIconWidget* firstIcon;					//0xE8
		TNTIconWidget* secondIcon;					//0xEC
		TNTIconWidget* thirdIcon;					//0xF0
		TNTIconWidget* fourthIcon;					//0xF4
		TNTIconWidget* fifthIcon;					//0xF8
		TNTIconWidget* sixthIcon;					//0xFC
		TNTIconWidget* firstUselessIcon;			//0x100
		TNTIconWidget* secondUselessIcon;			//0x104
		TEWLabel* firstAsk;							//0x108
		TEWLabel* secondAsk;						//0x10C
		TEWLabel* thirdAsk;							//0x110
		TEWLabel* fourthAsk;						//0x114
		TEWLabel* fifthAsk;							//0x118
		TEWLabel* sixthAsk;							//0x11C
		TEWLabel* firstUselessAsk;					//0x120
		TEWLabel* secondUselessAsk;					//0x124
		TEWLabel* firstQuantity;					//0x128
		TEWLabel* secondQuantity;					//0x12C
		TEWLabel* thirdQuantity;					//0x130
		TEWLabel* fourthQuantity;					//0x134
		TEWLabel* fifthQuantity;					//0x138
		TEWLabel* sixthQuantity;					//0x13C
		TEWLabel* firstUselessQuantity;				//0x140
		TEWLabel* secondUselessQuantity;			//0x144
		TNTItemList* itemList;						//0x148
		TEWGraphicButtonWidget* upgradeButton;		//0x14C
		TEWLabel* upgradeButtonText;				//0x150
		TEWGraphicButtonWidget* removeRunicButton;	//0x154
		TEWLabel* removeRunicButtonText;			//0x158
		char unknown23[4];							//0x15C
		bool isEnoughtIngredients;					//0x160
		bool isActionBlocked;						//0x161
		bool isActionBlocked2;						//0x162
		bool isRemoveLastClicked;					//0x163
		int16_t goldRequired;						//0x164
		char unknown25[26];							//0x166
		uint32_t goldAmount;						//0x180
		bool unknown26;								//0x184
		char unknown27[7];							//0x185
	};
	static_assert(sizeof(TNTRuneUpgradeWidget) == 0x18C, "TNTRuneUpgradeWidget does not have a size of 0x18C.");
#pragma pack(pop)
}