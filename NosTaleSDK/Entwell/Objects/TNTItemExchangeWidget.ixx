module;
export module TNTItemExchangeWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemExchangeWidget : public TEWCustomFormWidget
	{
		char unknown141[204]; // 0xBC
	};
	static_assert(sizeof(TNTItemExchangeWidget) == 0x188, "TNTItemExchangeWidget does not have a size of 0x188.");
#pragma pack(pop)
}