module;
#include <stdint.h>
export module TEWControlWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

	export struct TEWControlWidget : public TLBSWidget
	{
		char unknown3[28];			// 0x0024
		// 0x38 4 bytes : address for keyboard ?
		uint8_t unknown4;			// 0x0040
		char widgetBgra[0x04];			// 0x0041 //BGRA
		char unknown5[3];			// 0x0045
		uint16_t unknown6;			// 0x0048
		uint16_t unknown7;			// 0x004A
		bool unknown8;				// 0x004C
		int8_t currentPictureViewIndex;// 0x004D
		int8_t unknown9;			// 0x004E probably currentPictureViewIndex being 2 bytes
		char imageData[14];		// 0x004F //ImageData.h
		char unknown10;				// 0x005D
		int16_t unknown11;			// 0x005E
		int32_t functionArgument;	// 0x0060 Probably some callbacks. Don't touch it while we don't need it
		int32_t unknown12;			// 0x0064
	};
	static_assert(sizeof(TEWControlWidget) == 0x68, "TEWControlWidget does not have a size of 0x68.");
#pragma pack(pop)
}