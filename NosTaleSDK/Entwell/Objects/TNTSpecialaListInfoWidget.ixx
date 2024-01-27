module;
export module TNTSpecialaListInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialaListInfoWidget : public TEWCustomFormWidget
	{
		char unknown20[0x420]; // 0xBC
	};
	static_assert(sizeof(TNTSpecialaListInfoWidget) == 0x04DC, "TNTSpecialaListInfoWidget does not have a size of 0x04DC.");
#pragma pack(pop)
}