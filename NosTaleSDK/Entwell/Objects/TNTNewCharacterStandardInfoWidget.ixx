module;
#include <stdint.h>
export module TNTNewCharacterStandardInfoWidget;
import TEWCustomFormWidget;
import TEWGraphicButtonWidget;
import TEWControlWidgetEX;
import TEWLabels;
import TNTCoverIcon;
import TNTIconWidget;
import TNTItemList;
import TEWLabel;
import TEWButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
	static constexpr int PARTNER_ARRAY_SIZE = 12;
	static constexpr int PET_ARRAY_SIZE = 10;

	// TODO Just to make the compiler happy, need reverse
	class TNTCommonInfoBoard {};
	class TNTActInfoWidget {};
	class TNTNewFamilyInfoWidget {};
	class TNTStoryInfoWidget {};
	class TNTQuestInfoWidget {};
	class TNTGroupInfoWidget {};
	class TNTTitleInfoWidget {};
#pragma pack(push, 1)
	export struct TNTNewCharacterStandardInfoWidget : public TEWCustomFormWidget
	{
		// TODO: Find uknown values


		char pad_00BC[4];									//0x00BC
		TEWGraphicButtonWidget* questionMarkButton;			//0x00C0 
		TEWGraphicButtonWidget* closeButton;				//0x00C4 
		TEWGraphicButtonWidget* nosmateCollectionButton;	//0x00C8
		TEWControlWidgetEX* nameControlWidgetEx;			//0x00CC
		TEWControlWidgetEX* levelControlWidgetEx;			//0x00D0
		TEWControlWidgetEX* reputationControlWidgetEx;		//0x00D4
		TEWControlWidgetEX* hpControlWidgetEx;				//0x00D8
		TEWControlWidgetEX* mpControlWidgetEx;				//0x00DC
		TEWLabels* coloredLabels;							//0x00E0
		TEWLabels* playerInfoLabels;						//0x00E4
		TEWControlWidgetEX* weaponControlWidgetEx;			//0x00E8
		TEWControlWidgetEX* armorControlWidgetEx;			//0x00EC
		TEWControlWidgetEX* hatControlWidgetEx;				//0x00F0
		TEWControlWidgetEX* glovesControlWidgetEx;			//0x00F4
		TEWControlWidgetEX* shoesControlWidgetEx;			//0x00F8
		TEWControlWidgetEX* secondWeaponControlWidgetEx;	//0x00FC
		TEWControlWidgetEX* necklaceControlWidgetEx;		//0x0100
		TEWControlWidgetEX* ringControlWidgetEx;			//0x0104
		TEWControlWidgetEX* braceletControlWidgetEx;		//0x0108
		TEWControlWidgetEX* maskControlWidgetEx;			//0x010C
		TEWControlWidgetEX* fairyControlWidgetEx;			//0x0110
		TEWControlWidgetEX* amuletControlWidgetEx;			//0x0114
		TEWControlWidgetEX* spControlWidgetEx;				//0x0118
		TEWControlWidgetEX* costumeControlWidgetEx;			//0x011C
		TEWControlWidgetEX* costumeHatControlWidgetEx;		//0x0120
		TEWControlWidgetEX* weaponCostumeControlWidgetEx;	//0x0124
		TEWControlWidgetEX* wingsCostumeControlWidgetEx;	//0x0128
		TEWControlWidgetEX* minipetControlWidgetEx;			//0x012C
		TNTIconWidget* weaponIconWidget;					//0x0130
		TNTIconWidget* armorIconWidget;						//0x0134
		TNTIconWidget* hatIconWidget;						//0x0138
		TNTIconWidget* glovesIconWidget;					//0x013C
		TNTIconWidget* shoesIconWidget;						//0x0140
		TNTIconWidget* secondWeaponIconWidget;				//0x0144
		TNTIconWidget* necklaceIconWidget;					//0x0148
		TNTIconWidget* ringIconWidget;						//0x014C
		TNTIconWidget* braceletIconWidget;					//0x0150
		TNTIconWidget* maskIconWidget;						//0x0154
		TNTIconWidget* fairyIconWidget;						//0x0158
		TNTIconWidget* amuletIconWidget;					//0x015C
		TNTIconWidget* spIconWidget;						//0x0160
		TNTIconWidget* customeIconWidget;					//0x0164
		TNTIconWidget* costumeHatIconWidget;				//0x0168
		TNTIconWidget* weaponCostumeIconWidget;				//0x016C
		TNTIconWidget* wingsCostumeIconWidget;				//0x0170
		TNTIconWidget* minipetIconWidget;					//0x0174
		TEWCustomPanelWidget* statisticsCustomPanel;		//0x0178
		TNTItemList* uknownList;							//0x017C
		TNTIconWidget* petIconWidgets[PET_ARRAY_SIZE];		//0x0180
		TEWGraphicButtonWidget* characterHeadButton;		//0x01A8
		TEWGraphicButtonWidget* partnerHeadButton[PARTNER_ARRAY_SIZE]; //0x01AC
		TEWGraphicButtonWidget* petHeadButton[PET_ARRAY_SIZE]; //0x01DC
		TNTItemList* uknownList_2;							//0x0204
		TNTIconWidget* characterHeadIconWidget;				//0x0208
		TNTIconWidget* partnerHeadIconWidget[PARTNER_ARRAY_SIZE]; //0x020C
		TNTItemList* uknownList_3;							//0x023C
		TNTIconWidget* weaponStatIconWidget_1;				//0x0240
		TNTIconWidget* weaponStatIconWidget_2;				//0x0244
		TNTIconWidget* characterStatSpacer_1;				//0x0248
		TNTIconWidget* secondWeaponStatIconWidget_1;		//0x024C
		TNTIconWidget* secondWeaponStatIconWidget_2;		//0x0250
		TNTIconWidget* characterStatSpacer_2;				//0x0254
		TNTIconWidget* defenseStatIconWidget;				//0x0258
		TNTIconWidget* meleeDefenseStatIconWidget;			//0x025C
		TNTIconWidget* rangeDefenseStatIconWidget;			//0x0260
		TNTIconWidget* magicDefenseStatIconWidget;			//0x0264
		TNTIconWidget* fairyElementStatIconWidget;			//0x0268
		TNTIconWidget* fireResistanceIconWidget;			//0x026C
		TNTIconWidget* waterResistanceIconWidget;			//0x0270
		TNTIconWidget* lghtResistanceIconWidget;			//0x0274
		TNTIconWidget* shadowResistanceIconWidget;			//0x0278
		TEWControlWidgetEX* ereniaMedalControlWidgetEx;		//0x027C
		TEWControlWidgetEX* adventurerMedalControlWidgetEx; //0x0280
		TEWControlWidgetEX* expertOrderMedalControlWidgetEx; //0x0284 
		TEWControlWidgetEX* friendshipMedalControlWidgetEx; //0x0288
		TEWControlWidgetEX* weirdQuestionMarkControlWidgetEx; //0x028C 
		TEWControlWidgetEX* uknownControlWidgetEx_1;		//0x0290
		TEWControlWidgetEX* uknownControlWidgetEx_2;		//0x0294
		TEWControlWidgetEX* uknownControlWidgetEx_3;		//0x0298 
		TNTIconWidget* uknownIconWidget_3;					//0x029C
		TNTIconWidget* uknownIconWidget_4;					//0x02A0
		TNTIconWidget* uknownIconWidget_5;					//0x02A4
		TNTIconWidget* uknownIconWidget_6;					//0x02A8
		TNTIconWidget* uknownIconWidget_7;					//0x02AC
		TNTIconWidget* uknownIconWidget_8;					//0x02B0
		TNTIconWidget* uknownIconWidget_9;					//0x02B4
		TNTIconWidget* uknownIconWidget_10;					//0x02B8
		TNTIconWidget* reputationIconWidget;				//0x02BC
		int32_t classType;									//0x02C0 0 = adventurer, 1 = swordie, 2 = archer, 3 = mage
		int32_t gender;										//0x02C4 0 = male, 1 = female
		char* className;									//0x02C8
		int32_t currentSelectedTabIndex;					//0x02CC
		int32_t currentSelectedPartnerIndex;				//0x02D0
		int32_t currentSelectedPetIndex;					//0x02D4
		TEWGraphicButtonWidget* characterTabButton; //0x02CC 
		TEWGraphicButtonWidget* questTabButton; //0x02D0 
		TEWGraphicButtonWidget* familyTabButton; //0x02D4 
		TEWGraphicButtonWidget* actTabButton; //0x02D8 
		TEWGraphicButtonWidget* storyTabButton; //0x02DC 
		TEWGraphicButtonWidget* titleTabButton; //0x02E0 
		TEWGraphicButtonWidget* celestialTowerTabButton; //0x02E4 
		TEWControlWidgetEX* characterControlWidgetEx_Unused; //0x02E8 
		TEWControlWidgetEX* questControlWidgetEx_Unused; //0x02EC 
		TEWControlWidgetEX* familyControlWidgetEx_Unused; //0x02F0 
		TEWControlWidgetEX* actControlWidgetEx_Unused; //0x02F4 
		TEWControlWidgetEX* storyControlWidgetEx_Unused; //0x02F8 
		TEWControlWidgetEX* uknownControlWidgetEx_4; //0x02FC 
		TEWControlWidgetEX* uknownControlWidgetEx_5; //0x0300 
		TEWLabel* characterTabLabel; //0x0304 
		TEWLabel* questTabLabel; //0x0308
		TEWLabel* familyTabLabel; //0x030C
		TEWLabel* actTabLabel; //0x0310
		TEWLabel* storyTabLabel; //0x0314
		TEWLabel* titleTabLabel; //0x0318
		TEWLabel* celestialTowerTabLabel; //0x031C
		TEWLabels* partnerInfoLabels; //0x0320 
		TEWCustomPanelWidget* aPartnerCustomPanelWidgetsX[PARTNER_ARRAY_SIZE]; //0x0324 The blue X on the partner icon
		PartnerSpSkillIcons aPartnerSpSkillIconWidget[PARTNER_ARRAY_SIZE]; //0x0354 Equipment, resistance and skills
		TEWCustomPanelWidget* aPartnerCustomPanelWidgets[PET_ARRAY_SIZE]; //0x03E4 From here there are additional custom panels for each slot
		TNTIconWidget* aPartnerSpIconWidget[PARTNER_ARRAY_SIZE]; //0x040C 
		TNTItemList* uknownList_4; //0x043C 
		TNTItemList* uknownList_5; //0x0440
		TNTItemList* uknownList_6; //0x0444
		TEWControlWidgetEX* partnerSpControlWidgetEx; //0x0448
		TEWControlWidgetEX* partnerSpBorderEffectControlWidgetEx; //0x044C
		char pad_0450[12]; //0x0450
		TEWButtonWidget* partnerPersonalityButton; //0x045C 
		TEWButtonWidget* partnerSilenceButton; //0x0460 
		TEWButtonWidget* partnerNormalStateButton; //0x0464 
		TEWButtonWidget* partnerSpeakButton; //0x0468 
		TEWGraphicButtonWidget* partnerPersonalityArrowButton; //0x046C 
		char pad_0470[4]; //0x0470
		PartnerSpSkillLevel aPartnerSpSkillLevel[PARTNER_ARRAY_SIZE]; //0x0474
		PartnerSkills aPartnerSkills[PARTNER_ARRAY_SIZE]; //0x0504 
		PartnerSkillsAutomaticButtons aPartnerSkillsAutomaticButtons[PARTNER_ARRAY_SIZE]; //0x0564
		PartnerEquipmentIcons aPartnerEquipmentIcons[PARTNER_ARRAY_SIZE]; //0x05F4
		PartnerResistanceIcons aPartnerResistanceIcons[PARTNER_ARRAY_SIZE]; //0x0654
		TNTIconWidget* partnerAttackStatIconWidget_1; //0x06B4 
		TNTIconWidget* partnerAttackStatIconWidget_2; //0x06B8 
		TNTIconWidget* partnerUknownIconWidget_1; //0x06BC 
		TNTIconWidget* partnerDefenseStatIconWidget; //0x06C0 
		TNTIconWidget* partnerMeleeDefenseStatIconWidget; //0x06C4 
		TNTIconWidget* partnerRangeDefenseStatIconWidget; //0x06C8 
		TNTIconWidget* partnerMagicDefenseStatIconWidget; //0x06CC 
		TNTIconWidget* partnerElementStatIconWidget; //0x06D0 
		TNTIconWidget* partnerFireResistanceIconWidget; //0x06D4 
		TNTIconWidget* partnerWaterResistanceIconWidget; //0x06D8 
		TNTIconWidget* partnerLightResistanceIconWidget; //0x06DC 
		TNTIconWidget* partnerShadowResistanceIconWidget; //0x06E0 
		TNTItemList* uknownList_7; //0x06E4 
		TNTItemList* uknownList_8; //0x06E8
		TEWLabels* petInfoLabels; //0x06EC 
		TNTCommonInfoBoard* TNTCommonInfoBoardPtr; //0x06F0 
		TNTIconWidget* petAttackStatIconWidget_1; //0x06F4 
		TNTIconWidget* petAttackStatIconWidget_2; //0x06F8 
		TNTIconWidget* petSpacerStatIconWidget; //0x06FC 
		TNTIconWidget* petDefenseStatIconWidget; //0x0700 
		TNTIconWidget* petMeleeDefenseStatIconWidget; //0x0704 
		TNTIconWidget* petRangeDefenseStatIconWidget; //0x0708 
		TNTIconWidget* petMagicDefenseStatIconWidget; //0x070C 
		TNTIconWidget* petElementIconWidget; //0x0710 
		TNTIconWidget* petFireResistanceIconWidget; //0x0714 
		TNTIconWidget* petWaterResistanceIconWidget; //0x0718 
		TNTIconWidget* petLightResistanceIconWidget; //0x071C 
		TNTIconWidget* petShadowResistanceIconWidget; //0x0720 
		TNTActInfoWidget* TNTActInfoWidgetPtr; //0x0724 
		TNTNewFamilyInfoWidget* TNTNewFamilyInfoWidgetPtr; //0x0728 
		PetInformation aPetInformation[PET_ARRAY_SIZE]; //0x072C
		PetInformation aPetInformation_2[PET_ARRAY_SIZE]; //0x0DBC
		char pad_144C[13040]; //0x144C
		int32_t currentPetList; //0x473C
		int32_t maxPetList; //0x4740
		TEWGraphicButtonWidget* petListLeftButton; //0x4744 
		TEWGraphicButtonWidget* petListRightButton; //0x4748 
		TEWLabel* petListLabel; //0x474C 
		char pad_4750[4]; //0x4750
		TEWGraphicButtonWidget* invokeButtonList[PET_ARRAY_SIZE + PARTNER_ARRAY_SIZE]; //0x4754 
		TEWCustomPanelWidget* leftPanel; //0x47AC 
		TEWCustomPanelWidget* centerPanel; //0x47B0
		TEWCustomPanelWidget* rightPanel; //0x47B4
		char pad_47B8[4]; //0x47B8
		TEWControlWidgetEX* characterSpLightEffect; //0x47BC 
		TEWControlWidgetEX* characterSpLightEffect_2; //0x47C0 
		uint32_t effectStatus; //0x47C4
		char pad_47C8[12]; //0x47C8
		TNTStoryInfoWidget* TNTStoryInfoWidgetPtr; //0x47D4 
		TNTQuestInfoWidget* TNTQuestInfoWidgetPtr; //0x47D8 
		TNTGroupInfoWidget* TNTGroupInfoWidgetPtr; //0x47DC 
		TNTTitleInfoWidget* TNTTitleInfoWidgetPtr; //0x47E0 
		int32_t entityIndex; //0x47E4
		PartnerInformation aPartnerInformation[PARTNER_ARRAY_SIZE]; //0x47E8
		char unknown[0x5A58]; //0x519C
	};
	static_assert(sizeof(TNTNewCharacterStandardInfoWidget) == 0xAC00, "TNTNewCharacterStandardInfoWidget does not have a size of 0xAC00");
#pragma pack(pop)
}