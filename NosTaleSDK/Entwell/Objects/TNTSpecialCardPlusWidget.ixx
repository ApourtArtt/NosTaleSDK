module;
#include <stdint.h>
export module TNTSpecialCardPlusWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialCardPlusWidget : public TEWCustomFormWidget
	{
		char unknown21[4];						//0xBC
		struct TEWLabel* title;						//0xC0
		struct TEWGraphicButtonWidget* helpBtn;		//0xC4
		struct TEWGraphicButtonWidget* closeBtn;		//0xC8
		struct TEWCustomPanelWidget* bgPanel;			//0xCC
		struct TNTIconWidget* spIcon;					//0xD0
		struct TEWLabel* cardLabel;					//0xD4
		struct TEWControlWidgetEX* plusIcon;			//0xD8
		struct TNTIconWidget* goldIcon;				//0xDC
		struct TNTIconWidget* jewelIcon;				//0xE0
		struct TNTItemList* itemList;					//0xE4
		struct TEWLabel* goldDemandLabel;				//0xE8
		struct TEWLabel* jewelDemandLabel;				//0xEC
		struct TEWLabel* goldQuantityLabel;			//0xF0
		struct TEWLabel* jewelQuantityLabel;			//0xF4
		struct TEWGraphicButtonWidget* upgradeBtn;		//0xF8
		struct TEWLabel* upgradeBtnLabel;				//0xFC
		char unknown22[4];						//0x100
		uint32_t goldQuantity;					//0x104
		uint32_t jewelQuantity;					//0x108
		uint32_t jewelIconId;					//0x10C
		uint32_t currentGoldAmount;				//0x110
	};
	static_assert(sizeof(TNTSpecialCardPlusWidget) == 0x114, "TNTSpecialCardPlusWidget does not have a size of 0x114.");
#pragma pack(pop)
}