module;
#include <stdint.h>
export module TLBSWidget;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSWidget : public TObject
	{
		int8_t evenThing;           // 0x04 Unknown use yet
		char unknown1[3];           // 0x05 Unknown
		struct TLBSWidget* parent;         // 0x08 Widget holding this one
		struct TLBSWidget* unknownWidget;  // 0x0C Unknown
		char border[8];             // 0x10
		bool visible;               // 0x18 Is the widget visible ?
		bool isHandlingClick;       // 0x19 Is the widget supposed to react on click ? Care : the whole Border describe the widget area
		bool isLastWidgetClicked;   // 0x1A Is the widget the last widget clicked ?
		bool savePosition;          // 0x1B If true, widget can change from to front or behind other widget (little bit complicated with minimapwidget)
		bool unknown2;				// 0x1C
		bool unknown3;				// 0x1D
		char cursor[1];             // 0x1E
		uint8_t useCustomCursor;    // 0x1F 255 when custom, else 0
		struct TLBSWidgetList* children;   // 0x20 List of childs
	};
	static_assert(sizeof(TLBSWidget) == 0x24, "TLBSWidget does not have a size of 0x24.");
#pragma pack(pop)
}