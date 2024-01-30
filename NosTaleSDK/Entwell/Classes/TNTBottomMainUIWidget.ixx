module;
export module TNTBottomMainUIWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTBottomMainUIWidget : public TEWCustomPanelWidget
	{
		char unknown19[4];									// 0x0A4
		struct TNTPlayerCExpGaugeWidget* cexpGauge;			// 0x0A8
		struct TNTTrayWidget* tray;							// 0x0AC
		struct TEWRollOverButtonWidget* optionsBtn;			// 0x0B0
		struct TEWRollOverButtonWidget* secondOptionsBtn;	// 0x0B4
		struct TEWRollOverButtonWidget* nosmallBtn;			// 0x0B8
		struct TEWRollOverButtonWidget* eventBtn;			// 0x0BC
		struct TEWRollOverButtonWidget* battlePassBtn;		// 0x0C0
		struct TEWCustomPanelWidget* oldPanel;				// 0x0C4
		struct TEWStringListView* oldText;					// 0x0C8
		char unknown20[88];									// 0x0CC
		uint32_t unknown21;									// 0x124
	};
	static_assert(sizeof(TNTBottomMainUIWidget) == 0x128, "TNTBottomMainUIWidget size isn't 0x128.");
	static_assert(sizeof(TNTBottomMainUIWidget) <= 0x128, "TNTBottomMainUIWidget size is upper than 0x128.");
	static_assert(sizeof(TNTBottomMainUIWidget) >= 0x128, "TNTBottomMainUIWidget size is lower than 0x128.");
#pragma pack(pop)
}