module;
#include <stdint.h>
export module TNTSPCardUpgradeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSPCardUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown21[4];						//0xBC
		struct TEWLabel* title;						//0xC0
		struct TEWGraphicButtonWidget* helpBtn;		//0xC4
		struct TEWGraphicButtonWidget* closeBtn;		//0xC8
		struct TEWCustomPanelWidget* bgPanel;			//0xCC
		struct TNTIconWidget* spIcon;					//0xD0
		struct TEWLabel* cardLabel;					//0xD4
		struct TEWLabel* successLabel;					//0xD8
		struct TEWLabel* destroyLabel;					//0xDC
		struct TEWLabel* failLabel;					//0xE0
		struct TEWControlWidgetEX* plusIcon;			//0xE4
		struct TNTIconWidget* goldIcon;				//0xE8
		struct TNTIconWidget* reqIcon[3];				//0xEC
		struct TNTItemList* itemList;					//0xF0
		struct TEWLabel* goldDemandLabel;				//0xF4
		struct TEWLabel* reqDemandLabel[3];			//0x100
		struct TEWLabel* goldQuantityLabel;			//0x10C
		struct TEWLabel* reqQuantityLabel[3];			//0x110
		struct TEWGraphicButtonWidget* upgradeBtn;		//0x11C
		struct TEWLabel* upgradeBtnLabel;				//0x120
		int8_t unknown22;						//0x124
		int8_t unknown23;						//0x125
		int16_t unknown24;						//0x126
		uint32_t goldQuantity;					//0x128
		uint32_t reqQuantity[3];				//0x12C
		uint32_t thirdReqIconId;				//0x138
		uint32_t currentGoldAmount;				//0x13C
	};
	static_assert(sizeof(TNTSPCardUpgradeWidget) == 0x140, "TNTSPCardUpgradeWidget does not have a size of 0x140.");
#pragma pack(pop)
}