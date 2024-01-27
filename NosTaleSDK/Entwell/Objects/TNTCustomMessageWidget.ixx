module;
#include <stdint.h>
export module TNTCustomMessageWidget;
import TNTCustomMessageCoreWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCustomMessageWidget : public TNTCustomMessageCoreWidget
	{
		char unknown23[4];			// 0xD4
	};
	static_assert(sizeof(TNTCustomMessageWidget) == 0xD8, "TNTCustomMessageWidget does not have a size of 0xD8");
#pragma pack(pop)
}