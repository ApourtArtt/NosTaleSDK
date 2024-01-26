module;
export module TGameRootWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TGameRootWidget : public TLBSWidget
	{
	};
	static_assert(sizeof(TGameRootWidget) == 0x24, "TGameRootWidget does not have a size of 0x24.");
#pragma pack(pop)
}