module;
#include <stdint.h>
export module TControl;
import TComponent;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TControl : public TComponent
	{
		void* parent;				// 0x030 TWinControl
		char unknown2[4];			// 0x034
		void* windowProc;			// 0x038 TWndMethod
		struct TControl* unknown3;	// 0x03C
		int left;					// 0x040
		int top;					// 0x044
		int width;					// 0x048
		int height;					// 0x04C
		uint32_t controlStyle;		// 0x050
		uint16_t controlState;		// 0x052
		bool useDesktopFont;		// 0x056
		bool isVisible;				// 0x057
		bool isEnabled;				// 0x058
		bool useParentFont;			// 0x059
		bool useParentColor;		// 0x05A
		bool isAligned;				// 0x05B
		bool isAutoSized;			// 0x05C
		uint8_t dragMode;			// 0x05D
		bool isControl;				// 0x05E
		bool biDiMode;				// 0x05F
		bool biDiModeParent;		// 0x060
		uint8_t anchor;				// 0x061
		bool isAnchorMove;			// 0x062
		char unknown4;				// 0x063
		char unknown5[0xF8];		// 0x064
	};
	static_assert(sizeof(TControl) == 0x15C, "TControl size isn't 0x15C.");
	static_assert(sizeof(TControl) <= 0x15C, "TControl size is upper than 0x15C.");
	static_assert(sizeof(TControl) >= 0x15C, "TControl size is lower than 0x15C.");
#pragma pack(pop)
}