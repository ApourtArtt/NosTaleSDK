module;
#include <stdint.h>
export module TNTPartySummaryInfoWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTPartySummaryInfoWidget : public TEWCustomPanelWidget
	{
		char unknown19[4]; // 0xA4
		struct TEWLabel* labelLevel; // 0xA8
		struct TEWLabel* labelPseudonym; // 0xAC
		struct TNTMaskingGaugeWidget* gaugeHp; // 0xB0
		struct TNTMaskingGaugeWidget* gaugeMp; // 0xB4
		struct TNTItemList* itemListUnknown; // 0xB8
		char unknown20[4]; // 0xBC
		void* TPetSelectIcon; // 0xC0 (pet image)
		struct TEWControlWidgetEX* greenCircle; // 0xC4
		struct TEWControlWidgetEX* topLeftImage; // 0xC8
		struct TEWControlWidgetEX* bottomLeftImageRemoved; // 0xCC
		char unknown21[4]; // 0xD0 triggered on click
		struct TEWControlWidgetEX* bottomLeftImage; // 0xD4
		struct TEWGraphicButtonWidget* topRightButton; // 0xD8
		char unknown22[4]; // 0xDC
		char ignoreForNow; // 0xE0 1 = player 2 = pet 3 = partner
		char entityType; // 0xE1 note: not really entityType, so not of type EntityType (mate = 3 instead of 2)
		char unknown23[2]; // 0xE2
		int32_t entityId; // 0xE4
		char unknown24[4]; // 0xE8
		struct TNTIconWidget* buff1; // 0xEC
		struct TNTIconWidget* buff2; // 0xF0
		struct TNTIconWidget* buff3; // 0xF4
		struct TNTIconWidget* buff4; // 0xF8
		struct TNTIconWidget* buff5; // 0xFC
		struct TNTIconWidget* buff6; // 0x100
		struct TNTIconWidget* buff7; // 0x104
		struct TNTIconWidget* buff8; // 0x108
		char unknown25[4]; // 0x10C
		void* TNTGraphicButtonAtSpecialCard; // 0x110 SP button
	};
	static_assert(sizeof(TNTPartySummaryInfoWidget) == 0x114, "TNTPartySummaryInfoWidget does not have a size of 0x114");
#pragma pack(pop)
}