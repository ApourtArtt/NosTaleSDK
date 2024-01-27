module;
#include <stdint.h>
export module TNTCommonInfoBoard;
import TEWFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
	class TEWStringListView;
	class TEWControlWidgetEX;
	class TNTIconViewer;
	class TNTIconWidget;
	class TEWLabel;
	class TNTItemList;
	class TEWScrollBarTrack;
	class TEWGraphicButtonWidget;

#pragma pack(push, 1)
	export struct TNTCommonInfoBoard : public TEWFormWidget
	{
		char unknown25[4];						// 0xC4
		TEWStringListView* description;			// 0xC8
		TEWControlWidgetEX* charIconBg;			// 0xCC visible only for char
		TNTIconViewer* itemImg;					// 0xD0
		TEWControlWidgetEX* iconBg;				// 0xD4 invisible for item/entity
		TNTIconWidget* carveRuneImg;			// 0xD8
		TEWLabel* carveRuneQuantity;			// 0xDC
		TEWLabel* carveRuneDamage;				// 0xE0
		char unknown26[4];						// 0xE4
		TNTItemList* unknown27;					// 0xE8
		char unknown28[0x158];					// 0xEC
		TNTIconWidget* unknown29;				// 0x244
		TNTIconWidget* unknown30;				// 0x248
		TNTIconWidget* unknown31;				// 0x24C
		TNTIconWidget* unknown32;				// 0x250
		TNTIconWidget* unknown33;				// 0x254
		TNTIconWidget* unknown34;				// 0x258
		TNTIconWidget* unknown35;				// 0x25C
		TNTIconWidget* unknown36;				// 0x260
		TNTIconWidget* unknown37;				// 0x264
		TNTIconWidget* unknown38;				// 0x268
		TEWScrollBarTrack* scrollBarTrack;		// 0x26C
		TEWGraphicButtonWidget* closeBtn;		// 0x270
		char unknown39[0xC];					// 0x274
	};
	static_assert(sizeof(TNTCommonInfoBoard) == 0x280, "TNTCommonInfoBoard does not have a size of 0x280.");
#pragma pack(pop)
}