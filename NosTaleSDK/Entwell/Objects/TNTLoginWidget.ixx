module;
#include <stdint.h>
export module TNTLoginWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTLoginWidget : public TLBSWidget
	{
		char unknown3[0x18]; // 0x24
	};
	static_assert(sizeof(TNTLoginWidget) == 0x3C, "TNTLoginWidget does not have a size of 0x3C.");
#pragma pack(pop)
}