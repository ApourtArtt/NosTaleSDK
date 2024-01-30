module;
export module TNTItemExchangeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemExchangeWidget : public TEWCustomFormWidget
	{
		char unknown38[204]; // 0xBC
	};
	static_assert(sizeof(TNTItemExchangeWidget) == 0x188, "TNTItemExchangeWidget size isn't 0x188.");
	static_assert(sizeof(TNTItemExchangeWidget) <= 0x188, "TNTItemExchangeWidget size is upper than 0x188.");
	static_assert(sizeof(TNTItemExchangeWidget) >= 0x188, "TNTItemExchangeWidget size is lower than 0x188.");
#pragma pack(pop)
}