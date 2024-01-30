module;
#include <stdint.h>
export module TNTStarPetWidget;
import TEWCustomFormWidget;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	struct TNTStarPetWidget : public TEWCustomFormWidget
	{
		char unknown99[4];							// 0x0BC
		uint32_t unknown100;						// 0x0C0
		uint32_t unknown101;						// 0x0C4
		uint32_t unknown102;						// 0x0C8
		uint32_t unknown103;						// 0x0CC
		struct TEWLabel* unknown104;				// 0x0D0
		struct TEWCustomPanelWidget* unknown105;	// 0x0D4
		struct TEWScrollBar* unknown106;			// 0x0D8
		char unknown107[36];						// 0x0DC
		struct TList<void*>* unknown108;			// 0x100
		struct TList<void*>* unknown109;			// 0x104
		uint8_t unknown110;							// 0x108
		uint8_t unknown111;							// 0x109
		uint16_t unknown112;						// 0x10A
		struct TEWNormalButtonWidget* unknown113;	// 0x10C
		struct TEWListView* unknown114;				// 0x110
		char unknown115[2916];						// 0x114
		uint32_t unknown116;						// 0xC78
		char unknown117[36];						// 0xC7C
		struct TEWGraphicButtonWidget* unknown118;	// 0xCA0
		uint8_t unknown119;							// 0xCA4
		char unknown120[3];							// 0xCA5
		struct TEWCustomPanelWidget* unknown121;	// 0xCA8
		struct TEWLabel* unknown122;				// 0xCAC
		struct TEWLabel* unknown123;				// 0xCB0
		struct TEWLabel* unknown124;				// 0xCB4
		struct TEWCustomPanelWidget* unknown125;	// 0xCB8
		struct TEWScrollBar* unknown126;			// 0xCBC
		char unknown127[36];						// 0xCC0
		struct TList<void*>* unknown128;			// 0xCE4
		struct TList<void*>* unknown129;			// 0xCE8
		char unknown130[36];						// 0xCEC
		uint8_t unknown131;							// 0xD10
		uint8_t unknown132;							// 0xD11
		uint16_t unknown133;						// 0xD12
		struct TEWListView* unknown134;				// 0xD14
		char unknown135[252];						// 0xD18
		uint8_t unknown136;							// 0xE14
		char unknown137[3];							// 0xE15
		uint32_t unknown138;						// 0xE18
		char unknown139[12];						// 0xE1C
	};
	static_assert(sizeof(TNTStarPetWidget) == 0xE28, "TNTStarPetWidget size isn't 0xE28.");
	static_assert(sizeof(TNTStarPetWidget) <= 0xE28, "TNTStarPetWidget size is upper than 0xE28.");
	static_assert(sizeof(TNTStarPetWidget) >= 0xE28, "TNTStarPetWidget size is lower than 0xE28.");
#pragma pack(pop)
}