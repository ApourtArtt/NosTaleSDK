module;
#include <stdint.h>
export module TNTMaskingGaugeWidget;
import TLBSWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMaskingGaugeWidget : public TLBSWidget
	{
		struct TEWCustomPanelWidget* unknownPanel;	// 0x024
		TEWCustomPanelWidget* gaugeBackground;		// 0x028
		TEWCustomPanelWidget* unknownPanel2;		// 0x02C
		TEWCustomPanelWidget* maskPanel;			// 0x030
		TEWCustomPanelWidget* borderPanel;			// 0x034
		char unknown3[16];							// 0x038
		int32_t maxValue;							// 0x048
		int32_t currentValue;						// 0x04C
		int32_t bonusValue;							// 0x050
		float percentValue;							// 0x054
		Properties::Logical::Callback onUpdate;		// 0x058
		int32_t currentValue2;						// 0x060
		char unknown5[8];							// 0x064
		struct TEWLabel* valuesLabel;				// 0x06C
	};
	static_assert(sizeof(TNTMaskingGaugeWidget) == 0x70, "TNTMaskingGaugeWidget size isn't 0x70.");
	static_assert(sizeof(TNTMaskingGaugeWidget) <= 0x70, "TNTMaskingGaugeWidget size is upper than 0x70.");
	static_assert(sizeof(TNTMaskingGaugeWidget) >= 0x70, "TNTMaskingGaugeWidget size is lower than 0x70.");
#pragma pack(pop)
}