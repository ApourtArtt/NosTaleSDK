module;
#include <stdint.h>
export module TNTCharacterSummaryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCharacterSummaryInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		uint8_t unknown39;									// 0x0C0
		char unknown40[3];									// 0x0C1
		struct TNTMaskingGaugeWidget* unknown41;			// 0x0C4
		struct TNTMaskingGaugeWidget* unknown42;			// 0x0C8
		struct TNTItemList* unknown43;						// 0x0CC
		struct TNTItemList* unknown44;						// 0x0D0
		char unknown45[32];									// 0x0D4
		struct TPetSelectIcon* icon;						// 0x0F4
		char unknown46[8];									// 0x0F8
		uint32_t unknown47;									// 0x100
		char unknown48[4];									// 0x104
		uint32_t unknown49;									// 0x108
		uint32_t unknown50;									// 0x10C
		struct TEWLabel* unknown51;							// 0x110
		struct TEWLabelWithHint* unknown52;					// 0x114
		struct TEWLabelWithHint* unknown53;					// 0x118
		struct TEWControlWidgetEX* unknown54;				// 0x11C
		uint8_t unknown55;									// 0x120
		uint8_t unknown56;									// 0x121
		char unknown57[2];									// 0x122
		struct TNTGraphicButtonAtSpecialCard* unknown58;	// 0x124
		struct TEWCustomPanelWidget* unknown59;				// 0x128
		uint32_t unknown60;									// 0x12C
		uint32_t unknown61;									// 0x130
		struct TEWCustomPanelWidget* unknown62;				// 0x134
		char unknown63[48];									// 0x138
		uint16_t unknown64;									// 0x168
		char unknown65[2];									// 0x16A
		uint32_t unknown66;									// 0x16C
		char unknown67[4];									// 0x170
		struct TEWControlWidgetEX* unknown68;				// 0x174
		uint8_t unknown69;									// 0x178
		char unknown70[3];									// 0x179
		uint8_t unknown71;									// 0x17C
		char unknown72[15];									// 0x17D
	};
	static_assert(sizeof(TNTCharacterSummaryInfoWidget) == 0x18C, "TNTCharacterSummaryInfoWidget size isn't 0x18C.");
	static_assert(sizeof(TNTCharacterSummaryInfoWidget) <= 0x18C, "TNTCharacterSummaryInfoWidget size is upper than 0x18C.");
	static_assert(sizeof(TNTCharacterSummaryInfoWidget) >= 0x18C, "TNTCharacterSummaryInfoWidget size is lower than 0x18C.");
#pragma pack(pop)
}