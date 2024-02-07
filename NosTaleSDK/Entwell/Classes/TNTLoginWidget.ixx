module;
#include <stdint.h>
export module TNTLoginWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTLoginWidget : public TLBSWidget
	{
		struct TEWControlWidgetEX* unused;				// 0x024
		struct TNTNewServerSelectWidget2* serverSelect;	// 0x028
		uint32_t unknown7;								// 0x02C
		bool isInLoading;								// 0x030
		char unknown9[3];								// 0x031
		struct TNTLoginWindowWidget* loginWindow;		// 0x034
		uint8_t unknown11;								// 0x038
		uint8_t unknown12;								// 0x039
		char unknown13[2];								// 0x03A
	};
	static_assert(sizeof(TNTLoginWidget) == 0x3C, "TNTLoginWidget size isn't 0x3C.");
	static_assert(sizeof(TNTLoginWidget) <= 0x3C, "TNTLoginWidget size is upper than 0x3C.");
	static_assert(sizeof(TNTLoginWidget) >= 0x3C, "TNTLoginWidget size is lower than 0x3C.");
#pragma pack(pop)
}