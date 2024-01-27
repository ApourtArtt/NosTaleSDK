module;
export module TNTTaskBarWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTaskBarWidget : public TEWCustomFormWidget
	{
		char unknown22[4];											// 0xBC
		struct TEWRollOverButtonWidget* helpButton;						// 0xC0
		struct TEWRollOverButtonWidget* noteButton;						// 0xC4
		struct TEWRollOverButtonWidget* parcelButton;						// 0xC8
		struct TEWRollOverButtonWidget* characterButton;					// 0xCC
		struct TEWRollOverButtonWidget* skillsButton;						// 0xD0
		struct TEWRollOverButtonWidget* inventoryButton;					// 0xD4
		struct TEWRollOverButtonWidget* unusedButton;						// 0xD8
		struct TEWRollOverButtonWidget* questButton;						// 0xDC
		struct TEWRollOverButtonWidget* minilandButton;					// 0xE0
		struct TEWRollOverButtonWidget* messengerButton;					// 0xE4
		struct TEWRollOverButtonWidget* unusedButton2;						// 0xE8
		struct TNTWebBrowserFormWidget* guideWebBrowser;					// 0xEC
		void* nosmallMemoWrite;										// 0xF0 TNTNosMallMemoWrite
		void* nosmallTotalWidget;									// 0xF4 TNTNosMallTotalWidget
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget;		// 0xF8
		void* skillInfoWidget;										// 0xFC TNTNewCharacterSkillInfoWidget
		void* inventoryInfoWidget;									// 0x100 TNTNewCharacterInventoryInfoWidget
		void* nosmallTotalWidget2;									// 0x104 TNTNosMallTotalWidget
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget2;	// 0x104
		void* miniLandInfoWidget;									// 0x108 TNTMinilandInfoWidget
		void* buddyWidget;											// 0x10C TBuddyWidget
		void* systemOptionWidget;									// 0x110 TNTSystemOptionWidget
		TEWCustomPanelWidget* hintWidget;							// 0x114
		struct TEWLabel* hintText;											// 0x118
		struct TEWGraphicButtonWidget* gameConfigurationBtn;				// 0x11C
		struct TEWGraphicButtonWidget* returnBtn;							// 0x120
		struct TEWGraphicButtonWidget* serverSelectBtn;					// 0x124
		struct TEWGraphicButtonWidget* quitGameBtn;						// 0x128
		struct TEWLabel* gameConfigBtnLabel;								// 0x12C
		struct TEWLabel* returnBtnLabel;									// 0x130
		struct TEWLabel* serverSelectBtnLabel;								// 0x134
		struct TEWLabel* quitGameLabel;									// 0x138

	};
	static_assert(sizeof(TNTTaskBarWidget) == 0x140, "TNTTaskBarWidget does not have a size of 0x140.");
#pragma pack(pop)
}