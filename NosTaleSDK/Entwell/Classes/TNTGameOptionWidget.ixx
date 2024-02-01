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
		char unknown38[4];									// 0x0BC
		struct TEWLabel* windowTitle;						// 0x0C0
		struct TEWGraphicButtonWidget* questionMarkButton;	// 0x0C4
		TEWGraphicButtonWidget* closeButton;				// 0x0C8 
		TLBSWidget* displayConfigurationWidget;				// 0x0CC 
		TEWLabel* displayConfigurationLabel;				// 0x0D0 
		TEWCustomPanelWidget* displayConfigurationPanel;	// 0x0D4 
		TEWLabel* resolutionLabel;							// 0x0D8 
		TEWGraphicButtonWidget* resolution1024X768Button;	// 0x0DC 
		TEWGraphicButtonWidget* resolution1280X1024Button;	// 0x0E0 
		TEWLabel* resolution1024X768ButtonLabel;			// 0x0E4 
		TEWLabel* resolution1280X1024ButtonLabel;			// 0x0E8 
		TEWGraphicButtonWidget* resolution1280X800Button;	// 0x0EC 
		TEWGraphicButtonWidget* resolution1440X900Button;	// 0x0F0 
		TEWGraphicButtonWidget* resolution1024X700Button;	// 0x0F4 
		TEWLabel* resolution1280X800ButtonLabel;			// 0x0F8 
		TEWLabel* resolution1440X900ButtonLabel;			// 0x0FC 
		TEWLabel* resolution1024X700ButtonLabel;			// 0x100 
		TEWGraphicButtonWidget* resolution1680X1050Button;	// 0x104 
		TEWLabel* resolution1680X1050ButtonLabel;			// 0x108 
		TEWGraphicButtonWidget* windowModeButton;			// 0x10C 
		TEWLabel* windowModeLabel;							// 0x110 
		TEWGraphicButtonWidget* fullScreenWindowModeButton;	// 0x114 
		TEWLabel* fullScreenWindowModeLabel;				// 0x118 
		TEWGraphicButtonWidget* resetUiPositionButton;		// 0x11C 
		TEWLabel* resetUiPositionLabel;						// 0x120 
		TEWCustomPanelWidget* unknown39;					// 0x124 
		TEWLabel* unusedLabel1;								// 0x128 
		TEWGraphicButtonWidget* resolutionButton8Unused;	// 0x12C 
		TEWGraphicButtonWidget* resolutionButton9Unused;	// 0x130 
		TEWLabel* resolutionButtonLabel8Unused;				// 0x134 
		TEWLabel* resolutionButtonLabel9Unused;				// 0x138 
		TLBSWidget* soundWidget;							// 0x13C 
		TEWLabel* soundLabel;								// 0x140 
		TEWCustomPanelWidget* soundPanel;					// 0x144 
		TEWLabel* soundEffectsLabel;						// 0x148 
		struct TEWScrollBarTrack* soundEffectsScrollBar;	// 0x14C 
		TEWGraphicButtonWidget* soundsEffectCheckBox;		// 0x150 
		TEWLabel* bgmLabel;									// 0x154 
		TEWScrollBarTrack* bgmScrollBar;					// 0x158 
		TEWGraphicButtonWidget* bgmCheckBox;				// 0x15C 
		TLBSWidget* otherSettingsWidget;					// 0x160 
		TEWLabel* otherSettingsLabel;						// 0x164 
		TEWCustomPanelWidget* otherSettingsPanel;			// 0x168 
		uint8_t isPartyBlockChecked;						// 0x16C
		uint8_t isFamilyBlockChecked;						// 0x16D
		uint8_t isFriendBlockChecked;						// 0x16E
		uint8_t isWhisperBlockChecked;						// 0x16F
		uint8_t isExchangeBlockChecked;						// 0x170
		uint8_t isMouseTrapChecked;							// 0x171
		uint8_t isSpeakerBlockChecked;						// 0x172
		uint8_t isBlockMlInvitesChecked;					// 0x173
		uint8_t isGetUpImmediatelyChecked;					// 0x174
		uint8_t isSmileysGoneChecked;						// 0x175
		uint8_t isHpStatusGoneChecked;						// 0x176
		uint8_t isBuffSeqGoneChecked;						// 0x177
		uint8_t isHatIsNotVisibleChecked;					// 0x178
		uint8_t isLockUiChecked;							// 0x179
		uint8_t unknown40;									// 0x17A
		uint8_t unknown41;									// 0x17B
		TEWGraphicButtonWidget* partyBlockCheckBox;			// 0x17C 
		TEWGraphicButtonWidget* familyBlockCheckBox;		// 0x180 
		TEWGraphicButtonWidget* friendBlockCheckBox;		// 0x184 
		TEWGraphicButtonWidget* whisperBlockCheckBox;		// 0x188 
		TEWGraphicButtonWidget* exchangeBlockCheckBox;		// 0x18C 
		TEWGraphicButtonWidget* mouseTrapCheckBox;			// 0x190 
		TEWGraphicButtonWidget* speakerBlockCheckBox;		// 0x194 
		TEWGraphicButtonWidget* blockMlInvitesCheckBox;		// 0x198 
		TEWGraphicButtonWidget* getUpImmediatelyCheckBox;	// 0x19C 
		TEWGraphicButtonWidget* smileysGoneCheckBox;		// 0x1A0 
		TEWGraphicButtonWidget* hpStatusGoneCheckBox;		// 0x1A4 
		TEWGraphicButtonWidget* buffSeqGoneCheckBox;		// 0x1A8 
		TEWGraphicButtonWidget* hatIsNotVisibleCheckBox;	// 0x1AC 
		TEWGraphicButtonWidget* lockUiCheckBox;				// 0x1B0 
		TEWGraphicButtonWidget* hideTimeCheckBox;			// 0x1B4
		TEWGraphicButtonWidget* hideStatsCheckBox;			// 0x1B8 
		struct TEWLabels* otherSettingsLabels;				// 0x1BC
		TLBSWidget* bottomWidget;							// 0x1C0 
		TEWCustomPanelWidget* bottomPanel;					// 0x1C4 
		TEWGraphicButtonWidget* confirmButton;				// 0x1C8 
		TEWLabel* confirmLabel;								// 0x1CC
		uint8_t isBgmChecked;								// 0x1D0
		uint8_t isSoundsEffectsChecked;						// 0x1D1
		uint8_t unknown43;									// 0x1D2
		uint8_t isWindowModeChecked;						// 0x1D3
		char unknown44[4];									// 0x1D4
		Properties::Logical::Callback unknown45;			// 0x1D8
		Properties::Logical::Callback unknown46;			// 0x1E0
	};
	static_assert(sizeof(TNTGameOptionWidget) == 0x1E8, "TNTGameOptionWidget size isn't 0x1E8.");
	static_assert(sizeof(TNTGameOptionWidget) <= 0x1E8, "TNTGameOptionWidget size is upper than 0x1E8.");
	static_assert(sizeof(TNTGameOptionWidget) >= 0x1E8, "TNTGameOptionWidget size is lower than 0x1E8.");
#pragma pack(pop)
}