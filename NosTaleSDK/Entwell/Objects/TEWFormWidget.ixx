module;
export module TEWFormWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWFormWidget : public TEWCustomFormWidget
	{
		char unknown22[4];				// 0xBC
		char resizeFlag[1];	// 0xC0
		char unknown24[3];				// 0xC1 probably padding
	};
	static_assert(sizeof(TEWFormWidget) == 0xC4, "TEWFormWidget does not have a size of 0xC4.");
#pragma pack(pop)
}