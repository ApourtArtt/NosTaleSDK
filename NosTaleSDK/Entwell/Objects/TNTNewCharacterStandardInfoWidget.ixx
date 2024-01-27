module;
#include <stdint.h>
export module TNTNewCharacterStandardInfoWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
	static constexpr int PARTNER_ARRAY_SIZE = 12;
	static constexpr int PET_ARRAY_SIZE = 10;

#pragma pack(push, 1)
	export struct TNTNewCharacterStandardInfoWidget : public TEWCustomFormWidget
	{
		char pad_00BC[4];									//0x00BC
		struct TEWGraphicButtonWidget* questionMarkButton;			//0x00C0 
		struct TEWGraphicButtonWidget* closeButton;				//0x00C4 
		struct TEWGraphicButtonWidget* nosmateCollectionButton;	//0x00C8
		struct TEWControlWidgetEX* nameControlWidgetEx;			//0x00CC
		struct TEWControlWidgetEX* levelControlWidgetEx;			//0x00D0
		struct TEWControlWidgetEX* reputationControlWidgetEx;		//0x00D4
		struct TEWControlWidgetEX* hpControlWidgetEx;				//0x00D8
		struct TEWControlWidgetEX* mpControlWidgetEx;				//0x00DC
		struct TEWLabels* coloredLabels;							//0x00E0
		struct TEWLabels* playerInfoLabels;						//0x00E4
		struct TEWControlWidgetEX* weaponControlWidgetEx;			//0x00E8
		struct TEWControlWidgetEX* armorControlWidgetEx;			//0x00EC
		struct TEWControlWidgetEX* hatControlWidgetEx;				//0x00F0
		struct TEWControlWidgetEX* glovesControlWidgetEx;			//0x00F4
		struct TEWControlWidgetEX* shoesControlWidgetEx;			//0x00F8
		struct TEWControlWidgetEX* secondWeaponControlWidgetEx;	//0x00FC
		struct TEWControlWidgetEX* necklaceControlWidgetEx;		//0x0100
		struct TEWControlWidgetEX* ringControlWidgetEx;			//0x0104
		struct TEWControlWidgetEX* braceletControlWidgetEx;		//0x0108
		struct TEWControlWidgetEX* maskControlWidgetEx;			//0x010C
		struct TEWControlWidgetEX* fairyControlWidgetEx;			//0x0110
		struct TEWControlWidgetEX* amuletControlWidgetEx;			//0x0114
		struct TEWControlWidgetEX* spControlWidgetEx;				//0x0118
		struct TEWControlWidgetEX* costumeControlWidgetEx;			//0x011C
		struct TEWControlWidgetEX* costumeHatControlWidgetEx;		//0x0120
		struct TEWControlWidgetEX* weaponCostumeControlWidgetEx;	//0x0124
		struct TEWControlWidgetEX* wingsCostumeControlWidgetEx;	//0x0128
		struct TEWControlWidgetEX* minipetControlWidgetEx;			//0x012C
		struct TNTIconWidget* weaponIconWidget;					//0x0130
		struct TNTIconWidget* armorIconWidget;						//0x0134
		struct TNTIconWidget* hatIconWidget;						//0x0138
		struct TNTIconWidget* glovesIconWidget;					//0x013C
		struct TNTIconWidget* shoesIconWidget;						//0x0140
		struct TNTIconWidget* secondWeaponIconWidget;				//0x0144
		struct TNTIconWidget* necklaceIconWidget;					//0x0148
		struct TNTIconWidget* ringIconWidget;						//0x014C
		struct TNTIconWidget* braceletIconWidget;					//0x0150
		struct TNTIconWidget* maskIconWidget;						//0x0154
		struct TNTIconWidget* fairyIconWidget;						//0x0158
		struct TNTIconWidget* amuletIconWidget;					//0x015C
		struct TNTIconWidget* spIconWidget;						//0x0160
		struct TNTIconWidget* customeIconWidget;					//0x0164
		struct TNTIconWidget* costumeHatIconWidget;				//0x0168
		struct TNTIconWidget* weaponCostumeIconWidget;				//0x016C
		struct TNTIconWidget* wingsCostumeIconWidget;				//0x0170
		struct TNTIconWidget* minipetIconWidget;					//0x0174
		struct TEWCustomPanelWidget* statisticsCustomPanel;		//0x0178
		struct TNTItemList* uknownList;							//0x017C
		struct TNTIconWidget* petIconWidgets[PET_ARRAY_SIZE];		//0x0180
		struct TEWGraphicButtonWidget* characterHeadButton;		//0x01A8
		struct TEWGraphicButtonWidget* partnerHeadButton[PARTNER_ARRAY_SIZE]; //0x01AC
		struct TEWGraphicButtonWidget* petHeadButton[PET_ARRAY_SIZE]; //0x01DC
		struct TNTItemList* uknownList_2;							//0x0204
		struct TNTIconWidget* characterHeadIconWidget;				//0x0208
		struct TNTIconWidget* partnerHeadIconWidget[PARTNER_ARRAY_SIZE]; //0x020C
		struct TNTItemList* uknownList_3;							//0x023C
		struct TNTIconWidget* weaponStatIconWidget_1;				//0x0240
		struct TNTIconWidget* weaponStatIconWidget_2;				//0x0244
		struct TNTIconWidget* characterStatSpacer_1;				//0x0248
		struct TNTIconWidget* secondWeaponStatIconWidget_1;		//0x024C
		struct TNTIconWidget* secondWeaponStatIconWidget_2;		//0x0250
		struct TNTIconWidget* characterStatSpacer_2;				//0x0254
		struct TNTIconWidget* defenseStatIconWidget;				//0x0258
		struct TNTIconWidget* meleeDefenseStatIconWidget;			//0x025C
		struct TNTIconWidget* rangeDefenseStatIconWidget;			//0x0260
		struct TNTIconWidget* magicDefenseStatIconWidget;			//0x0264
		struct TNTIconWidget* fairyElementStatIconWidget;			//0x0268
		struct TNTIconWidget* fireResistanceIconWidget;			//0x026C
		struct TNTIconWidget* waterResistanceIconWidget;			//0x0270
		struct TNTIconWidget* lghtResistanceIconWidget;			//0x0274
		struct TNTIconWidget* shadowResistanceIconWidget;			//0x0278
		struct TEWControlWidgetEX* ereniaMedalControlWidgetEx;		//0x027C
		struct TEWControlWidgetEX* adventurerMedalControlWidgetEx; //0x0280
		struct TEWControlWidgetEX* expertOrderMedalControlWidgetEx; //0x0284 
		struct TEWControlWidgetEX* friendshipMedalControlWidgetEx; //0x0288
		struct TEWControlWidgetEX* weirdQuestionMarkControlWidgetEx; //0x028C 
		struct TEWControlWidgetEX* uknownControlWidgetEx_1;		//0x0290
		struct TEWControlWidgetEX* uknownControlWidgetEx_2;		//0x0294
		struct TEWControlWidgetEX* uknownControlWidgetEx_3;		//0x0298 
		struct TNTIconWidget* uknownIconWidget_3;					//0x029C
		struct TNTIconWidget* uknownIconWidget_4;					//0x02A0
		struct TNTIconWidget* uknownIconWidget_5;					//0x02A4
		struct TNTIconWidget* uknownIconWidget_6;					//0x02A8
		struct TNTIconWidget* uknownIconWidget_7;					//0x02AC
		struct TNTIconWidget* uknownIconWidget_8;					//0x02B0
		struct TNTIconWidget* uknownIconWidget_9;					//0x02B4
		struct TNTIconWidget* uknownIconWidget_10;					//0x02B8
		struct TNTIconWidget* reputationIconWidget;				//0x02BC
		int32_t classType;									//0x02C0 0 = adventurer, 1 = swordie, 2 = archer, 3 = mage
		int32_t gender;										//0x02C4 0 = male, 1 = female
		char* className;									//0x02C8
		int32_t currentSelectedTabIndex;					//0x02CC
		int32_t currentSelectedPartnerIndex;				//0x02D0
		int32_t currentSelectedPetIndex;					//0x02D4
		struct TEWGraphicButtonWidget* characterTabButton; //0x02CC 
		struct TEWGraphicButtonWidget* questTabButton; //0x02D0 
		struct TEWGraphicButtonWidget* familyTabButton; //0x02D4 
		struct TEWGraphicButtonWidget* actTabButton; //0x02D8 
		struct TEWGraphicButtonWidget* storyTabButton; //0x02DC 
		struct TEWGraphicButtonWidget* titleTabButton; //0x02E0 
		struct TEWGraphicButtonWidget* celestialTowerTabButton; //0x02E4 
		struct TEWControlWidgetEX* characterControlWidgetEx_Unused; //0x02E8 
		struct TEWControlWidgetEX* questControlWidgetEx_Unused; //0x02EC 
		struct TEWControlWidgetEX* familyControlWidgetEx_Unused; //0x02F0 
		struct TEWControlWidgetEX* actControlWidgetEx_Unused; //0x02F4 
		struct TEWControlWidgetEX* storyControlWidgetEx_Unused; //0x02F8 
		struct TEWControlWidgetEX* uknownControlWidgetEx_4; //0x02FC 
		struct TEWControlWidgetEX* uknownControlWidgetEx_5; //0x0300 
		struct TEWLabel* characterTabLabel; //0x0304 
		struct TEWLabel* questTabLabel; //0x0308
		struct TEWLabel* familyTabLabel; //0x030C
		struct TEWLabel* actTabLabel; //0x0310
		struct TEWLabel* storyTabLabel; //0x0314
		struct TEWLabel* titleTabLabel; //0x0318
		struct TEWLabel* celestialTowerTabLabel; //0x031C
		struct TEWLabels* partnerInfoLabels; //0x0320 
		struct TEWCustomPanelWidget* aPartnerCustomPanelWidgetsX[PARTNER_ARRAY_SIZE]; //0x0324 The blue X on the partner icon
		char aPartnerSpSkillIconWidget[0xC * PARTNER_ARRAY_SIZE]; //0x0354 Equipment, resistance and skills
		struct TEWCustomPanelWidget* aPartnerCustomPanelWidgets[PET_ARRAY_SIZE]; //0x03E4 From here there are additional custom panels for each slot
		struct TNTIconWidget* aPartnerSpIconWidget[PARTNER_ARRAY_SIZE]; //0x040C 
		struct TNTItemList* uknownList_4; //0x043C 
		struct TNTItemList* uknownList_5; //0x0440
		struct TNTItemList* uknownList_6; //0x0444
		struct TEWControlWidgetEX* partnerSpControlWidgetEx; //0x0448
		struct TEWControlWidgetEX* partnerSpBorderEffectControlWidgetEx; //0x044C
		char pad_0450[12]; //0x0450
		struct TEWButtonWidget* partnerPersonalityButton; //0x045C 
		struct TEWButtonWidget* partnerSilenceButton; //0x0460 
		struct TEWButtonWidget* partnerNormalStateButton; //0x0464 
		struct TEWButtonWidget* partnerSpeakButton; //0x0468 
		struct TEWGraphicButtonWidget* partnerPersonalityArrowButton; //0x046C 
		char pad_0470[4]; //0x0470
		char aPartnerSpSkillLevel[0xC * PARTNER_ARRAY_SIZE]; //0x0474
		char aPartnerSkills[0x8 * PARTNER_ARRAY_SIZE]; //0x0504 
		char aPartnerSkillsAutomaticButtons[0xC * PARTNER_ARRAY_SIZE]; //0x0564
		char aPartnerEquipmentIcons[0x8 * PARTNER_ARRAY_SIZE]; //0x05F4
		char aPartnerResistanceIcons[0x8 * PARTNER_ARRAY_SIZE]; //0x0654
		struct TNTIconWidget* partnerAttackStatIconWidget_1; //0x06B4 
		struct TNTIconWidget* partnerAttackStatIconWidget_2; //0x06B8 
		struct TNTIconWidget* partnerUknownIconWidget_1; //0x06BC 
		struct TNTIconWidget* partnerDefenseStatIconWidget; //0x06C0 
		struct TNTIconWidget* partnerMeleeDefenseStatIconWidget; //0x06C4 
		struct TNTIconWidget* partnerRangeDefenseStatIconWidget; //0x06C8 
		struct TNTIconWidget* partnerMagicDefenseStatIconWidget; //0x06CC 
		struct TNTIconWidget* partnerElementStatIconWidget; //0x06D0 
		struct TNTIconWidget* partnerFireResistanceIconWidget; //0x06D4 
		struct TNTIconWidget* partnerWaterResistanceIconWidget; //0x06D8 
		struct TNTIconWidget* partnerLightResistanceIconWidget; //0x06DC 
		struct TNTIconWidget* partnerShadowResistanceIconWidget; //0x06E0 
		struct TNTItemList* uknownList_7; //0x06E4 
		struct TNTItemList* uknownList_8; //0x06E8
		struct TEWLabels* petInfoLabels; //0x06EC 
		struct TNTCommonInfoBoard* TNTCommonInfoBoardPtr; //0x06F0 
		struct TNTIconWidget* petAttackStatIconWidget_1; //0x06F4 
		struct TNTIconWidget* petAttackStatIconWidget_2; //0x06F8 
		struct TNTIconWidget* petSpacerStatIconWidget; //0x06FC 
		struct TNTIconWidget* petDefenseStatIconWidget; //0x0700 
		struct TNTIconWidget* petMeleeDefenseStatIconWidget; //0x0704 
		struct TNTIconWidget* petRangeDefenseStatIconWidget; //0x0708 
		struct TNTIconWidget* petMagicDefenseStatIconWidget; //0x070C 
		struct TNTIconWidget* petElementIconWidget; //0x0710 
		struct TNTIconWidget* petFireResistanceIconWidget; //0x0714 
		struct TNTIconWidget* petWaterResistanceIconWidget; //0x0718 
		struct TNTIconWidget* petLightResistanceIconWidget; //0x071C 
		struct TNTIconWidget* petShadowResistanceIconWidget; //0x0720 
		struct TNTActInfoWidget* TNTActInfoWidgetPtr; //0x0724 
		struct TNTNewFamilyInfoWidget* TNTNewFamilyInfoWidgetPtr; //0x0728 
		char aPetInformation[0xA8 * PET_ARRAY_SIZE]; //0x072C
		char aPetInformation_2[0xA8 * PET_ARRAY_SIZE]; //0x0DBC
		char pad_144C[13040]; //0x144C
		int32_t currentPetList; //0x473C
		int32_t maxPetList; //0x4740
		struct TEWGraphicButtonWidget* petListLeftButton; //0x4744 
		struct TEWGraphicButtonWidget* petListRightButton; //0x4748 
		struct TEWLabel* petListLabel; //0x474C 
		char pad_4750[4]; //0x4750
		struct TEWGraphicButtonWidget* invokeButtonList[PET_ARRAY_SIZE + PARTNER_ARRAY_SIZE]; //0x4754 
		struct TEWCustomPanelWidget* leftPanel; //0x47AC 
		struct TEWCustomPanelWidget* centerPanel; //0x47B0
		struct TEWCustomPanelWidget* rightPanel; //0x47B4
		char pad_47B8[4]; //0x47B8
		struct TEWControlWidgetEX* characterSpLightEffect; //0x47BC 
		struct TEWControlWidgetEX* characterSpLightEffect_2; //0x47C0 
		uint32_t effectStatus; //0x47C4
		char pad_47C8[12]; //0x47C8
		struct TNTStoryInfoWidget* TNTStoryInfoWidgetPtr; //0x47D4 
		struct TNTQuestInfoWidget* TNTQuestInfoWidgetPtr; //0x47D8 
		struct TNTGroupInfoWidget* TNTGroupInfoWidgetPtr; //0x47DC 
		struct TNTTitleInfoWidget* TNTTitleInfoWidgetPtr; //0x47E0 
		int32_t entityIndex; //0x47E4
		char aPartnerInformation[0xCF * PARTNER_ARRAY_SIZE]; //0x47E8
		char unknown[0x5A58]; //0x519C
	};
	static_assert(sizeof(TNTNewCharacterStandardInfoWidget) == 0xAC00, "TNTNewCharacterStandardInfoWidget does not have a size of 0xAC00");
#pragma pack(pop)
}