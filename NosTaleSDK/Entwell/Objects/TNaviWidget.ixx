module;
#include <stdint.h>
export module TNaviWidget;
import TLBSWidget;
import TImpossibleIconWidget;

namespace NosTaleSDK::Entwell::Classes
{
    class TNaviNameViewer;
    class TNaviChatViewer;
    class TNaviMultiSelect;
    class TDowsingArrowWidget;
    class TReadyWidget;
    class TImpossibleIconWidget;

#pragma pack(push, 1)
	export struct TNaviWidget : public TLBSWidget
	{
        bool isLeftClicking;                                // 0x24
        bool isRightClicking;                               // 0x25
        char isClickingWithShift;                           // 0x26 Becomes 1 when holding shift and left clicking (causing the click to not be taken into account)
        bool isHovering;                                    // 0x27
        bool isMovingMouseWhileRightclicking;               // 0x28 Becomes 0 very briefly when holding right click and moving the mouse on the TNaviWidget - No read found
        char unknown3[3];                                   // 0x29 probably padding
        uint32_t timestampLeftClick;                        // 0x2C
        uint32_t timestampClick;                            // 0x30 every click
        int16_t lastLeftClickPosX;                          // 0x34
        int16_t lastLeftClickPosY;                          // 0x36
        TNaviNameViewer* naviNameViewer;                    // 0x38
        TNaviChatViewer* naviChatViewer;                    // 0x3C
        TNaviMultiSelect* naviMultiSelect;                  // 0x40
        TDowsingArrowWidget* dowsingArrowsWidget;           // 0x44
        TReadyWidget* readyWidget;                          // 0x48
        bool getUpImmediately;                              // 0x4C Retrieved from stat packet
        bool smileyGone;                                    // 0x4D Retrieved from stat packet
        bool hpStatusGone;                                  // 0x4E Retrieved from stat packet
        bool raidboxContent;                                // 0x4F Retrieved from stat packet
        bool hatIsNotVisible;                               // 0x50 Retrieved from stat packet
        bool lockUI;                                        // 0x51 Retrieved from stat packet
        bool unknown4;                                      // 0x52 Unknown but retrieved from stat packet
        bool unknown5;                                      // 0x53 Unknown but retrieved from stat packet
        bool blockMinilandInvit;                            // 0x54 Retrieved from stat packet
        bool mouseTrap;                                     // 0x55 Retrieved from stat packet
        char unknown6[2];                                   // 0x56 probably padding
        char unknown7[4];                                   // 0x58 pointer to something, but -1 as value in my case
        TImpossibleIconWidget* impossibleWidget;            // 0x5C widget appearing when stunned/rooted
        char TMarkWidget[500][4];                           // 0x60 Yes, 500...
        char currentCursor[1];                               // 0x830
        bool useCustomCursor2;                              // 0x831
        int32_t unknown8;                                   // 0x832 might be another type but -1 (0xfffffff) in my case
        bool forbiddenToClick;                              // 0x833 ex: if clicking into a wall, you will get the cursor "forbidden" if you click because this value was 1 before clicking
        char unknown9;                                      // 0x834 probably padding
    };
    static_assert(sizeof(TNaviWidget) == 0x838, "TNaviWidget does not have a size of 0x838.");
#pragma pack(pop)
}