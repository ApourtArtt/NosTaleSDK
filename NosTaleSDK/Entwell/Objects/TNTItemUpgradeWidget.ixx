module;
#include <stdint.h>
export module TNTItemUpgradeWidget;
import TEWCustomFormWidget;
import TEWLabels;
import TNTIconWidget;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemUpgradeWidget : public TEWCustomFormWidget
	{
		char unknown21[4];						//0xBC
		TEWLabels* allLabels;					//0xC0
		TNTIconWidget* eqIcon;					//0xC4
		TNTIconWidget* requirementIcons[3];		//0xC8
		char unknown22[8];						//0xD4
		int32_t unknown23;						//0xDC
		void* eqItem;				//0xE0
		uint16_t eqItemId;						//0xE4
		char unknown24[58];						//0xE6
		void* firstReqItem;		//0x120
		uint16_t firstReqItemId;				//0x124
		char unknown25[58];						//0x126
		void* secondReqItem;		//0x160
		uint16_t secondReqItemId;				//0x164
		char unknown26[58];						//0x166
		void* thirdReqItem;		//0x1A0
		uint16_t thirdReqItemId;				//0x1A4
		char unknown27[50];						//0x1A6
		TEWGraphicButtonWidget* reinforceBtn;	//0x1D8
		char unknown28[4];						//0x1DC
		char unknown29[4];						//0x1E0
	};
	static_assert(sizeof(TNTItemUpgradeWidget) == 0x1E4, "TNTItemUpgradeWidget does not have a size of 0x1E4.");
#pragma pack(pop)
}