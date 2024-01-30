module;
export module TNTSpecialaListInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialaListInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];							// 0x0BC
		struct TEWControlWidgetEX* unknown39;		// 0x0C0
		char unknown40[40];							// 0x0C4
		struct TNTItemList* unknown41;				// 0x0EC
		struct TNTIconWidget* unknown42;			// 0x0F0
		char unknown43[16];							// 0x0F4
		struct TEWRollOverButtonWidget* unknown44;	// 0x104
		struct TEWLabel* unknown45;					// 0x108
		struct TEWLabel* unknown46;					// 0x10C
		struct TEWLabel* unknown47;					// 0x110
		struct TEWCustomPanelWidget* unknown48;		// 0x114
		struct TNTItemList* unknown49;				// 0x118
		struct TEWTextOutLabel* unknown50;			// 0x11C
		struct TEWTextOutLabel* unknown51;			// 0x120
		struct TEWTextOutLabel* unknown52;			// 0x124
		struct TEWTextOutLabel* unknown53;			// 0x128
		struct TEWTextOutLabel* unknown54;			// 0x12C
		struct TEWGraphicButtonWidget* unknown55;	// 0x130
		struct TEWLabel* unknown56;					// 0x134
		struct TEWLabel* unknown57;					// 0x138
		struct TEWLabel* unknown58;					// 0x13C
		struct TNTIconWidget* unknown59;			// 0x140
		struct TEWLabel* unknown60[16];				// 0x144
		struct TEWStringListView* unknown61;		// 0x184
		struct TEWGraphicButtonWidget* unknown62;	// 0x188
		struct TEWGraphicButtonWidget* unknown63;	// 0x18C
		struct TNTIconViewer* unknown64;			// 0x190
		struct TNTIconViewer* unknown65;			// 0x194
		char unknown66[552];						// 0x198
		struct TEWCustomPanelWidget* unknown67;		// 0x3C0
		char unknown68[192];						// 0x3C4
		struct TEWLabel* unknown69;					// 0x484
		struct TEWCustomPanelWidget* unknown70;		// 0x488
		struct TEWLabel* unknown71;					// 0x48C
		struct TEWLabel* unknown72;					// 0x490
		struct TEWLabel* unknown73;					// 0x494
		struct TEWCustomPanelWidget* unknown74;		// 0x498
		struct TEWStringListView* unknown75;		// 0x49C
		struct TEWGraphicButtonWidget* unknown76;	// 0x4A0
		struct TEWGraphicButtonWidget* unknown77;	// 0x4A4
		struct TEWGraphicButtonWidget* unknown78;	// 0x4A8
		struct TEWGraphicButtonWidget* unknown79;	// 0x4AC
		struct TEWGraphicButtonWidget* unknown80;	// 0x4B0
		struct TEWGraphicButtonWidget* unknown81;	// 0x4B4
		struct TEWLabel* unknown82;					// 0x4B8
		struct TEWLabel* unknown83;					// 0x4BC
		struct TEWLabel* unknown84;					// 0x4C0
		struct TEWLabel* unknown85;					// 0x4C4
		char unknown86[32];							// 0x4C8
	};
	static_assert(sizeof(TNTSpecialaListInfoWidget) == 0x4E8, "TNTSpecialaListInfoWidget size isn't 0x4E8.");
	static_assert(sizeof(TNTSpecialaListInfoWidget) <= 0x4E8, "TNTSpecialaListInfoWidget size is upper than 0x4E8.");
	static_assert(sizeof(TNTSpecialaListInfoWidget) >= 0x4E8, "TNTSpecialaListInfoWidget size is lower than 0x4E8.");
#pragma pack(pop)
}