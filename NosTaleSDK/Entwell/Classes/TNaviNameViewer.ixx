module;
#include <stdint.h>
export module TNaviNameViewer;
import TObject;
import FontStyle;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviNameViewer : public TObject
	{
		char pressVKeyCounter;				// 0x004
		char maxVKeyCounter;				// 0x005 4 by default
		char unknown[2];					// 0x006
		struct TMapObjBase* targetHovered;	// 0x008
		uint8_t displayEntity;				// 0x00C enum (0, 0x12, 0x1a, 0x1e)
		Enumerations::FontStyle fontStyle;	// 0x00D
		uint16_t pseudonymPosY;				// 0x00E
		uint16_t spaceBetweenLines;			// 0x010
		int16_t reputationIconWidth;		// 0x012
		int16_t reputationIconHeight;		// 0x014
		char unknown2[2];					// 0x016
	};
	static_assert(sizeof(TNaviNameViewer) == 0x18, "TNaviNameViewer size isn't 0x18.");
	static_assert(sizeof(TNaviNameViewer) <= 0x18, "TNaviNameViewer size is upper than 0x18.");
	static_assert(sizeof(TNaviNameViewer) >= 0x18, "TNaviNameViewer size is lower than 0x18.");
#pragma pack(pop)
}