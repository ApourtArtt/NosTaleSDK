module;
#include <stdint.h>
export module TNaviNameViewer;
import TObject;
import TMapObjBase;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviNameViewer : public TObject
	{
        char vCounter;                      // 0x04 By clicking v, vCounter++ and vCounter can not go above 3
        char maxVCounter;                   // 0x05 4 by default
        char unknown[2];                    // 0x06 probably padding
        TMapObjBase* targetHovered;         // 0x08
        char displayEntity;                 // 0x0C can be an enum if needed (0, 0x12, 0x1a, 0x1e)
        char fontStyle;                     // 0x0D
        uint16_t pseudonymPosY;             // 0x0E
        uint16_t spaceBetweenLines;         // 0x10
        int16_t reputationWidth;            // 0x12
        int16_t reputationHeight;           // 0x14
        char unknown2[2];                   // 0x16 probably padding
    };
    static_assert(sizeof(TNaviNameViewer) == 0x18, "TNaviNameViewer does not have a size of 0x18.");
#pragma pack(pop)
}