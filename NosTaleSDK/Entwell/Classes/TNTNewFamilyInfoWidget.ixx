module;
export module TNTNewFamilyInfoWidget;
import TEWCustomPanelWidget;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewFamilyInfoWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];							// 0x0A4
		struct TList<void*>* unknown31;				// 0x0A8
		struct TNTIntHeadList* unknown32;			// 0x0AC
		char unknown33[132];						// 0x0B0
		struct TEWGraphicButtonWidget* unknown34;	// 0x134
		struct TEWGraphicButtonWidget* unknown35;	// 0x138
		struct TEWGraphicButtonWidget* unknown36;	// 0x13C
		struct TEWLabel* unknown37;					// 0x140
		struct TEWLabel* unknown38;					// 0x144
		char unknown39[48];							// 0x148
		struct TEWStringListView* unknown40;		// 0x178
		struct TEWStringListView* unknown41;		// 0x17C
		struct TEWScrollBar* unknown42;				// 0x180
		struct TEWGraphicButtonWidget* unknown43;	// 0x184
		struct TEWGraphicButtonWidget* unknown44;	// 0x188
		struct TEWGraphicButtonWidget* unknown45;	// 0x18C
		uint32_t unknown46;							// 0x190
		char unknown47[48];							// 0x194
		struct TEWGraphicButtonWidget* unknown48;	// 0x1C4
		uint8_t unknown49;							// 0x1C8
		char unknown50[3];							// 0x1C9
		struct TEWGraphicButtonWidget* unknown51;	// 0x1CC
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