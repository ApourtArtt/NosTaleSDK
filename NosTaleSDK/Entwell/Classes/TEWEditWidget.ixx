module;
#include <stdint.h>
export module TEWEditWidget;
import TEWControlWidget;
import WideString;
import Callback;
import TextStyle;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWEditWidget : public TEWControlWidget
	{
		Properties::Logical::WideString text;		// 0x068
		Properties::Logical::WideString unknown20;	// 0x06C 
		Properties::Logical::WideString unknown21;	// 0x070 Ctrl+Click text related
		Properties::Logical::WideString unknown22;	// 0x074 Ctrl+Click text related
		int32_t textCursorPosition;					// 0x078
		int32_t pxBeforeTextCursor;					// 0x07C
		int32_t textPadding;						// 0x080 < 0 : to the right, > 0 : to the left
		int32_t numberCharactersSelected;			// 0x084 < 0 : textCursor is on the left, > 0 : textCursor is on the right
		uint32_t lastTimeTextCursorBlinked;			// 0x088
		char unknown23[4];							// 0x08C
		Properties::Logical::Callback onClick;		// 0x090
		Properties::Logical::Callback unknown24;	// 0x098
		Properties::Logical::Callback onKeyPressed;	// 0x0A0
		Properties::Logical::Callback unknown25;	// 0x0A8
		Properties::Logical::Callback unknown26;	// 0x0B0
		Properties::Logical::Callback unknown27;	// 0x0B8
		Properties::Logical::Callback unknown28;	// 0x0C0
		Properties::Logical::Callback unknown29;	// 0x0C8
		Properties::Logical::Callback unknown30;	// 0x0D0
		Properties::Graphical::TextStyle textStyle;	// 0x0D8
		char unknown31;								// 0x0E3
	};
	static_assert(sizeof(TEWEditWidget) == 0xE4, "TEWEditWidget size isn't 0xE4.");
	static_assert(sizeof(TEWEditWidget) <= 0xE4, "TEWEditWidget size is upper than 0xE4.");
	static_assert(sizeof(TEWEditWidget) >= 0xE4, "TEWEditWidget size is lower than 0xE4.");
#pragma pack(pop)
}
