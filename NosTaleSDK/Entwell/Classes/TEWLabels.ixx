module;
#include <stdint.h>
export module TEWLabels;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWLabels : public TEWControlWidgetEX
	{
		bool unknown13;						// 0x68 Common with the textPositionBytes 0x00 offset
		char unknown14;						// 0x69
		int16_t nbLines;					// 0x6A Common with the textPositionBytes 0x04 offset + Seems like an int8_t and then an unknown
		bool applyStyle;					// 0x6C
		char commonTextStyle[0x0B];			// 0x6D
		// Maybe a class for those following 4 int16_t. If not, then still use a TextPosition and assign its members to the variables
		int16_t pxBeforeTextX;				// 0x78
		int16_t pxBeforeTextY;				// 0x7A
		int16_t x;							// 0x7C
		int16_t y;							// 0x7E
		void* textStylePtr;			// 0x80
		void* textPositionArrayPtr;	// 0x84 Ptr to TextPosition array
	};
	static_assert(sizeof(TEWLabels) == 0x88, "TEWLabels does not have a size of 0x88.");
#pragma pack(pop)
}