module;
#include <stdint.h>
export module TNTPartySummaryInfoWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTPartySummaryInfoWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];														// 0x0A4
		struct TEWLabel* level;													// 0x0A8
		struct TEWLabel* pseudonym;												// 0x0AC
		struct TNTMaskingGaugeWidget* gaugeHp;									// 0x0B0
		struct TNTMaskingGaugeWidget* gaugeMp;									// 0x0B4
		struct TNTItemList* unknown31;											// 0x0B8
		uint8_t unknown32;														// 0x0BC
		char unknown33[3];														// 0x0BD
		struct TPetSelectIcon* firstPartyMemberImage;							// 0x0C0
		struct TEWControlWidgetEX* firstPartyMemberGreenCircle;					// 0x0C4
		struct TEWControlWidgetEX* firstPartyMemberTargetCircle;				// 0x0C8
		struct TEWControlWidgetEX* firstPartyMemberUnusedImage;					// 0x0CC
		bool isFirstPartyMemberFollow;											// 0x0D0
		bool isFirstPartyMemberControlled;										// 0x0D1
		char unknown34[2];														// 0x0D2
		struct TEWControlWidgetEX* firstPartyMemberPowerSeed;					// 0x0D4
		struct TEWGraphicButtonWidget* firstPartyMemberBag;						// 0x0D8
		char unknown35[4];														// 0x0DC
		uint8_t unknown36;														// 0x0E0 1 = player 2 = pet 3 = partner
		uint8_t firstPartyMemberEntityType;										// 0x0E1 1 = player 3 = pet/player
		char unknown37[2];														// 0x0E2
		int32_t firstPartyMemberEntityId;										// 0x0E4
		bool isFirstPartyMemberPet;												// 0x0E8
		char unknown38[3];														// 0x0E9
		struct TNTIconWidget* firstPartyMemberBuffIcons[8];						// 0x0EC
		char unknown39[4];														// 0x10C
		struct TNTGraphicButtonAtSpecialCard2* firstPartyMemberSpButton;		// 0x110
	};
	static_assert(sizeof(TNTPartySummaryInfoWidget) == 0x114, "TNTPartySummaryInfoWidget size isn't 0x114.");
	static_assert(sizeof(TNTPartySummaryInfoWidget) <= 0x114, "TNTPartySummaryInfoWidget size is upper than 0x114.");
	static_assert(sizeof(TNTPartySummaryInfoWidget) >= 0x114, "TNTPartySummaryInfoWidget size is lower than 0x114.");
#pragma pack(pop)
}