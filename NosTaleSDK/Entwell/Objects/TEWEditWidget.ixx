module;
#include <stdint.h>
export module TEWEditWidget;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWEditWidget : public TEWControlWidget
	{
		wchar_t* buffer;                        // 0x68
		char unknown13[4];                        // 0x6C something with text (got out of memory and asian character appeared)
		char unknown14[4];                        // 0x70 used for ctrl+clic on item for ALL chat (speaker), as a packet completion : 2 46 (inventory type, cell)
		char unknown15[4];                        // 0x74 used to store only text before item_name (without the "{item_name}" when using ctrl+click item)
		int32_t textCursorPosition;                // 0x78
		int32_t pxBeforeTextCursor;                // 0x7C
		int32_t textPadding;                    // 0x80 < 0 : pads to the right, > 0 : pads to the left
		int32_t numberCharactersSelected;        // 0x84 < 0 : textCursor is on the left, > 0 : textCursor is on the right
		uint32_t lastTimeTextCursorBlinked;        // 0x88
		char unknown16[1 * 4];                    // 0x8C
		char onClickCallback[8];                // 0x90
		char unknown16_2[2 * 4];                // 0x98
		char onKeyPress[8];                    // 0xA0
		char callback[8];                        // 0xA8
		char callback2[8];                        // 0xA8
		char callback3[8];                        // 0xA8
		char unknown17[3 * 8];    // 0xE0 Probably 3 others callback
		int8_t fontStyle;                        // 0xD8
		char unknown18;                            // 0xD9
		char textBgra[4];                            // 0xDA
		char selectionBgra[4];                        // 0xDE
		char unknown19[2];                        // 0xE2
	};
	static_assert(sizeof(TEWEditWidget) == 0xE4, "TEWEditWidget does not have a size of 0xE4."); //AA, fix here. I broke something.
#pragma pack(pop)
}
