#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWCustomPanelWidget.h"
#include "TEWScrollBarTrack.h"
#include "TEWGraphicButtonWidget.h"
#include "TEWLabel.h"
#include "TEWLabels.h"

// TODO: Find uknown values

class TNTGameOptionWidget : public TEWCustomFormWidget
{
public:
	char pad_00BC[4]; //0x00BC
	TEWLabel* windowTitle; //0x00C0
	TEWGraphicButtonWidget* questionMarkButton; //0x00C4 by default it's hidden
	TEWGraphicButtonWidget* closeButton; //0x00C8 
	TLBSWidget* displayConfigurationWidget; //0x00CC 
	TEWLabel* displayConfigurationLabel; //0x00D0 
	TEWCustomPanelWidget* displayConfigurationPanel; //0x00D4 
	TEWLabel* resolutionLabel; //0x00D8 
	TEWGraphicButtonWidget* resolution1024x768Button; //0x00DC 
	TEWGraphicButtonWidget* resolution1280x1024Button; //0x00E0 
	TEWLabel* resolution1024x768ButtonLabel; //0x00E4 
	TEWLabel* resolution1280x1024ButtonLabel; //0x00E8 
	TEWGraphicButtonWidget* resolution1280x800Button; //0x00EC 
	TEWGraphicButtonWidget* resolution1440x900Button; //0x00F0 
	TEWGraphicButtonWidget* resolution1024x700Button; //0x00F4 
	TEWLabel* resolution1280x800ButtonLabel; //0x00F8 
	TEWLabel* resolution1440x900ButtonLabel; //0x00FC 
	TEWLabel* resolution1024x700ButtonLabel; //0x0100 
	TEWGraphicButtonWidget* resolution1680x1050Button; //0x0104 
	TEWLabel* resolution1680x1050ButtonLabel; //0x0108 
	TEWGraphicButtonWidget* windowModeButton; //0x010C 
	TEWLabel* windowModeLabel; //0x0110 
	TEWGraphicButtonWidget* fullScreenWindowModeButton; //0x0114 
	TEWLabel* fullScreenWindowModeLabel; //0x0118 
	TEWGraphicButtonWidget* resetUIPositionButton; //0x011C 
	TEWLabel* resetUIPositionLabel; //0x0120 
	TEWCustomPanelWidget* uknownPanel_1; //0x0124 
	TEWLabel* unusedLabel_1; //0x0128 
	TEWGraphicButtonWidget* resolutionButton_8_Unused; //0x012C 
	TEWGraphicButtonWidget* resolutionButton_9_Unused; //0x0130 
	TEWLabel* resolutionButtonLabel_8_Unused; //0x0134 
	TEWLabel* resolutionButtonLabel_9_Unused; //0x0138 
	TLBSWidget* soundWidget; //0x013C 
	TEWLabel* soundLabel; //0x0140 
	TEWCustomPanelWidget* soundPanel; //0x0144 
	TEWLabel* soundEffectsLabel; //0x0148 
	TEWScrollBarTrack* soundEffectsScrollBar; //0x014C 
	TEWGraphicButtonWidget* soundsEffectCheckBox; //0x0150 
	TEWLabel* bgmLabel; //0x0154 
	TEWScrollBarTrack* bgmScrollBar; //0x0158 
	TEWGraphicButtonWidget* bgmCheckBox; //0x015C 
	TLBSWidget* otherSettingsWidget; //0x0160 
	TEWLabel* otherSettingsLabel; //0x0164 
	TEWCustomPanelWidget* otherSettingsPanel; //0x0168 
	uint8_t isPartyBlockChecked; //0x016C
	uint8_t isFamilyBlockChecked; //0x016D
	uint8_t isFriendBlockChecked; //0x016E
	uint8_t isWhisperBlockChecked; //0x016F
	uint8_t isExchangeBlockChecked; //0x0170
	uint8_t isMouseTrapChecked; //0x0171
	uint8_t isSpeakerBlockChecked; //0x0172
	uint8_t isBlockMLInvitesChecked; //0x0173
	uint8_t isGetUpImmediatelyChecked; //0x0174
	uint8_t isSmileysGoneChecked; //0x0175
	uint8_t isHpStatusGoneChecked; //0x0176
	uint8_t isBuffSeqGoneChecked; //0x0177
	uint8_t isHatIsNotVisibleChecked; //0x0178
	uint8_t isLockUIChecked; //0x0179
	uint8_t uknownChecked_1; //0x017A
	uint8_t uknownChecked_2; //0x017B
	TEWGraphicButtonWidget* partyBlockCheckBox; //0x017C 
	TEWGraphicButtonWidget* familyBlockCheckBox; //0x0180 
	TEWGraphicButtonWidget* friendBlockCheckBox; //0x0184 
	TEWGraphicButtonWidget* whisperBlockCheckBox; //0x0188 
	TEWGraphicButtonWidget* exchangeBlockCheckBox; //0x018C 
	TEWGraphicButtonWidget* mouseTrapCheckBox; //0x0190 
	TEWGraphicButtonWidget* speakerBlockCheckBox; //0x0194 
	TEWGraphicButtonWidget* blockMLInvitesCheckBox; //0x0198 
	TEWGraphicButtonWidget* getUpImmediatelyCheckBox; //0x019C 
	TEWGraphicButtonWidget* smileysGoneCheckBox; //0x01A0 
	TEWGraphicButtonWidget* hpStatusGoneCheckBox; //0x01A4 
	TEWGraphicButtonWidget* buffSeqGoneCheckBox; //0x01A8 
	TEWGraphicButtonWidget* hatIsNotVisibleCheckBox; //0x01AC 
	TEWGraphicButtonWidget* lockUICheckBox; //0x01B0 
	TEWLabels* otherSettingsLabels; //0x01B4 
	TLBSWidget* bottomWidget; //0x01B8 
	TEWCustomPanelWidget* bottomPanel; //0x01BC 
	TEWGraphicButtonWidget* confirmButton; //0x01C0 
	TEWLabel* confirmLabel; //0x01C4 
	uint8_t isBgmChecked; //0x01C8
	uint8_t isSoundsEffectsChecked; //0x01C9
	uint8_t uknownChecked_3; //0x01CA
	uint8_t isWindowModeChecked; //0x01CB
	char pad_01CC[4]; //0x01CC
	uint32_t TGameRootWidgetVtablePtr_1; //0x01D0
	uint32_t TGameRootWidgetPtr_1; //0x01D4 TGameRootWidget
	uint32_t TGameRootWidgetVtablePtr_2; //0x01D8
	uint32_t TGameRootWidgetPtr_2; //0x01DC TGameRootWidget
}; //Size: 0x01E0
static_assert(sizeof(TNTGameOptionWidget) == 0x1E0);