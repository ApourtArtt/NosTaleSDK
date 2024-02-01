module;
#include <stdint.h>
export module TNTChatEditWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTChatEditWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];							// 0x0A4
		TEWCustomPanelWidget* unknown31;			// 0x0A8
		struct TEWEditWidget* unknown32;			// 0x0AC
		char unknown33[8];							// 0x0B0
		struct TNTChatViewerWidget* unknown34;		// 0x0B8
		struct TEWControlWidgetEX* unknown35;		// 0x0BC
		struct TEWLabel* unknown36;					// 0x0C0
		uint16_t unknown37;							// 0x0C4
		uint16_t unknown38;							// 0x0C6
		char unknown39[2];							// 0x0C8
		uint16_t unknown40;							// 0x0CA
		uint8_t unknown41;							// 0x0CC
		uint8_t unknown42;							// 0x0CD
		char unknown43[2];							// 0x0CE
		uint32_t unknown44;							// 0x0D0
		uint8_t unknown45;							// 0x0D4
		char unknown46[3];							// 0x0D5
		TEWCustomPanelWidget* unknown47;			// 0x0D8
		TEWEditWidget* unknown48;					// 0x0DC
		struct TChatNameComboBoxWidget* unknown49;	// 0x0E0
		char unknown50[28];							// 0x0E4
		uint32_t unknown51;							// 0x100
		uint32_t unknown52;							// 0x104
		uint32_t unknown53;							// 0x108
		uint32_t unknown54;							// 0x10C
		TLBSWidget* unknown55;						// 0x110
		TEWLabel* unknown56;						// 0x114
		uint8_t unknown57;							// 0x118
		char unknown58[1251];						// 0x119
		int16_t unknown59;							// 0x5FC
		uint16_t unknown60;							// 0x5FE
		uint8_t unknown61;							// 0x600
		char unknown62[3];							// 0x601
		uint32_t unknown63;							// 0x604
		char unknown64[4];							// 0x608
		uint32_t unknown65;							// 0x60C
	};
	static_assert(sizeof(TNTChatEditWidget) == 0x610, "TNTChatEditWidget size isn't 0x610.");
	static_assert(sizeof(TNTChatEditWidget) <= 0x610, "TNTChatEditWidget size is upper than 0x610.");
	static_assert(sizeof(TNTChatEditWidget) >= 0x610, "TNTChatEditWidget size is lower than 0x610.");
#pragma pack(pop)
}