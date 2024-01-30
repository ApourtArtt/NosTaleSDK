module;
#include <stdint.h>
export module TNTQuickSlotWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTQuickSlotWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		struct TEWCustomPanelWidget* moveWidgetButton;		// 0x0C0
		struct TNTTimeAniIcon* slotsAniIcons[30];			// 0x0C4
		struct TNTItemList* unknown39;						// 0x13C
		struct TNTItemList* unknown40;						// 0x140
		struct TNTItemList* unknown41;						// 0x144
		struct TNTHintWidget* leftGaugeValue;				// 0x148
		struct TNTHintWidget* rightGaugeValue;				// 0x14C
		struct TEWCustomPanelWidget* totalGaugeBg;			// 0x150
		struct TEWGuageWithHintWidget* leftGauge;			// 0x154
		struct TEWCustomPanelWidget* leftGaugePanel;		// 0x158
		struct TEWGuageWithHintWidget* rightGauge;			// 0x15C
		struct TEWCustomPanelWidget* rightGaugePanel;		// 0x160
		char unknown42[4];									// 0x164
		struct TEWLabels* keyLabels;						// 0x168
		struct TEWControlWidgetEX* keyGlowEffect[30];		// 0x16C
		uint32_t glowEffectIntensity;						// 0x1E4 timestamp maybe
		char unknown43[4];									// 0x1E8
		struct TEWGraphicButtonWidget* firstTabButton;		// 0x1EC 
		struct TEWGraphicButtonWidget* secondTabButton;		// 0x1F0
		struct TEWGraphicButtonWidget* lockWidgetButton;	// 0x1F4
		struct TEWGraphicButtonWidget* changeLabelsButton;	// 0x1F8
		char unknown44[8];									// 0x1FC
	};
	static_assert(sizeof(TNTQuickSlotWidget) == 0x204, "TNTQuickSlotWidget size isn't 0x204.");
	static_assert(sizeof(TNTQuickSlotWidget) <= 0x204, "TNTQuickSlotWidget size is upper than 0x204.");
	static_assert(sizeof(TNTQuickSlotWidget) >= 0x204, "TNTQuickSlotWidget size is lower than 0x204.");
#pragma pack(pop)
}