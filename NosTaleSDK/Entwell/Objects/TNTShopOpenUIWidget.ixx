module;
#include <stdint.h>
export module TNTShopOpenUIWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTShopOpenUIWidget : public TEWCustomPanelWidget
	{
		char unknown19[4];						//0xA4
		struct TEWRollOverButtonWidget* tabBtn[6];		//0xA8
		struct TEWCustomPanelWidget* hintWidget;		//0xBC
		struct TEWLabel* hintLabel;					//0xC0
		int32_t unknown20;						//0xC4
		int32_t unknown21;						//0xC8
		int32_t tabId;							//0xD0
	};
	static_assert(sizeof(TNTShopOpenUIWidget) == 0xD4, "TNTShopOpenUIWidget does not have a size of 0xD4.");
#pragma pack(pop)
}