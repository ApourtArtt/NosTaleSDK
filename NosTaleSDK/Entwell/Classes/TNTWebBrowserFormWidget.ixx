module;
#include <stdint.h>
export module TNTWebBrowserFormWidget;
import TEWCustomFormWidget;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTWebBrowserFormWidget : public TEWCustomFormWidget
	{
		char unknown38[4];															// 0x0BC
		void* unknown39;															// 0x0C0 TChromium
		int16_t xOffset;															// 0x0C4
		int16_t yOffset;															// 0x0C6
		char unknown40[4];															// 0x0C8
		struct NosTaleSDK::Entwell::Properties::Logical::Position windowPosition;	// 0x0CC
		char unknown41[28];															// 0x0D0
		struct NosTaleSDK::Entwell::Properties::Logical::String* url;				// 0x0EC
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown42;			// 0x0F0
		char unknown43;																// 0x0F4
		uint8_t unknown44;															// 0x0F5
		char unknown45[2];															// 0x0F6
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown46;			// 0x0F8
		uint32_t closeFct;															// 0x0FC
	};
	static_assert(sizeof(TNTWebBrowserFormWidget) == 0x100, "TNTWebBrowserFormWidget size isn't 0x100.");
	static_assert(sizeof(TNTWebBrowserFormWidget) <= 0x100, "TNTWebBrowserFormWidget size is upper than 0x100.");
	static_assert(sizeof(TNTWebBrowserFormWidget) >= 0x100, "TNTWebBrowserFormWidget size is lower than 0x100.");
#pragma pack(pop)
}