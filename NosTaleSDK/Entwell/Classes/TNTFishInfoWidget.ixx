module;
#include <stdint.h>
export module TNTFishInfoWidget;
import TEWCustomFormWidget;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTFishInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];									// 0x0BC
		uint32_t unknown39;									// 0x0C0
		uint32_t unknown40;									// 0x0C4
		uint32_t unknown41;									// 0x0C8
		uint32_t unknown42;									// 0x0CC
		TEWCustomPanelWidget* unknown43;					// 0x0D0
		struct TEWScrollBar* scrollBar;						// 0x0D4
		struct TNTIconWidget* icons[21];					// 0x0D8
		uint32_t unknown46;									// 0x12C
		struct TNTCharacterInventoryInfoWidget* inventory;	// 0x130
		struct TEWListView* unknown47;						// 0x134
		char unknown48[12];									// 0x138
		TList<void*>* unknown49;							// 0x144
		char unknown50[4];									// 0x148
		TEWListView* unknown51;								// 0x14C
		struct TEWGraphicButtonWidget* unknown52;			// 0x150
		TEWCustomPanelWidget* unknown53;					// 0x154
		struct TEWControlWidgetMouseEvent* unknown54;		// 0x158
		TEWCustomPanelWidget* unknown55;					// 0x15C
		struct TEWLabel* unknown56;							// 0x160
	};
	static_assert(sizeof(TNTFishInfoWidget) == 0x164, "TNTFishInfoWidget size isn't 0x164.");
	static_assert(sizeof(TNTFishInfoWidget) <= 0x164, "TNTFishInfoWidget size is upper than 0x164.");
	static_assert(sizeof(TNTFishInfoWidget) >= 0x164, "TNTFishInfoWidget size is lower than 0x164.");
#pragma pack(pop)
}