module;
#include <stdint.h>
export module TLBSWidget;
import TObject;
import Border;
import Cursor;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSWidget : public TObject
	{
		int8_t unknown;														// 0x004
		char unknown2[3];													// 0x005
		struct TLBSWidget* parent;											// 0x008
		struct TLBSWidget* linkedWidget;									// 0x00C
		struct NosTaleSDK::Entwell::Properties::Graphical::Border border;	// 0x010
		bool isVisible;														// 0x018
		bool isHandlingClick;												// 0x019
		bool isLastClicked;													// 0x01A
		bool isInFront;														// 0x01B
		bool unknown3;														// 0x01C
		bool unknown4;														// 0x01D
		NosTaleSDK::Entwell::Enumerations::Cursor cursor;					// 0x01E
		uint8_t useCustomCursor;											// 0x01F 255 when custom, else 0
		struct TLBSWidgetList* children;									// 0x020
	};
	static_assert(sizeof(TLBSWidget) == 0x24, "TLBSWidget does not have a size of 0x24.");
	static_assert(sizeof(TLBSWidget) <= 0x24, "TLBSWidget does not have a size of 0x24 or lower.");
	static_assert(sizeof(TLBSWidget) >= 0x24, "TLBSWidget does not have a size of 0x24 or upper.");
#pragma pack(pop)
}