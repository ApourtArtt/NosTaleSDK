module;
export module TNTNosMallGroupItemSelectWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallGroupItemSelectWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TNTNosMallItemListWidget* unknown39; // 0x0C0
		struct TEWLabels* unknown40;				// 0x0C4
		char unknown41[4];							// 0x0C8
	};
	static_assert(sizeof(TNTNosMallGroupItemSelectWidget) == 0xCC, "TNTNosMallGroupItemSelectWidget size isn't 0xCC.");
	static_assert(sizeof(TNTNosMallGroupItemSelectWidget) <= 0xCC, "TNTNosMallGroupItemSelectWidget size is upper than 0xCC.");
	static_assert(sizeof(TNTNosMallGroupItemSelectWidget) >= 0xCC, "TNTNosMallGroupItemSelectWidget size is lower than 0xCC.");
#pragma pack(pop)
}