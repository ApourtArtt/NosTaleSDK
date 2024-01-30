module;
#include <stdint.h>
export module TNTMonsterSummaryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMonsterSummaryInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];										// 0x0BC
		struct TEWControlWidgetEX* oldHeadCircle;				// 0x0C0
		struct TEWCustomPanelWidget* background;				// 0x0C4
		struct TEWLabel* level;									// 0x0C8
		char unknown39[12];										// 0x0CC
		struct TEWLabel* name;									// 0x0D8
		char unknown40[32];										// 0x0DC
		struct TNTMaskingGaugeWidget* gaugeHp;					// 0x0FC
		struct TNTMaskingGaugeWidget* gaugeMp;					// 0x100
		struct TNTIconWidget* entityTypeIcon;					// 0x104
		struct TNTIconWidget* elementIcon;						// 0x108
		struct TNTIconWidget* isCapturableIcon;					// 0x10C
		char unknown41[4];										// 0x110
		struct TNTItemList* unknown42;							// 0x114 
		struct TEWCustomPanelWidget* capturablePanel;			// 0x118
		struct TEWGraphicButtonWidget* displayMenuButton;		// 0x11C
		struct TEWButtonWidget* partyButton;					// 0x120
		struct TEWButtonWidget* whisperButton;					// 0x124
		struct TEWButtonWidget* tradeButton;					// 0x128
		struct TEWButtonWidget* friendButton;					// 0x12C
		struct TEWButtonWidget* companyButton;					// 0x130
		struct TEWButtonWidget* stayButton;						// 0x134
		struct TEWButtonWidget* sendBackButton;					// 0x138
		struct TEWButtonWidget* blacklistButton;				// 0x13C
		struct TEWButtonWidget* commendButton;					// 0x140
		int32_t entityType;										// 0x144 1 = player, 2 = monster, 3 = npc, 4 = ?, 5 = allie/partner/pet
		struct TNTIconWidget* oldHeadIcon;						// 0x148
		int32_t targetID;										// 0x14C
		struct TEWGraphicButtonWidget* closeButton;				// 0x150
		bool isMenuVisible;										// 0x154
		char unknown43[3];										// 0x155
		int16_t reputationRankID;								// 0x158
		char unknown44[2];										// 0x15A
		wchar_t* targetName;									// 0x15C
		char unknown45[4];										// 0x160
		struct TEWControlWidgetEX* factionSideControlWidget;	// 0x164
		uint16_t unknown46;										// 0x168
		uint16_t unknown47;										// 0x16A Used when you click on the whisper button to open the chat
		struct TNTChatEditWidget* chatEditWidget;				// 0x16C
		struct TNTIconWidget* buffIcons[30];					// 0x170
	};
	static_assert(sizeof(TNTMonsterSummaryInfoWidget) == 0x1E8, "TNTMonsterSummaryInfoWidget size isn't 0x1E8.");
	static_assert(sizeof(TNTMonsterSummaryInfoWidget) <= 0x1E8, "TNTMonsterSummaryInfoWidget size is upper than 0x1E8.");
	static_assert(sizeof(TNTMonsterSummaryInfoWidget) >= 0x1E8, "TNTMonsterSummaryInfoWidget size is lower than 0x1E8.");
#pragma pack(pop)
}