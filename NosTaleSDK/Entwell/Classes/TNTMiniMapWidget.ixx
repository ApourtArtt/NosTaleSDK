module;
export module TNTMiniMapWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMiniMapWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TMiniMapWidget* miniMap;				// 0x0C0
		struct TEWLabel* mapName;					// 0x0C4
		struct TEWGraphicButtonWidget* openMapBtn;	// 0x0C8
		TEWGraphicButtonWidget* collapseWidgetBtn;	// 0x0CC
		char unknown39[4];							// 0x0D0
		struct TNTRiskMapWidget* tsMiniMap;			// 0x0D4
		char unknown40[4];							// 0x0D8
		struct TNTZoneMapWidget* map;				// 0x0DC
	};
	static_assert(sizeof(TNTMiniMapWidget) == 0xE0, "TNTMiniMapWidget size isn't 0xE0.");
	static_assert(sizeof(TNTMiniMapWidget) <= 0xE0, "TNTMiniMapWidget size is upper than 0xE0.");
	static_assert(sizeof(TNTMiniMapWidget) >= 0xE0, "TNTMiniMapWidget size is lower than 0xE0.");
#pragma pack(pop)
}