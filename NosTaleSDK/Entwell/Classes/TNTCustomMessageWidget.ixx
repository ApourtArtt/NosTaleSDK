module;
export module TNTCustomMessageWidget;
import TNTCustomMessageCoreWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCustomMessageWidget : public TNTCustomMessageCoreWidget
	{
		char unknown43[4];	// 0x0D4
	};
	static_assert(sizeof(TNTCustomMessageWidget) == 0xD8, "TNTCustomMessageWidget size isn't 0xD8.");
	static_assert(sizeof(TNTCustomMessageWidget) <= 0xD8, "TNTCustomMessageWidget size is upper than 0xD8.");
	static_assert(sizeof(TNTCustomMessageWidget) >= 0xD8, "TNTCustomMessageWidget size is lower than 0xD8.");
#pragma pack(pop)
}