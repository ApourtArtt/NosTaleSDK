module;
#include <stdint.h>
export module TNTQuickSlotWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTQuickSlotWidget : public TEWCustomFormWidget
	{
		char pad_00BC[4]; //0x00BC
		struct TEWCustomPanelWidget* moveWidgetButton; //0x00C0 this is the blue button to move the widget in-game
		struct TNTTimeAniIcon* aSlotsAniIcons[30]; //0x00C4 Array of pointers to TNTTimeAniIcon
		struct TNTItemList* uknownList_1; //0x013C Contains data bout the item/skill in the slot
		struct TNTItemList* uknownList_2; //0x0140
		struct TNTItemList* uknownList_3; //0x0144
		struct TEWLabels* keyLabels; //0x0148 the labels for each button: 1,2,3....
		struct TEWControlWidgetEX* aKeyGlowEffect[30]; //0x014C Array of pointers to TEWControlWidgetEX, by default all of them are disabled, they hold the intermittent yellow border glow
		uint32_t glowEffectIntensity; //0x01C4 Constantly changing, goes from 0-95
		char pad_01C8[4]; //0x01C8
		struct TEWGraphicButtonWidget* firstTabButton; //0x01CC 
		struct TEWGraphicButtonWidget* secondTabButton; //0x01D0
		struct TEWGraphicButtonWidget* lockWidgetButton; //0x01D4
		struct TEWGraphicButtonWidget* changeLabelsButton; //0x01D8
		char pad_01DC[4]; //0x01DC
	};
	static_assert(sizeof(TNTQuickSlotWidget) == 0x1E0, "TNTQuickSlotWidget does not have a size of 0x1E0");
#pragma pack(pop)
}