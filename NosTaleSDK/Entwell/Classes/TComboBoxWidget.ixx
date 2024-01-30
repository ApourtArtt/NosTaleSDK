module;
#include <stdint.h>
export module TComboBoxWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TComboBoxWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];							// 0x0A4
		struct TEWScrollBar* unknown31;				// 0x0A8
		struct TEWNormalButtonWidget* unknown32;	// 0x0AC
		char unknown33[12];							// 0x0B0
		uint32_t unknown34;							// 0x0BC
		uint32_t unknown35;							// 0x0C0
		uint32_t unknown36;							// 0x0C4
		char unknown37[12];							// 0x0C8
	};
	static_assert(sizeof(TComboBoxWidget) == 0xD4, "TComboBoxWidget size isn't 0xD4.");
	static_assert(sizeof(TComboBoxWidget) <= 0xD4, "TComboBoxWidget size is upper than 0xD4.");
	static_assert(sizeof(TComboBoxWidget) >= 0xD4, "TComboBoxWidget size is lower than 0xD4.");
#pragma pack(pop)
}