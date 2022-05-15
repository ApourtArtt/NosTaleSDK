#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWGraphicButtonWidget.h"
#include "TEWButtonWidget.h"
#include "TEWControlWidget.h"
#include "TEWControlWidgetEX.h"
#include "TEWLabel.h"
#include "TEWLabels.h"
#include "TNTItemList.h"
#include "../Properties/Logical/PartnerEquipmentIcons.h"
#include "../Properties/Logical/PartnerInformation.h"
#include "../Properties/Logical/PartnerResistanceIcons.h"
#include "../Properties/Logical/PartnerSkills.h"
#include "../Properties/Logical/PartnerSkillsAutomaticButtons.h"
#include "../Properties/Logical/PartnerSpSkillIcons.h"
#include "../Properties/Logical/PartnerSpSkillLevel.h"
#include "../Properties/Logical/PetInformation.h"
#pragma pack(push, 1)

constexpr int PARTNER_ARRAY_SIZE = 12;
constexpr int PET_ARRAY_SIZE = 10;

// TODO: Find uknown values


// Just to make the compiler happy, need reverse
class TNTCommonInfoBoard {};
class TNTActInfoWidget {};
class TNTNewFamilyInfoWidget {};
class TNTStoryInfoWidget {};
class TNTQuestInfoWidget {};
class TNTGroupInfoWidget {};
class TNTTitleInfoWidget {};

class TNTNewCharacterStandardInfoWidget : public TEWCustomFormWidget
{
public:
	char pad_00BC[4]; //0x00BC
	TEWGraphicButtonWidget* questionMarkButton; //0x00C0 
	TEWGraphicButtonWidget* closeButton; //0x00C4 
	TEWControlWidgetEX* nameControlWidgetEx; //0x00C8 
	TEWControlWidgetEX* levelControlWidgetEx; //0x00CC 
	TEWControlWidgetEX* reputationControlWidgetEx; //0x00D0 
	TEWControlWidgetEX* hpControlWidgetEx; //0x00D4 
	TEWControlWidgetEX* mpControlWidgetEx; //0x00D8 
	TEWLabels* coloredLabels; //0x00DC 
	TEWLabels* playerInfoLabels; //0x00E0 
	TEWControlWidgetEX* weaponControlWidgetEx; //0x00E4 
	TEWControlWidgetEX* armorControlWidgetEx; //0x00E8 
	TEWControlWidgetEX* hatControlWidgetEx; //0x00EC 
	TEWControlWidgetEX* glovesControlWidgetEx; //0x00F0 
	TEWControlWidgetEX* shoesControlWidgetEx; //0x00F4 
	TEWControlWidgetEX* secondWeaponControlWidgetEx; //0x00F8 
	TEWControlWidgetEX* necklaceControlWidgetEx; //0x00FC 
	TEWControlWidgetEX* ringControlWidgetEx; //0x0100 
	TEWControlWidgetEX* braceletControlWidgetEx; //0x0104 
	TEWControlWidgetEX* maskControlWidgetEx; //0x0108 
	TEWControlWidgetEX* fairyControlWidgetEx; //0x010C 
	TEWControlWidgetEX* amuletControlWidgetEx; //0x0110 
	TEWControlWidgetEX* spControlWidgetEx; //0x0114 
	TEWControlWidgetEX* costumeControlWidgetEx; //0x0118 
	TEWControlWidgetEX* costumeHatControlWidgetEx; //0x011C 
	TEWControlWidgetEX* weaponCostumeControlWidgetEx; //0x0120 
	TEWControlWidgetEX* wingsCostumeControlWidgetEx; //0x0124 
	TNTIconWidget* weaponIconWidget; //0x0128 
	TNTIconWidget* armorIconWidget; //0x012C 
	TNTIconWidget* hatIconWidget; //0x0130 
	TNTIconWidget* glovesIconWidget; //0x0134 
	TNTIconWidget* shoesIconWidget; //0x0138 
	TNTIconWidget* secondWeaponIconWidget; //0x013C 
	TNTIconWidget* necklaceIconWidget; //0x0140 
	TNTIconWidget* ringIconWidget; //0x0144 
	TNTIconWidget* braceletIconWidget; //0x0148 
	TNTIconWidget* maskIconWidget; //0x014C 
	TNTIconWidget* fairyIconWidget; //0x0150 
	TNTIconWidget* amuletIconWidget; //0x0154 
	TNTIconWidget* spIconWidget; //0x0158 
	TNTIconWidget* customeIconWidget; //0x015C 
	TNTIconWidget* costumeHatIconWidget; //0x0160 
	TNTIconWidget* weaponCostumeIconWidget; //0x0164 
	TNTIconWidget* wingsCostumeIconWidget; //0x0168 
	TEWCustomPanelWidget* statisticsCustomPanel; //0x016C 
	TNTItemList<uint32_t>* uknownList; //0x0170 
	TNTIconWidget* petIconWidgets[PET_ARRAY_SIZE]; //0x0174 
	TEWGraphicButtonWidget* characterHeadButton; //0x019C 
	TEWGraphicButtonWidget* partnerHeadButton[PARTNER_ARRAY_SIZE]; //0x01A0 
	TEWGraphicButtonWidget* petHeadButton[PET_ARRAY_SIZE]; //0x01D0 
	TNTItemList<uint32_t>* uknownList_2; //0x01F8 
	TNTIconWidget* characterHeadIconWidget; //0x01FC 
	TNTIconWidget* partnerHeadIconWidget[PARTNER_ARRAY_SIZE]; //0x0200 
	TNTItemList<uint32_t>* uknownList_3; //0x0230 
	TNTIconWidget* weaponStatIconWidget_1; //0x0234 
	TNTIconWidget* weaponStatIconWidget_2; //0x0238 
	TNTIconWidget* characterStatSpacer_1; //0x023C 
	TNTIconWidget* secondWeaponStatIconWidget_1; //0x0240 
	TNTIconWidget* secondWeaponStatIconWidget_2; //0x0244 
	TNTIconWidget* characterStatSpacer_2; //0x0248 
	TNTIconWidget* defenseStatIconWidget; //0x024C 
	TNTIconWidget* meleeDefenseStatIconWidget; //0x0250 
	TNTIconWidget* rangeDefenseStatIconWidget; //0x0254 
	TNTIconWidget* magicDefenseStatIconWidget; //0x0258 
	TNTIconWidget* fairyElementStatIconWidget; //0x025C 
	TNTIconWidget* fireResistanceIconWidget; //0x0260 
	TNTIconWidget* waterResistanceIconWidget; //0x0264 
	TNTIconWidget* lghtResistanceIconWidget; //0x0268 
	TNTIconWidget* shadowResistanceIconWidget; //0x026C 
	TEWControlWidgetEX* ereniaMedalControlWidgetEx; //0x0270
	TEWControlWidgetEX* adventurerMedalControlWidgetEx; //0x0274 
	TEWControlWidgetEX* expertOrderMedalControlWidgetEx; //0x0278 
	TEWControlWidgetEX* friendshipMedalControlWidgetEx; //0x027C 
	TEWControlWidgetEX* weirdQuestionMarkControlWidgetEx; //0x0280 
	TEWControlWidgetEX* uknownControlWidgetEx_1; //0x0284 
	TEWControlWidgetEX* uknownControlWidgetEx_2; //0x0288 
	TEWControlWidgetEX* uknownControlWidgetEx_3; //0x028C 
	TNTIconWidget* uknownIconWidget_3; //0x0290 
	TNTIconWidget* uknownIconWidget_4; //0x0294 
	TNTIconWidget* uknownIconWidget_5; //0x0298 
	TNTIconWidget* uknownIconWidget_6; //0x029C 
	TNTIconWidget* uknownIconWidget_7; //0x02A0 
	TNTIconWidget* uknownIconWidget_8; //0x02A4 
	TNTIconWidget* uknownIconWidget_9; //0x02A8 
	TNTIconWidget* uknownIconWidget_10; //0x02AC 
	TNTIconWidget* reputationIconWidget; //0x02B0 
	int32_t classType; //0x02B4 0 = adventurer, 1 = swordie, 2 = archer, 3 = mage
	int32_t gender; //0x02B8 0 = male, 1 = female
	char* className; //0x02BC
	int32_t currentSelectedTabIndex; //0x02C0
	int32_t currentSelectedPartnerIndex; //0x02C4
	int32_t currentSelectedPetIndex; //0x02C8
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
	TNTItemList<uint32_t>* uknownList_4; //0x043C 
	TNTItemList<uint32_t>* uknownList_5; //0x0440
	TNTItemList<uint32_t>* uknownList_6; //0x0444
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
	TNTItemList<uint32_t>* uknownList_7; //0x06E4 
	TNTItemList<uint32_t>* uknownList_8; //0x06E8
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
}; //Size: 0x519C
static_assert(sizeof(TNTNewCharacterStandardInfoWidget) == 0x519C);

#pragma pack(pop)