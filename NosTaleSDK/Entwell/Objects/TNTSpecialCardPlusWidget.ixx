module;
#include <stdint.h>
export module TNTSpecialCardPlusWidget;
import TEWCustomFormWidget;
import TEWLabel;
import TEWGraphicButtonWidget;
import TNTIconWidget;
import TEWControlWidgetEX;
import TNTItemList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialCardPlusWidget : public TEWCustomFormWidget
	{
		char unknown21[4];						//0xBC
		TEWLabel* title;						//0xC0
		TEWGraphicButtonWidget* helpBtn;		//0xC4
		TEWGraphicButtonWidget* closeBtn;		//0xC8
		TEWCustomPanelWidget* bgPanel;			//0xCC
		TNTIconWidget* spIcon;					//0xD0
		TEWLabel* cardLabel;					//0xD4
		TEWControlWidgetEX* plusIcon;			//0xD8
		TNTIconWidget* goldIcon;				//0xDC
		TNTIconWidget* jewelIcon;				//0xE0
		TNTItemList* itemList;					//0xE4
		TEWLabel* goldDemandLabel;				//0xE8
		TEWLabel* jewelDemandLabel;				//0xEC
		TEWLabel* goldQuantityLabel;			//0xF0
		TEWLabel* jewelQuantityLabel;			//0xF4
		TEWGraphicButtonWidget* upgradeBtn;		//0xF8
		TEWLabel* upgradeBtnLabel;				//0xFC
		char unknown22[4];						//0x100
		uint32_t goldQuantity;					//0x104
		uint32_t jewelQuantity;					//0x108
		uint32_t jewelIconId;					//0x10C
		uint32_t currentGoldAmount;				//0x110
	};
	static_assert(sizeof(TNTSpecialCardPlusWidget) == 0x114, "TNTSpecialCardPlusWidget does not have a size of 0x114.");
#pragma pack(pop)
}