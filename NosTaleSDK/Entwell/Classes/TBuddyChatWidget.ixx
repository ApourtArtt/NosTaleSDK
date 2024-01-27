module;
#include <stdint.h>
export module TBuddyChatWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TBuddyChatWidget : public TEWCustomFormWidget
	{
        uint8_t pad_00BC[4];                // 0x00BC
        struct TEWEditWidget* inputField;          // 0x00C0
        uint8_t pad_00C4[12];               // 0x00C4
        char* characterName;                // 0x00D0
        uint32_t characterId;               // 0x00D4
        char pad_00D8[4];                   // 0x00D8
        void* stringListView;  // 0x00DC
        struct TEWScrollBar* scrollBar;            // 0x00E0
        struct TEWCustomPanelWidget* panelWidget;  // 0x00E4
        struct TEWLabel* labelColor;               // 0x00E8
        uint8_t pad_00EC[28];               // 0x00EC
    };
    static_assert(sizeof(TBuddyChatWidget) == 0x108, "TBuddyChatWidget does not have a size of 0x108.");
#pragma pack(pop)
}