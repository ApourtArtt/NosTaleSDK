module;
#include <stdint.h>
export module TEWGuageWithHintWidget;
import TEWGuageWidget;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWGuageWithHintWidget : public TEWGuageWidget
	{
		char unknown40[4];						// 0x0BC
		Properties::Logical::DelphiString* unknown41;	// 0x0C0
		uint32_t unknown42;						// 0x0C4
	};
	static_assert(sizeof(TEWGuageWithHintWidget) == 0xC8, "TEWGuageWithHintWidget size isn't 0xC8.");
	static_assert(sizeof(TEWGuageWithHintWidget) <= 0xC8, "TEWGuageWithHintWidget size is upper than 0xC8.");
	static_assert(sizeof(TEWGuageWithHintWidget) >= 0xC8, "TEWGuageWithHintWidget size is lower than 0xC8.");
#pragma pack(pop)
}