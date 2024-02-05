module;
export module TNTLoginWindowWidget;
import TEWCustomFormWidget;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTLoginWindowWidget : public TEWCustomFormWidget
	{
		char unknown38[52];							// 0x0BC
		struct TEWGraphicButtonWidget* unknown39;	// 0x0F0
		TEWGraphicButtonWidget* unknown40;			// 0x0F4
		struct TEWLabel* unknown41;					// 0x0F8
		TEWLabel* unknown42;						// 0x0FC
		struct TEWEditWidget* unknown43;			// 0x100
		struct TEWPaddWordEdit* unknown44;			// 0x104
		char unknown45[4];							// 0x108
		struct TNTSimpleListBoxWidget* unknown46;	// 0x10C
		TEWGraphicButtonWidget* unknown47;			// 0x110
		TEWCustomPanelWidget* unknown48;			// 0x114
		TEWLabel* unknown49;						// 0x118
		Properties::Logical::DelphiString* unknown50;		// 0x11C
	};
	static_assert(sizeof(TNTLoginWindowWidget) == 0x120, "TNTLoginWindowWidget size isn't 0x120.");
	static_assert(sizeof(TNTLoginWindowWidget) <= 0x120, "TNTLoginWindowWidget size is upper than 0x120.");
	static_assert(sizeof(TNTLoginWindowWidget) >= 0x120, "TNTLoginWindowWidget size is lower than 0x120.");
#pragma pack(pop)
}