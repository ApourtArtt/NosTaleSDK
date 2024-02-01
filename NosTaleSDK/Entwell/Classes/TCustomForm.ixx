module;
export module TCustomForm;
import TScrollingWinControl;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TCustomForm : public TScrollingWinControl
	{
		char unknown8[0xDC]; // 0x21C
	};
	static_assert(sizeof(TCustomForm) == 0x2F8, "TCustomForm size isn't 0x2F8.");
	static_assert(sizeof(TCustomForm) <= 0x2F8, "TCustomForm size is upper than 0x2F8.");
	static_assert(sizeof(TCustomForm) >= 0x2F8, "TCustomForm size is lower than 0x2F8.");
#pragma pack(pop)
}