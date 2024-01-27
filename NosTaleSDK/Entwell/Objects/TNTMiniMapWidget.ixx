module;
#include <stdint.h>
export module TNTMiniMapWidget;
import TEWCustomFormWidget;
import TEWLabel;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMiniMapWidget : public TEWCustomFormWidget
	{
		char unknown22[4];							//0xBC
		void* miniMap;								//0xC0 TMiniMapWidget
		TEWLabel* mapName;							//0xC4
		TEWGraphicButtonWidget* openMapBtn;			//0xC8
		TEWGraphicButtonWidget* collapseWidgetBtn;	//0xCC
		char unknown23[4];							//0xD0
		void* tsMiniMap;							//0xD4 TNTRiskMapWidget
		char unknown24[4];							//0xD8
		void* map;									//0xDC TNTZoneMapWidget
	};
	static_assert(sizeof(TNTMiniMapWidget) == 0xE0, "TNTMiniMapWidget does not have a size of 0xE0.");
#pragma pack(pop)
}