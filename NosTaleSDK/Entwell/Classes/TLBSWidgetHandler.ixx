module;
#include <stdint.h>
export module TLBSWidgetHandler;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSWidgetHandler : public TObject
	{
		struct TNosTaleMainF* mainForm;				// 0x004
		uint16_t aspectRatioX;						// 0x008
		uint16_t aspectRatioY;						// 0x00A
		struct TGameRootWidget* gameRootWidget;		// 0x00C
		struct TLBSWidget* currentClickedWidget;	// 0x010
		TLBSWidget* currentHoveredWidget;			// 0x014
		TLBSWidget* lastClickedWidget;				// 0x018
		char unknown1[4];							// 0x01C
		char unknown2[4];							// 0x020
		bool unknown3;								// 0x024
		int16_t mouseXPosition;						// 0x025
		int16_t mouseYPosition;						// 0x027
		char unknown4[3];							// 0x029
		int unknown5;								// 0x02C
		char unknown6[4];							// 0x030
		char unknown7[4];							// 0x034
		char unknown8[4];							// 0x038
		int8_t unknown13;							// 0x03C
		char unknown9[3];							// 0x03D
		void* hkl;									// 0x040
		char unknown10[24];							// 0x044
		void* candidateStrArr;						// 0x05C
		char unknown11[4];							// 0x060
		char unknown12[676];						// 0x064
	};
	static_assert(sizeof(TLBSWidgetHandler) == 0x308, "TLBSWidgetHandler size isn't 0x308.");
	static_assert(sizeof(TLBSWidgetHandler) <= 0x308, "TLBSWidgetHandler size is upper than 0x308.");
	static_assert(sizeof(TLBSWidgetHandler) >= 0x308, "TLBSWidgetHandler size is lower than 0x308.");
#pragma pack(pop)
}