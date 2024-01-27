module;
#include <stdint.h>
export module TNaviChatViewer;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{

    class TNTHintWidget;
#pragma pack(push, 1)
	export struct TNaviChatViewer : public TObject
	{
        int16_t numberOfLines;          // 0x04
        int16_t spaceBehindLine;        // 0x06
        int16_t invertedChatXOffset;    // 0x08 e.g: if value +200, the chat will be 200px at the left of the character head, if -200, 200px at the right (note: also applies to hp/mana bar, shop's name etc)
        char unknown1[2];               // 0x0A probably padding
        char* packet;                   // 0x0C Used when 0x10 is not nullptr
        char unknown3[4];               // 0x10 pointer to something
        char unknown4[4];               // 0x14
        uint32_t time;                  // 0x18
        char* text;                     // 0x1C
        char unknown7[4];               // 0x20
        char unknown8[4];               // 0x24
        char unknown9[4];               // 0x28 Used as a bool on 0x28 but seems to be a ptr
        char unknown10[4];              // 0x2C
        TNTHintWidget* aboveHeadHint;   // 0x30 When (e.g) transforming, isVisible will be true
        TNTHintWidget* hintWidget;      // 0x30 Idk what it is used for but isVisible turns to false when a msg is displayed
        char unknown11[4];              // 0x38 pointer to something
        int16_t unknown12;              // 0x3C always ++ then reset to 0
        char unknown13[2];              // 0x3E probably padding
        char unknown14[4];              // 0x40 -1 in my case, no W/R found
    };
    static_assert(sizeof(TNaviChatViewer) == 0x44, "TNaviChatViewer does not have a size of 0x44.");
#pragma pack(pop)
}