module;
#include <stdint.h>
export module TNTShopOpenUIWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTShopOpenUIWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];							// 0x0A4
		struct TEWRollOverButtonWidget* tabBtn[6];	// 0x0A8
		struct TEWCustomPanelWidget* hintWidget;	// 0x0C0
		struct TEWLabel* hintLabel;					// 0x0C4
		char unknown31[12];							// 0x0C8
		int32_t tabId;								// 0x0D4
	};
	static_assert(sizeof(TNTShopOpenUIWidget) == 0xD8, "TNTShopOpenUIWidget size isn't 0xD8.");
	static_assert(sizeof(TNTShopOpenUIWidget) <= 0xD8, "TNTShopOpenUIWidget size is upper than 0xD8.");
	static_assert(sizeof(TNTShopOpenUIWidget) >= 0xD8, "TNTShopOpenUIWidget size is lower than 0xD8.");
#pragma pack(pop)
}