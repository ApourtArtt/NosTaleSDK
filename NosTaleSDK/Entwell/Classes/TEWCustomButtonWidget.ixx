module;
export module TEWCustomButtonWidget;
import TEWCustomPanelWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCustomButtonWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];															// 0x0A4
		bool isClicked;																// 0x0A8
		bool isHovered;																// 0x0A9
		char unknown31[6];															// 0x0AA
		struct NosTaleSDK::Entwell::Properties::Logical::Callback callback;			// 0x0B0
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknownCallback;	// 0x0B8
		bool unknown32;																// 0x0C0 Strange behaviour : 1 on click on button, not triggered by keyboard
		char unknown33;																// 0x0C1
		bool makeSound;																// 0x0C2
		char unknown34[5];															// 0x0C3
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknownCallback2;	// 0x0C8
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknownCallback3;	// 0x0D0
	};
	static_assert(sizeof(TEWCustomButtonWidget) == 0xD8, "TEWCustomButtonWidget size isn't 0xD8.");
	static_assert(sizeof(TEWCustomButtonWidget) <= 0xD8, "TEWCustomButtonWidget size is upper than 0xD8.");
	static_assert(sizeof(TEWCustomButtonWidget) >= 0xD8, "TEWCustomButtonWidget size is lower than 0xD8.");
#pragma pack(pop)
}