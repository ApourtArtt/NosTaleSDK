module;
#include <stdint.h>
export module TNTIconWidget;
import TEWControlWidgetEvent;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconWidget : public TEWControlWidgetEvent
	{
		bool showEdgesInblue;	// 0x70
		char unknown14[15];		// 0x71
		int16_t clickX;			// 0x80
		int16_t clickY;			// 0x82
		bool keepTransparency;	// 0x84
		bool resized;			// 0x85 Weird behaviour, what is it really ?
		char unknown16[26];		// 0x86
		/*
		0x98 : callback doubleleft  click
		*/
		int8_t imageIf;			// 0xA0 5 for my turtle, other value = transparent. 1 on my sheep change to something animated.
		bool showEdgesInOrange;	// 0xA1
		char unknown17;			// 0xA2
		bool animate;			// 0xA3
		char unknown18[4];		// 0xA4
		char image[4];	// 0xA8
		char unknown19[4];		// 0xAC
		int16_t slot;			// 0xB0
		char unknown20[26];		// 0xB2
	};
	static_assert(sizeof(TNTIconWidget) == 0xCC, "TNTIconWidget does not have a size of 0xCC.");
#pragma pack(pop)
}