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
		TEWLabel* unknown46;						// 0x10C
		TEWLabel* unknown47;						// 0x110
		TEWCustomPanelWidget* unknown48;			// 0x114
		TNTItemList* unknown49;						// 0x118
		struct TEWTextOutLabel* unknown50;			// 0x11C
		TEWTextOutLabel* unknown51;					// 0x120
		TEWTextOutLabel* unknown52;					// 0x124
		TEWTextOutLabel* unknown53;					// 0x128
		TEWTextOutLabel* unknown54;					// 0x12C
		struct TEWGraphicButtonWidget* unknown55;	// 0x130
		TEWLabel* unknown56;						// 0x134
		TEWLabel* unknown57;						// 0x138
		TEWLabel* unknown58;						// 0x13C
		TNTIconWidget* unknown59;					// 0x140
		TEWLabel* unknown60[16];					// 0x144
		struct TEWStringListView* unknown61;		// 0x184
		TEWGraphicButtonWidget* unknown62;			// 0x188
		TEWGraphicButtonWidget* unknown63;			// 0x18C
		struct TNTIconViewer* unknown64;			// 0x190
		TNTIconViewer* unknown65;					// 0x194
		char unknown66[552];						// 0x198
		TEWCustomPanelWidget* unknown67;			// 0x3C0
		char unknown68[192];						// 0x3C4
		TEWLabel* unknown69;						// 0x484
		TEWCustomPanelWidget* unknown70;			// 0x488
		TEWLabel* unknown71;						// 0x48C
		TEWLabel* unknown72;						// 0x490
		TEWLabel* unknown73;						// 0x494
		TEWCustomPanelWidget* unknown74;			// 0x498
		TEWStringListView* unknown75;				// 0x49C
		TEWGraphicButtonWidget* unknown76;			// 0x4A0
		TEWGraphicButtonWidget* unknown77;			// 0x4A4
		TEWGraphicButtonWidget* unknown78;			// 0x4A8
		TEWGraphicButtonWidget* unknown79;			// 0x4AC
		TEWGraphicButtonWidget* unknown80;			// 0x4B0
		TEWGraphicButtonWidget* unknown81;			// 0x4B4
		TEWLabel* unknown82;						// 0x4B8
		TEWLabel* unknown83;						// 0x4BC
		TEWLabel* unknown84;						// 0x4C0
		TEWLabel* unknown85;						// 0x4C4
		char unknown86[32];							// 0x4C8
	};
	static_assert(sizeof(TNTSpecialaListInfoWidget) == 0x4E8, "TNTSpecialaListInfoWidget size isn't 0x4E8.");
	static_assert(sizeof(TNTSpecialaListInfoWidget) <= 0x4E8, "TNTSpecialaListInfoWidget size is upper than 0x4E8.");
	static_assert(sizeof(TNTSpecialaListInfoWidget) >= 0x4E8, "TNTSpecialaListInfoWidget size is lower than 0x4E8.");
#pragma pack(pop)
}