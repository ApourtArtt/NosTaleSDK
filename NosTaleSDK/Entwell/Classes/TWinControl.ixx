module;
export module TWinControl;
import TControl;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TWinControl : public TControl
	{
		char unknown6[0xA8]; // 0x15C
	};
	static_assert(sizeof(TWinControl) == 0x204, "TWinControl size isn't 0x204.");
	static_assert(sizeof(TWinControl) <= 0x204, "TWinControl size is upper than 0x204.");
	static_assert(sizeof(TWinControl) >= 0x204, "TWinControl size is lower than 0x204.");
#pragma pack(pop)
}