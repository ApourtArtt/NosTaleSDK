module;
export module TNTCharacterSummaryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCharacterSummaryInfoWidget : public TEWCustomFormWidget
	{
		char unknown19[0xD0];
	};
	static_assert(sizeof(TNTCharacterSummaryInfoWidget) == 0x18C, "TNTCharacterSummaryInfoWidget does not have a size of 0x18C.");
#pragma pack(pop)
}