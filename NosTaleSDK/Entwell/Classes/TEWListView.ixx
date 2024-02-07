module;
#include <stdint.h>
export module TEWListView;
import TEWStringListView;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWListView : public TEWStringListView
	{
		uint8_t unknown28;		// 0x0B0
		char unknown29[7];		// 0x0B1
		uint16_t unknown30;		// 0x0B8
		uint16_t unknown31;		// 0x0BA
		uint32_t unknown32;		// 0x0BC
		uint32_t hoveredIndex;	// 0x0C0
		uint8_t unknown34;		// 0x0C4
		char unknown35[3];		// 0x0C5
	};
	static_assert(sizeof(TEWListView) == 0xC8, "TEWListView size isn't 0xC8.");
	static_assert(sizeof(TEWListView) <= 0xC8, "TEWListView size is upper than 0xC8.");
	static_assert(sizeof(TEWListView) >= 0xC8, "TEWListView size is lower than 0xC8.");
#pragma pack(pop)
}