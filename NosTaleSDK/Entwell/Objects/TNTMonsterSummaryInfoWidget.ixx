module;
#include <stdint.h>
export module TNTMonsterSummaryInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMonsterSummaryInfoWidget : public TEWCustomFormWidget
	{
		char pad_00BC[4]; //0x00BC
		struct TEWControlWidgetEX* oldHeadCircle; //0x00C0
		TEWCustomPanelWidget* widgetPanel; //0x00C4
		struct TEWLabel* levelLabel; //0x00C8
		char pad_00CC[12]; //0x00CC
		struct TEWLabel* nameLabel; //0x00D8
		char pad_00DC[32]; //0x00DC
		struct TNTMaskingGaugeWidget* gaugeHp; //0x00FC
		struct TNTMaskingGaugeWidget* gaugeMp; //0x0100
		struct TNTIconWidget* entityTypeIcon; //0x0104
		struct TNTIconWidget* elementIcon; //0x0108
		struct TNTIconWidget* isCapturableIcon; //0x010C
		char pad_0110[4]; //0x0110
		uint32_t uknownList_1; //0x0114 TNTItemList
		struct TEWCustomPanelWidget* capturablePanel; //0x0118 Not used by default
		struct TEWGraphicButtonWidget* displayMenuButton; //0x011C
		struct TEWButtonWidget* partyButton; //0x0120
		struct TEWButtonWidget* whisperButton; //0x0124
		struct TEWButtonWidget* tradeButton; //0x0128
		struct TEWButtonWidget* friendButton; //0x012C
		struct TEWButtonWidget* companyButton; //0x0130
		struct TEWButtonWidget* stayButton; //0x0134
		struct TEWButtonWidget* sendBackButton; //0x0138
		struct TEWButtonWidget* blacklistButton; //0x013C
		struct TEWButtonWidget* commendButton; //0x0140
		int32_t entityType; //0x0144 Not sure at all (1 = player, 2 = monster, 3 = npc, 4 = ?, 5 = allie/partner/pet
		TNTIconWidget* oldHeadIcon; //0x0148
		int32_t targetID; //0x014C It sometimes change with certain types of entities
		struct TEWGraphicButtonWidget* closeButton; //0x0150
		uint8_t isMenuVisible; //0x0154
		char pad_0155[3]; //0x0155
		int16_t reputationRankID; //0x0158 Max should be 32
		char pad_015A[2]; //0x015A
		wchar_t* targetName; //0x015C
		char pad_0160[4]; //0x0160
		struct TEWControlWidgetEX* factionSideControlWidget; //0x0164
		uint16_t uknown_var_1; //0x0168
		uint16_t uknown_var_2; //0x016A Used when you click on the whisper button to open the chat
		struct TNTChatEditWidget* chatEditWidget; //0x016C
		struct TNTIconWidget* buffIcons[8]; //0x0170
	};
	static_assert(sizeof(TNTMonsterSummaryInfoWidget) == 0x190, "TNTMonsterSummaryInfoWidget does not have a size of 0x190");
#pragma pack(pop)
}