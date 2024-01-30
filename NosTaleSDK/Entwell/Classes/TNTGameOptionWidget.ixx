module;
#include <stdint.h>
export module TNTGameOptionWidget;
import TEWCustomFormWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTGameOptionWidget : public TEWCustomFormWidget
	{
		char unknown38[4];														// 0x0BC
		struct TEWLabel* windowTitle;											// 0x0C0
		struct TEWGraphicButtonWidget* questionMarkButton;						// 0x0C4
		struct TEWGraphicButtonWidget* closeButton;								// 0x0C8 
		struct TLBSWidget* displayConfigurationWidget;							// 0x0CC 
		struct TEWLabel* displayConfigurationLabel;								// 0x0D0 
		struct TEWCustomPanelWidget* displayConfigurationPanel;					// 0x0D4 
		struct TEWLabel* resolutionLabel;										// 0x0D8 
		struct TEWGraphicButtonWidget* resolution1024x768Button;				// 0x0DC 
		struct TEWGraphicButtonWidget* resolution1280x1024Button;				// 0x0E0 
		struct TEWLabel* resolution1024x768ButtonLabel;							// 0x0E4 
		struct TEWLabel* resolution1280x1024ButtonLabel;						// 0x0E8 
		struct TEWGraphicButtonWidget* resolution1280x800Button;				// 0x0EC 
		struct TEWGraphicButtonWidget* resolution1440x900Button;				// 0x0F0 
		struct TEWGraphicButtonWidget* resolution1024x700Button;				// 0x0F4 
		struct TEWLabel* resolution1280x800ButtonLabel;							// 0x0F8 
		struct TEWLabel* resolution1440x900ButtonLabel;							// 0x0FC 
		struct TEWLabel* resolution1024x700ButtonLabel;							// 0x100 
		struct TEWGraphicButtonWidget* resolution1680x1050Button;				// 0x104 
		struct TEWLabel* resolution1680x1050ButtonLabel;						// 0x108 
		struct TEWGraphicButtonWidget* windowModeButton;						// 0x10C 
		struct TEWLabel* windowModeLabel;										// 0x110 
		struct TEWGraphicButtonWidget* fullScreenWindowModeButton;				// 0x114 
		struct TEWLabel* fullScreenWindowModeLabel;								// 0x118 
		struct TEWGraphicButtonWidget* resetUIPositionButton;					// 0x11C 
		struct TEWLabel* resetUIPositionLabel;									// 0x120 
		struct TEWCustomPanelWidget* unknown39;									// 0x124 
		struct TEWLabel* unusedLabel_1;											// 0x128 
		struct TEWGraphicButtonWidget* resolutionButton_8_Unused;				// 0x12C 
		struct TEWGraphicButtonWidget* resolutionButton_9_Unused;				// 0x130 
		struct TEWLabel* resolutionButtonLabel_8_Unused;						// 0x134 
		struct TEWLabel* resolutionButtonLabel_9_Unused;						// 0x138 
		struct TLBSWidget* soundWidget;											// 0x13C 
		struct TEWLabel* soundLabel;											// 0x140 
		struct TEWCustomPanelWidget* soundPanel;								// 0x144 
		struct TEWLabel* soundEffectsLabel;										// 0x148 
		struct TEWScrollBarTrack* soundEffectsScrollBar;						// 0x14C 
		struct TEWGraphicButtonWidget* soundsEffectCheckBox;					// 0x150 
		struct TEWLabel* bgmLabel;												// 0x154 
		struct TEWScrollBarTrack* bgmScrollBar;									// 0x158 
		struct TEWGraphicButtonWidget* bgmCheckBox;								// 0x15C 
		struct TLBSWidget* otherSettingsWidget;									// 0x160 
		struct TEWLabel* otherSettingsLabel;									// 0x164 
		struct TEWCustomPanelWidget* otherSettingsPanel;						// 0x168 
		uint8_t isPartyBlockChecked;											// 0x16C
		uint8_t isFamilyBlockChecked;											// 0x16D
		uint8_t isFriendBlockChecked;											// 0x16E
		uint8_t isWhisperBlockChecked;											// 0x16F
		uint8_t isExchangeBlockChecked;											// 0x170
		uint8_t isMouseTrapChecked;												// 0x171
		uint8_t isSpeakerBlockChecked;											// 0x172
		uint8_t isBlockMLInvitesChecked;										// 0x173
		uint8_t isGetUpImmediatelyChecked;										// 0x174
		uint8_t isSmileysGoneChecked;											// 0x175
		uint8_t isHpStatusGoneChecked;											// 0x176
		uint8_t isBuffSeqGoneChecked;											// 0x177
		uint8_t isHatIsNotVisibleChecked;										// 0x178
		uint8_t isLockUIChecked;												// 0x179
		uint8_t unknown40;														// 0x17A
		uint8_t unknown41;														// 0x17B
		struct TEWGraphicButtonWidget* partyBlockCheckBox;						// 0x17C 
		struct TEWGraphicButtonWidget* familyBlockCheckBox;						// 0x180 
		struct TEWGraphicButtonWidget* friendBlockCheckBox;						// 0x184 
		struct TEWGraphicButtonWidget* whisperBlockCheckBox;					// 0x188 
		struct TEWGraphicButtonWidget* exchangeBlockCheckBox;					// 0x18C 
		struct TEWGraphicButtonWidget* mouseTrapCheckBox;						// 0x190 
		struct TEWGraphicButtonWidget* speakerBlockCheckBox;					// 0x194 
		struct TEWGraphicButtonWidget* blockMLInvitesCheckBox;					// 0x198 
		struct TEWGraphicButtonWidget* getUpImmediatelyCheckBox;				// 0x19C 
		struct TEWGraphicButtonWidget* smileysGoneCheckBox;						// 0x1A0 
		struct TEWGraphicButtonWidget* hpStatusGoneCheckBox;					// 0x1A4 
		struct TEWGraphicButtonWidget* buffSeqGoneCheckBox;						// 0x1A8 
		struct TEWGraphicButtonWidget* hatIsNotVisibleCheckBox;					// 0x1AC 
		struct TEWGraphicButtonWidget* lockUICheckBox;							// 0x1B0 
		struct TEWGraphicButtonWidget* hideTimeCheckBox;						// 0x1B4
		struct TEWGraphicButtonWidget* hideStatsCheckBox;						// 0x1B8 
		struct TEWLabels* otherSettingsLabels;									// 0x1BC
		struct TLBSWidget* bottomWidget;										// 0x1C0 
		struct TEWCustomPanelWidget* bottomPanel;								// 0x1C4 
		struct TEWGraphicButtonWidget* confirmButton;							// 0x1C8 
		struct TEWLabel* confirmLabel;											// 0x1CC
		uint8_t isBgmChecked;													// 0x1D0
		uint8_t isSoundsEffectsChecked;											// 0x1D1
		uint8_t unknown43;														// 0x1D2
		uint8_t isWindowModeChecked;											// 0x1D3
		char unknown44[4];														// 0x1D4
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown45;	// 0x1D8
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown46;	// 0x1E0
	};
	static_assert(sizeof(TNTGameOptionWidget) == 0x1E8, "TNTGameOptionWidget size isn't 0x1E8.");
	static_assert(sizeof(TNTGameOptionWidget) <= 0x1E8, "TNTGameOptionWidget size is upper than 0x1E8.");
	static_assert(sizeof(TNTGameOptionWidget) >= 0x1E8, "TNTGameOptionWidget size is lower than 0x1E8.");
#pragma pack(pop)
}