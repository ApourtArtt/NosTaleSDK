module;
#include <stdint.h>
export module TNaviChatViewer;
import TObject;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviChatViewer : public TObject
	{
		int16_t numberOfLines;					// 0x004
		int16_t spaceBehindLine;				// 0x006
		int16_t invertedChatXOffset;			// 0x008 > 0 => left // < 0 => right
		char unknown[2];						// 0x00A
		Properties::Logical::DelphiString* packet;    // 0x00C
		void* unknown2;							// 0x010
		char unknown3[4];						// 0x014
		uint32_t timestamp;						// 0x018
		Properties::Logical::DelphiString* text;      // 0x01C
		char unknown4[4];						// 0x020
		Properties::Logical::DelphiString* unknown5;  // 0x024
		uint32_t unknown6;						// 0x028 bool or ptr
		char unknown7[4];						// 0x02C
		struct TNTHintWidget* aboveHeadHint;	// 0x030
		TNTHintWidget* hintWidget;				// 0x034
		void* unknown8;							// 0x038
		int16_t unknown9;						// 0x03C
		char unknown10[2];						// 0x03E
		char unknown11[4];						// 0x040
	};
	static_assert(sizeof(TNaviChatViewer) == 0x44, "TMovePosiMarked size isn't 0x44.");
	static_assert(sizeof(TNaviChatViewer) <= 0x44, "TMovePosiMarked size is upper than 0x44.");
	static_assert(sizeof(TNaviChatViewer) >= 0x44, "TMovePosiMarked size is lower than 0x44.");
#pragma pack(pop)
}