module;
export module TNTMessageBoxWidget;
import TNTCustomMessageWidget;
import Callback;
import WideString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMessageBoxWidget : public TNTCustomMessageWidget
	{
		struct TEWGraphicButtonWidget* leftButton;	// 0x0D8
		TEWGraphicButtonWidget* rightButton;		// 0x0DC
		Properties::Logical::Callback onClose;		// 0x0E0
		char unknown44[4];							// 0x0E8
		Properties::Logical::WideString* unknown45;	// 0x0EC
		Properties::Logical::WideString* arg;		// 0x0F0
	};
	static_assert(sizeof(TNTMessageBoxWidget) == 0xF4, "TNTMessageBoxWidget size isn't 0xF4.");
	static_assert(sizeof(TNTMessageBoxWidget) <= 0xF4, "TNTMessageBoxWidget size is upper than 0xF4.");
	static_assert(sizeof(TNTMessageBoxWidget) >= 0xF4, "TNTMessageBoxWidget size is lower than 0xF4.");
#pragma pack(pop)
}