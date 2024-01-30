module;
#include <stdint.h>
export module TNTIconWidget;
import TEWControlWidgetEvent;
import Callback;
import Position;
import Icon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconWidget : public TEWControlWidgetEvent
	{
		bool isBorderBlue;															// 0x070
		char unknown22[7];															// 0x071
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown23;		// 0x078
		struct NosTaleSDK::Entwell::Properties::Logical::Position clickPosition;	// 0x080
		bool isTransparent;															// 0x084
		bool unknown24;																// 0x085
		char unknown25[2];															// 0x086
		float unknown26;															// 0x088
		char unknown27[4];															// 0x08C
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown28;		// 0x090
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown29;		// 0x098
		int8_t unknown30;															// 0x0A0
		bool isBorderOrange;														// 0x0A1
		uint8_t unknown31;															// 0x0A2
		bool isAnimate;																// 0x0A3
		uint8_t unknown32;															// 0x0A4
		uint8_t unknown33;															// 0x0A5
		uint8_t unknown34;															// 0x0A6
		char unknown35;																// 0x0A7
		struct NosTaleSDK::Entwell::Properties::Graphical::Icon* icon;				// 0x0A8
		uint8_t unknown36;															// 0x0AC
		char unknown37;																// 0x0AD
		uint16_t unknown38;															// 0x0AE
		int16_t slot;																// 0x0B0
		char unknown39[2];															// 0x0B2
		uint32_t unknown40;															// 0x0B4
		uint32_t unknown41;															// 0x0B8
		char unknown42[10];															// 0x0BC
		uint16_t unknown43;															// 0x0C6
		uint8_t unknown44;															// 0x0C8
		uint8_t unknown45;															// 0x0C9
		uint8_t unknown46;															// 0x0CA
		uint8_t unknown47;															// 0x0CB
	};
	static_assert(sizeof(TNTIconWidget) == 0xCC, "TEWControlWidgetEvent size isn't 0xCC.");
	static_assert(sizeof(TNTIconWidget) <= 0xCC, "TEWControlWidgetEvent size is upper than 0xCC.");
	static_assert(sizeof(TNTIconWidget) >= 0xCC, "TEWControlWidgetEvent size is lower than 0xCC.");
#pragma pack(pop)
}