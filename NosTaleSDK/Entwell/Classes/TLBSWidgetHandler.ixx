module;
#include <stdint.h>
export module TLBSWidgetHandler;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSWidgetHandler : public TObject
	{
		void* TNosTaleMainF;						// 0x0004 TODO: class named TNosTaleMainF - also in 0x34
		uint16_t aspectRatioX;						// 0x0008
		uint16_t aspectRatioY;						// 0x000A
		struct TGameRootWidget* gameRootWidget;		// 0x000C
		struct TLBSWidget* currentClickedWidget;	// 0x0010
		struct TLBSWidget* currentHoveredWidget;	// 0x0014
		struct TLBSWidget* lastClickedWidget;		// 0x0018
		char unknown1[4];							// 0x001C
		char unknown2[4];							// 0x0020 5 bytes so probably a struct
		bool unknown3;								// 0x0024
		int16_t mouseXPosition;						// 0x0025
		int16_t mouseYPosition;						// 0x0027
		char unknown4[3];							// 0x0029 Maybe padding
		int unknown5;								// 0x002C
		char unknown6[4];							// 0x0030
		char unknown7[4];							// 0x0034
		char unknown8[4];							// 0x0038
		int8_t unknown13;							// 0x003C
		char unknown9[3];							// 0x003D
		void* HKL;									// 0x0040
		char unknown10[24];							// 0x0044
		void* TCandidateStrArr;						// 0x005C
		char unknown11[4];							// 0x0060
		char unknown12[676];						// 0x0064
	};
	static_assert(sizeof(TLBSWidgetHandler) == 0x308, "TLBSWidgetHandler size isn't 0x308.");
	static_assert(sizeof(TLBSWidgetHandler) <= 0x308, "TLBSWidgetHandler size is upper than 0x308.");
	static_assert(sizeof(TLBSWidgetHandler) >= 0x308, "TLBSWidgetHandler size is lower than 0x308.");
#pragma pack(pop)
}