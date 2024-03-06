module;
#include <stdint.h>
export module TNTChatViewerWidget;
import TEWFormWidget;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTChatViewerWidget : public TEWFormWidget
	{
		char unknown40[4];														// 0x0C4
		uint32_t unknown41;														// 0x0C8
		char unknown42[20];														// 0x0CC
		struct TEWScrollBar* scrollBar;											// 0x0E0
		TEWCustomPanelWidget* unknown43;										// 0x0E4
		char unknown44[24];														// 0x0E8
		uint8_t unknown45;														// 0x100
		char unknown46[3];														// 0x101
		struct TEWGraphicButtonWidget* unknown47;								// 0x104
		uint8_t unknown48;														// 0x108
		char unknown49;															// 0x109
		uint16_t unknown50;														// 0x10A
		uint16_t unknown51;														// 0x10C
		uint16_t unknown52;														// 0x10E
		uint16_t unknown53;														// 0x110
		uint8_t unknown54;														// 0x112
		uint8_t unknown55;														// 0x113
		uint16_t unknown56;														// 0x114
		uint16_t unknown57;														// 0x116
		Properties::Logical::DelphiArray<wchar_t>* unknown58;								// 0x118
		uint8_t unknown59;														// 0x11C
		uint8_t unknown60;														// 0x11D
		char unknown61[2];														// 0x11E
		uint16_t unknown62;														// 0x120
		uint16_t unknown63;														// 0x122
		struct TNTChatEditWidget* unknown64;									// 0x124
		TNTChatEditWidget* unknown65;											// 0x124
	};
	static_assert(sizeof(TNTChatViewerWidget) == 0x12C, "TNTChatViewerWidget size isn't 0x12C.");
	static_assert(sizeof(TNTChatViewerWidget) <= 0x12C, "TNTChatViewerWidget size is upper than 0x12C.");
	static_assert(sizeof(TNTChatViewerWidget) >= 0x12C, "TNTChatViewerWidget size is lower than 0x12C.");
#pragma pack(pop)
}