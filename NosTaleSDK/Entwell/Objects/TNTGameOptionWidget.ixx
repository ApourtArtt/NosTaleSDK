module;
#include <stdint.h>
export module TNTGameOptionWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTGameOptionWidget : public TEWCustomFormWidget
	{
		char pad_00BC[4]; //0x00BC
		struct TEWLabel* windowTitle; //0x00C0
		struct TEWGraphicButtonWidget* questionMarkButton; //0x00C4 by default it's hidden
		struct TEWGraphicButtonWidget* closeButton; //0x00C8 
		struct TLBSWidget* displayConfigurationWidget; //0x00CC 
		struct TEWLabel* displayConfigurationLabel; //0x00D0 
		struct TEWCustomPanelWidget* displayConfigurationPanel; //0x00D4 
		struct TEWLabel* resolutionLabel; //0x00D8 
		struct TEWGraphicButtonWidget* resolution1024x768Button; //0x00DC 
		struct TEWGraphicButtonWidget* resolution1280x1024Button; //0x00E0 
		struct TEWLabel* resolution1024x768ButtonLabel; //0x00E4 
		struct TEWLabel* resolution1280x1024ButtonLabel; //0x00E8 
		struct TEWGraphicButtonWidget* resolution1280x800Button; //0x00EC 
		struct TEWGraphicButtonWidget* resolution1440x900Button; //0x00F0 
		struct TEWGraphicButtonWidget* resolution1024x700Button; //0x00F4 
		struct TEWLabel* resolution1280x800ButtonLabel; //0x00F8 
		struct TEWLabel* resolution1440x900ButtonLabel; //0x00FC 
		struct TEWLabel* resolution1024x700ButtonLabel; //0x0100 
		struct TEWGraphicButtonWidget* resolution1680x1050Button; //0x0104 
		struct TEWLabel* resolution1680x1050ButtonLabel; //0x0108 
		struct TEWGraphicButtonWidget* windowModeButton; //0x010C 
		struct TEWLabel* windowModeLabel; //0x0110 
		struct TEWGraphicButtonWidget* fullScreenWindowModeButton; //0x0114 
		struct TEWLabel* fullScreenWindowModeLabel; //0x0118 
		struct TEWGraphicButtonWidget* resetUIPositionButton; //0x011C 
		struct TEWLabel* resetUIPositionLabel; //0x0120 
		struct TEWCustomPanelWidget* uknownPanel_1; //0x0124 
		struct TEWLabel* unusedLabel_1; //0x0128 
		struct TEWGraphicButtonWidget* resolutionButton_8_Unused; //0x012C 
		struct TEWGraphicButtonWidget* resolutionButton_9_Unused; //0x0130 
		struct TEWLabel* resolutionButtonLabel_8_Unused; //0x0134 
		struct TEWLabel* resolutionButtonLabel_9_Unused; //0x0138 
		struct TLBSWidget* soundWidget; //0x013C 
		struct TEWLabel* soundLabel; //0x0140 
		struct TEWCustomPanelWidget* soundPanel; //0x0144 
		struct TEWLabel* soundEffectsLabel; //0x0148 
		struct TEWScrollBarTrack* soundEffectsScrollBar; //0x014C 
		struct TEWGraphicButtonWidget* soundsEffectCheckBox; //0x0150 
		struct TEWLabel* bgmLabel; //0x0154 
		struct TEWScrollBarTrack* bgmScrollBar; //0x0158 
		struct TEWGraphicButtonWidget* bgmCheckBox; //0x015C 
		struct TLBSWidget* otherSettingsWidget; //0x0160 
		struct TEWLabel* otherSettingsLabel; //0x0164 
		struct TEWCustomPanelWidget* otherSettingsPanel; //0x0168 
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
		struct TEWGraphicButtonWidget* partyBlockCheckBox; //0x017C 
		struct TEWGraphicButtonWidget* familyBlockCheckBox; //0x0180 
		struct TEWGraphicButtonWidget* friendBlockCheckBox; //0x0184 
		struct TEWGraphicButtonWidget* whisperBlockCheckBox; //0x0188 
		struct TEWGraphicButtonWidget* exchangeBlockCheckBox; //0x018C 
		struct TEWGraphicButtonWidget* mouseTrapCheckBox; //0x0190 
		struct TEWGraphicButtonWidget* speakerBlockCheckBox; //0x0194 
		struct TEWGraphicButtonWidget* blockMLInvitesCheckBox; //0x0198 
		struct TEWGraphicButtonWidget* getUpImmediatelyCheckBox; //0x019C 
		struct TEWGraphicButtonWidget* smileysGoneCheckBox; //0x01A0 
		struct TEWGraphicButtonWidget* hpStatusGoneCheckBox; //0x01A4 
		struct TEWGraphicButtonWidget* buffSeqGoneCheckBox; //0x01A8 
		struct TEWGraphicButtonWidget* hatIsNotVisibleCheckBox; //0x01AC 
		struct TEWGraphicButtonWidget* lockUICheckBox; //0x01B0 
		struct TEWLabels* otherSettingsLabels; //0x01B4 
		struct TLBSWidget* bottomWidget; //0x01B8 
		struct TEWCustomPanelWidget* bottomPanel; //0x01BC 
		struct TEWGraphicButtonWidget* confirmButton; //0x01C0 
		struct TEWLabel* confirmLabel; //0x01C4 
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
#pragma pack(pop)
}