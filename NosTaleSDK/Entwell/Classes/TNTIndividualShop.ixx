module;
export module TNTIndividualShop;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIndividualShop : public TEWCustomFormWidget
	{
		char unknown141[208]; // 0xBC
	};
	static_assert(sizeof(TNTIndividualShop) == 0x18C, "TNTIndividualShop does not have a size of 0x18C.");
#pragma pack(pop)
}