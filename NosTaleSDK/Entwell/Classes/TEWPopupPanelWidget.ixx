module;
export module TEWPopupPanelWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWPopupPanelWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];					// 0x0A4
		struct TEWPopupCover* unknown31;	// 0x0A8
	};
	static_assert(sizeof(TEWPopupPanelWidget) == 0xAC, "TEWPopupPanelWidget size isn't 0xAC.");
	static_assert(sizeof(TEWPopupPanelWidget) <= 0xAC, "TEWPopupPanelWidget size is upper than 0xAC.");
	static_assert(sizeof(TEWPopupPanelWidget) >= 0xAC, "TEWPopupPanelWidget size is lower than 0xAC.");
#pragma pack(pop)
}