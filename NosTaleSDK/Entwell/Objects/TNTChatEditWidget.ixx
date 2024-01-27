module;
#include <stdint.h>
export module TNTChatEditWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTChatEditWidget : public TEWCustomPanelWidget
	{
		char unknown19[1388];
	};
	static_assert(sizeof(TNTChatEditWidget) == 0x610, "TNTChatEditWidget does not have a size of 0x610.");
#pragma pack(pop)
}