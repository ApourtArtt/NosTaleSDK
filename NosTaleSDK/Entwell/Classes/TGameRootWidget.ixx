module;
export module TGameRootWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TGameRootWidget : public TLBSWidget
	{
	};
	static_assert(sizeof(TGameRootWidget) == 0x24, "TGameRootWidget size isn't 0x24.");
	static_assert(sizeof(TGameRootWidget) <= 0x24, "TGameRootWidget size is upper than 0x24.");
	static_assert(sizeof(TGameRootWidget) >= 0x24, "TGameRootWidget size is lower than 0x24.");
#pragma pack(pop)
}