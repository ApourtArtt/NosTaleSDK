module;
export module TNTCommonInfoBoard;
import TEWFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCommonInfoBoard : public TEWFormWidget
	{
		char unknown25[4];						// 0xC4
		struct TEWStringListView* description;			// 0xC8
		struct TEWControlWidgetEX* charIconBg;			// 0xCC visible only for char
		struct TNTIconViewer* itemImg;					// 0xD0
		struct TEWControlWidgetEX* iconBg;				// 0xD4 invisible for item/entity
		struct TNTIconWidget* carveRuneImg;			// 0xD8
		struct TEWLabel* carveRuneQuantity;			// 0xDC
		struct TEWLabel* carveRuneDamage;				// 0xE0
		char unknown26[4];						// 0xE4
		struct TNTItemList* unknown27;					// 0xE8
		char unknown28[0x158];					// 0xEC
		struct TNTIconWidget* unknown29;				// 0x244
		struct TNTIconWidget* unknown30;				// 0x248
		struct TNTIconWidget* unknown31;				// 0x24C
		struct TNTIconWidget* unknown32;				// 0x250
		struct TNTIconWidget* unknown33;				// 0x254
		struct TNTIconWidget* unknown34;				// 0x258
		struct TNTIconWidget* unknown35;				// 0x25C
		struct TNTIconWidget* unknown36;				// 0x260
		struct TNTIconWidget* unknown37;				// 0x264
		struct TNTIconWidget* unknown38;				// 0x268
		struct TEWScrollBarTrack* scrollBarTrack;		// 0x26C
		struct TEWGraphicButtonWidget* closeBtn;		// 0x270
		char unknown39[0xC];					// 0x274
	};
	static_assert(sizeof(TNTCommonInfoBoard) == 0x280, "TNTCommonInfoBoard does not have a size of 0x280.");
#pragma pack(pop)
}