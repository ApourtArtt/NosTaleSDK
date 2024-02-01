module;
export module TNTTaskBarWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTaskBarWidget : public TEWCustomFormWidget
	{
		char unknown38[4];												// 0x0BC
		struct TEWRollOverButtonWidget* helpButton;						// 0x0C0
		TEWRollOverButtonWidget* noteButton;							// 0x0C4
		TEWRollOverButtonWidget* parcelButton;							// 0x0C8
		TEWRollOverButtonWidget* characterButton;						// 0x0CC
		TEWRollOverButtonWidget* skillsButton;							// 0x0D0
		TEWRollOverButtonWidget* inventoryButton;						// 0x0D4
		TEWRollOverButtonWidget* unusedButton;							// 0x0D8
		TEWRollOverButtonWidget* questButton;							// 0x0DC
		TEWRollOverButtonWidget* minilandButton;						// 0x0E0
		TEWRollOverButtonWidget* messengerButton;						// 0x0E4
		TEWRollOverButtonWidget* unusedButton2;							// 0x0E8
		struct TNTWebBrowserFormWidget* guideWebBrowser;				// 0x0EC
		struct TNTNosMallMemoReadWrite* nosmallMemoReadWrite;			// 0x0F0
		struct TNTNosMallTotalWidget* nosmallTotalWidget;				// 0x0F4
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget;	// 0x0F8
		struct TNTNewCharacterSkillInfoWidget* skillInfoWidget;			// 0x0FC
		void* inventoryInfoWidget;										// 0x100 TNTNewCharacterInventoryInfoWidget
		TNTNosMallTotalWidget* nosmallTotalWidget2;						// 0x104
		TNTNewCharacterStandardInfoWidget* characterInfoWidget2;		// 0x104
		void* miniLandInfoWidget;										// 0x108 TNTMinilandInfoWidget
		void* buddyWidget;												// 0x10C TBuddyWidget
		void* systemOptionWidget;										// 0x110 TNTSystemOptionWidget
		TEWCustomPanelWidget* hintWidget;								// 0x114
		struct TEWLabel* hintText;										// 0x118
		struct TEWGraphicButtonWidget* gameConfigurationBtn;			// 0x11C
		TEWGraphicButtonWidget* returnBtn;								// 0x120
		TEWGraphicButtonWidget* serverSelectBtn;						// 0x124
		TEWGraphicButtonWidget* quitGameBtn;							// 0x128
		TEWLabel* gameConfigBtnLabel;									// 0x12C
		TEWLabel* returnBtnLabel;										// 0x130
		TEWLabel* serverSelectBtnLabel;									// 0x134
		TEWLabel* quitGameLabel;										// 0x138

	};
	static_assert(sizeof(TNTTaskBarWidget) == 0x140, "TNTTaskBarWidget size isn't 0x140.");
	static_assert(sizeof(TNTTaskBarWidget) <= 0x140, "TNTTaskBarWidget size is upper than 0x140.");
	static_assert(sizeof(TNTTaskBarWidget) >= 0x140, "TNTTaskBarWidget size is lower than 0x140.");
#pragma pack(pop)
}