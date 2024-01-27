module;
export module TEWCustomFormWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCustomFormWidget : public TEWCustomPanelWidget
	{
		char unknown19[24];		// 0x00A4 something to do with resize 0xAD for minimap
	};
	static_assert(sizeof(TEWCustomFormWidget) == 0x00BC, "TEWCustomFormWidget does not have a size of 0x00BC.");
#pragma pack(pop)
}
