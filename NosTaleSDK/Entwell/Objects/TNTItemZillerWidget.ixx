module;
#include <stdint.h>
export module TNTItemZillerWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemZillerWidget : public TEWCustomFormWidget
	{
		char unknown21[4];						//0xBC
		struct TEWLabels* allLabels;					//0xC0
		struct TNTIconWidget* eqIcon;					//0xC4
		struct TNTIconWidget* goldIcon;				//0xC8
		struct TNTIconWidget* cellaIcon;				//0xCC
		char unknown22[8];						//0xD0
		void* eqItem;				//0xD8
		char unknown23[32];						//0xDC
		void* unknown24;						//0xFC
		char unknown25[24];						//0x100
		void* goldItem;			//0x118
		uint16_t goldItemId;					//0x11C
		char unknown26[58];						//0x11E
		void* cellaItem;			//0x158
		uint16_t cellaItemId;					//0x15C
		char unknown27[50];						//0x15E
		struct TEWGraphicButtonWidget* betBtn;			//0x190
		uint32_t currentGoldAmount;				//0x194
		char unknown29[4];						//0x198
	};
	static_assert(sizeof(TNTItemZillerWidget) == 0x19C, "TNTItemZillerWidget does not have a size of 0x19C.");
#pragma pack(pop)
}