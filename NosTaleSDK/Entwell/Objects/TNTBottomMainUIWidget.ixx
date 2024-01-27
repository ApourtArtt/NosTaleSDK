module;
#include <stdint.h>
export module TNTBottomMainUIWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTBottomMainUIWidget : public TEWCustomPanelWidget
	{
		char unknown19[4];									//0xA4
		void* cexpGauge;									//0xA8 TNTPlayerCExpGaugeWidget
		void* tray;											//0xAC TNTTrayWidget
		struct TEWRollOverButtonWidget* optionsBtn;			//0xB0
		struct TEWRollOverButtonWidget* secondOptionsBtn;	//0xB4
		struct TEWRollOverButtonWidget* nosmallBtn;			//0xB8
		struct TEWRollOverButtonWidget* eventBtn;			//0xBC
		struct TEWRollOverButtonWidget* battlePassBtn;		//0xC0
		struct TEWCustomPanelWidget* oldPanel;						//0xC4 Old panel unused now
		struct TEWStringListView* text;						//0xC8 Text for strange panel
		char unknown20[80];									//0xCC
	};
	static_assert(sizeof(TNTBottomMainUIWidget) == 0x11C, "TNTBottomMainUIWidget does not have a size of 0x11C.");
#pragma pack(pop)
}