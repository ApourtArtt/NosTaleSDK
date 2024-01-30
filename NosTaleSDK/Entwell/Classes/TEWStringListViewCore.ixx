module;
#include <stdint.h>
export module TEWStringListViewCore;
import TEWLabels;
import TextStyle;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWStringListViewCore : public TEWLabels
	{
		struct TStringList* lastMessages;											// 0x088
		struct TStringList* unknown22;												// 0x08C
		struct TStringList* lines;													// 0x090
		struct TStringList* unknown23;												// 0x094
		int32_t currentLineIndex;													// 0x098
		int32_t count;																// 0x09C
		uint32_t unknown24;															// 0x0A0
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle** unknown25;	// 0x0A4
		char unknown27[4];															// 0x0A8
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle* unknown26;	// 0x0AC
	};
	static_assert(sizeof(TEWStringListViewCore) == 0xB0, "TEWStringListViewCore size isn't 0xB0.");
	static_assert(sizeof(TEWStringListViewCore) <= 0xB0, "TEWStringListViewCore size is upper than 0xB0.");
	static_assert(sizeof(TEWStringListViewCore) >= 0xB0, "TEWStringListViewCore size is lower than 0xB0.");
#pragma pack(pop)
}