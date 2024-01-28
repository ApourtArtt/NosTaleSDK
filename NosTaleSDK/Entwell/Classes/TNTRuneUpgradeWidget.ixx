module;
#include <stdint.h>
export module TNTRuneUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTRuneUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown22[4];							//0xBC
		struct TEWLabel* title;							//0xC0
		struct TEWGraphicButtonWidget* helpButton;			//0xC4
		struct TEWGraphicButtonWidget* closeButton;		//0xC8
		struct TEWCustomPanelWidget* unknownPanel;			//0xCC
		struct TNTIconWidget* iconSelectedItem;			//0xD0
		struct TEWLabel* nameUpgradeSelectedItem;			//0xD4
		struct TEWLabel* successRate;						//0xD8
		struct TEWLabel* damageRate;						//0xDC
		struct TEWLabel* failRate;							//0xE0
		struct TEWControlWidgetEX* plusIcon;				//0xE4
		struct TNTIconWidget* firstIcon;					//0xE8
		struct TNTIconWidget* secondIcon;					//0xEC
		struct TNTIconWidget* thirdIcon;					//0xF0
		struct TNTIconWidget* fourthIcon;					//0xF4
		struct TNTIconWidget* fifthIcon;					//0xF8
		struct TNTIconWidget* sixthIcon;					//0xFC
		struct TNTIconWidget* firstUselessIcon;			//0x100
		struct TNTIconWidget* secondUselessIcon;			//0x104
		struct TEWLabel* firstAsk;							//0x108
		struct TEWLabel* secondAsk;						//0x10C
		struct TEWLabel* thirdAsk;							//0x110
		struct TEWLabel* fourthAsk;						//0x114
		struct TEWLabel* fifthAsk;							//0x118
		struct TEWLabel* sixthAsk;							//0x11C
		struct TEWLabel* firstUselessAsk;					//0x120
		struct TEWLabel* secondUselessAsk;					//0x124
		struct TEWLabel* firstQuantity;					//0x128
		struct TEWLabel* secondQuantity;					//0x12C
		struct TEWLabel* thirdQuantity;					//0x130
		struct TEWLabel* fourthQuantity;					//0x134
		struct TEWLabel* fifthQuantity;					//0x138
		struct TEWLabel* sixthQuantity;					//0x13C
		struct TEWLabel* firstUselessQuantity;				//0x140
		struct TEWLabel* secondUselessQuantity;			//0x144
		struct TNTItemList* itemList;						//0x148
		struct TEWGraphicButtonWidget* upgradeButton;		//0x14C
		struct TEWLabel* upgradeButtonText;				//0x150
		struct TEWGraphicButtonWidget* removeRunicButton;	//0x154
		struct TEWLabel* removeRunicButtonText;			//0x158
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