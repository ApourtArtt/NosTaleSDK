module;
#include <stdint.h>
export module TBuddyChatWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TBuddyChatWidget : public TEWCustomFormWidget
	{
		char unknown20[4];							// 0x0BC
		struct TEWEditWidget* inputField;           // 0x0C0
		uint8_t unknown21[12];                      // 0x0C4
		char* characterName;                        // 0x0D0
		uint32_t characterId;                       // 0x0D4
		uint32_t unknown22;                         // 0x0D8
		struct TEWStringListView* stringListView;   // 0x0DC
		struct TEWScrollBar* scrollBar;             // 0x0E0
		struct TEWCustomPanelWidget* panelWidget;   // 0x0E4
		struct TEWLabel* labelColor;                // 0x0E8
		char unknown24[4];							// 0x0EC
		char unknown25[2];							// 0x0F0
		uint16_t unknown26;							// 0x0F2
		uint32_t unknown27;							// 0x0F4
		char unknown28[8];							// 0x0F8
		uint16_t unknown29;							// 0x100
		uint16_t unknown30;							// 0x102
		uint32_t unknown31;							// 0x104
	};
	static_assert(sizeof(TBuddyChatWidget) == 0x108, "TBuddyChatWidget size isn't 0x108.");
	static_assert(sizeof(TBuddyChatWidget) <= 0x108, "TBuddyChatWidget size is upper than 0x108.");
	static_assert(sizeof(TBuddyChatWidget) >= 0x108, "TBuddyChatWidget size is lower than 0x108.");
#pragma pack(pop)
}