module;
#include <stdint.h>
export module TNTNewFamilyInfoWidget;
import TEWCustomPanelWidget;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewFamilyInfoWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];							// 0x0A4
		TList<void*>* unknown31;					// 0x0A8
		struct TNTIntHeadList* unknown32;			// 0x0AC
		char unknown33[132];						// 0x0B0
		struct TEWGraphicButtonWidget* unknown34;	// 0x134
		TEWGraphicButtonWidget* unknown35;			// 0x138
		TEWGraphicButtonWidget* unknown36;			// 0x13C
		struct TEWLabel* unknown37;					// 0x140
		TEWLabel* unknown38;						// 0x144
		char unknown39[48];							// 0x148
		struct TEWStringListView* unknown40;		// 0x178
		TEWStringListView* unknown41;				// 0x17C
		struct TEWScrollBar* unknown42;				// 0x180
		TEWGraphicButtonWidget* unknown43;			// 0x184
		TEWGraphicButtonWidget* unknown44;			// 0x188
		TEWGraphicButtonWidget* unknown45;			// 0x18C
		uint32_t unknown46;							// 0x190
		char unknown47[48];							// 0x194
		TEWGraphicButtonWidget* unknown48;			// 0x1C4
		uint8_t unknown49;							// 0x1C8
		char unknown50[3];							// 0x1C9
		TEWGraphicButtonWidget* unknown51;			// 0x1CC
		uint32_t unknown52;							// 0x1D0
		uint32_t unknown53;							// 0x1D4
		uint8_t unknown54;							// 0x1D8
		char unknown55[7];							// 0x1D9
	};
	static_assert(sizeof(TNTNewFamilyInfoWidget) == 0x1E0, "TNTNewFamilyInfoWidget size isn't 0x1E0.");
	static_assert(sizeof(TNTNewFamilyInfoWidget) <= 0x1E0, "TNTNewFamilyInfoWidget size is upper than 0x1E0.");
	static_assert(sizeof(TNTNewFamilyInfoWidget) >= 0x1E0, "TNTNewFamilyInfoWidget size is lower than 0x1E0.");
#pragma pack(pop)
}