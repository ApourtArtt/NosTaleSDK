module;
export module TChatNameComboBoxWidget;
import TComboBoxWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TChatNameComboBoxWidget : public TComboBoxWidget
	{
		char unknown38[4];						// 0x0DC
		struct TNTChatEditWidget* unknown39;	// 0x0D8
	};
	static_assert(sizeof(TChatNameComboBoxWidget) == 0xDC, "TChatNameComboBoxWidget size isn't 0xDC.");
	static_assert(sizeof(TChatNameComboBoxWidget) <= 0xDC, "TChatNameComboBoxWidget size is upper than 0xDC.");
	static_assert(sizeof(TChatNameComboBoxWidget) >= 0xDC, "TChatNameComboBoxWidget size is lower than 0xDC.");
#pragma pack(pop)
}