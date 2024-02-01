module;
#include <stdint.h>
export module TNaviWidget;
import TLBSWidget;
import Position;
import Cursor;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviWidget : public TLBSWidget
	{
		bool isLeftClicking;									// 0x024
		bool isRightClicking;									// 0x025
		char isClickingWithShift;								// 0x026
		bool isHovering;										// 0x027
		bool isMovingMouseWhileRightClicking;					// 0x028
		char unknown5[3];										// 0x029
		uint32_t timestampLeftClick;							// 0x02C
		uint32_t timestampClick;								// 0x030
		Properties::Logical::Position lastLeftClickPosition;	// 0x034
		struct TNaviNameViewer* naviNameViewer;					// 0x038
		struct TNaviChatViewer* naviChatViewer;					// 0x03C
		struct TNaviMultiSelect* naviMultiSelect;				// 0x040
		struct TDowsingArrowWidget* dowsingArrowsWidget;		// 0x044
		struct TReadyWidget* readyWidget;						// 0x048
		bool getUpImmediately;									// 0x04C
		bool isSmileyGone;										// 0x04D
		bool isHpStatusGone;									// 0x04E
		bool raidboxContent;									// 0x04F
		bool isHatNotVisible;									// 0x050
		bool isUiLocked;										// 0x051
		bool unknown6;											// 0x052
		bool unknown7;											// 0x053
		bool isMlInviteBlocked;									// 0x054
		bool isMouseTrapped;									// 0x055
		uint8_t unknown8;										// 0x056
		uint8_t unknown9;										// 0x057
		void* unknown10;										// 0x058
		struct TImpossibleIconWidget* impossibleWidget;			// 0x05C
		struct TMarkWidget* markWidgets[500];					// 0x060
		Enumerations::Cursor cursor2;							// 0x830
		bool useCustomCursor2;									// 0x831
		uint16_t unknown11;										// 0x832
		uint16_t unknown12;										// 0x834
		uint8_t unknown13;										// 0x836 related to click on wall
		char unknown14;											// 0x837
	};
	static_assert(sizeof(TNaviWidget) == 0x838, "TNaviWidget size isn't 0x838.");
	static_assert(sizeof(TNaviWidget) <= 0x838, "TNaviWidget size is upper than 0x838.");
	static_assert(sizeof(TNaviWidget) >= 0x838, "TNaviWidget size is lower than 0x838.");
#pragma pack(pop)
}