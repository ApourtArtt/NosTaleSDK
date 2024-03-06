module;
#include <stdint.h>
export module TNTCustomMessageCoreWidget;
import TEWCustomFormWidget;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCustomMessageCoreWidget : public TEWCustomFormWidget
	{
		char unknown38[4];													// 0x0BC
		Properties::Logical::DelphiArray<char>* text;									// 0x0C0
		Properties::Logical::DelphiArray<char>* unknown39;								// 0x0C4
		struct TEWLabels* labels;											// 0x0C8
		TEWLabels* unknown40;												// 0x0CC
		uint16_t unknown41;													// 0x0D0
		uint16_t unknown42;													// 0x0D2
	};
	static_assert(sizeof(TNTCustomMessageCoreWidget) == 0xD4, "TNTCustomMessageCoreWidget size isn't 0xD4.");
	static_assert(sizeof(TNTCustomMessageCoreWidget) <= 0xD4, "TNTCustomMessageCoreWidget size is upper than 0xD4.");
	static_assert(sizeof(TNTCustomMessageCoreWidget) >= 0xD4, "TNTCustomMessageCoreWidget size is lower than 0xD4.");
#pragma pack(pop)
}