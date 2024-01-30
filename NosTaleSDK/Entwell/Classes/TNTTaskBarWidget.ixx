module;
export module TNTTaskBarWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTaskBarWidget : public TEWCustomFormWidget
	{
		char unknown38[4];													// 0x0BC
		struct TEWRollOverButtonWidget* helpButton;							// 0x0C0
		struct TEWRollOverButtonWidget* noteButton;							// 0x0C4
		struct TEWRollOverButtonWidget* parcelButton;						// 0x0C8
		struct TEWRollOverButtonWidget* characterButton;					// 0x0CC
		struct TEWRollOverButtonWidget* skillsButton;						// 0x0D0
		struct TEWRollOverButtonWidget* inventoryButton;					// 0x0D4
		struct TEWRollOverButtonWidget* unusedButton;						// 0x0D8
		struct TEWRollOverButtonWidget* questButton;						// 0x0DC
		struct TEWRollOverButtonWidget* minilandButton;						// 0x0E0
		struct TEWRollOverButtonWidget* messengerButton;					// 0x0E4
		struct TEWRollOverButtonWidget* unusedButton2;						// 0x0E8
		struct TNTWebBrowserFormWidget* guideWebBrowser;					// 0x0EC
		struct TNTNosMallMemoReadWrite* nosmallMemoReadWrite;				// 0x0F0
		void* nosmallTotalWidget;											// 0x0F4 TNTNosMallTotalWidget
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget;		// 0x0F8
		void* skillInfoWidget;												// 0x0FC TNTNewCharacterSkillInfoWidget
		void* inventoryInfoWidget;											// 0x100 TNTNewCharacterInventoryInfoWidget
		void* nosmallTotalWidget2;											// 0x104 TNTNosMallTotalWidget
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget2;		// 0x104
		void* miniLandInfoWidget;											// 0x108 TNTMinilandInfoWidget
		void* buddyWidget;													// 0x10C TBuddyWidget
		void* systemOptionWidget;											// 0x110 TNTSystemOptionWidget
		struct TEWCustomPanelWidget* hintWidget;							// 0x114
		struct TEWLabel* hintText;											// 0x118
		struct TEWGraphicButtonWidget* gameConfigurationBtn;				// 0x11C
		struct TEWGraphicButtonWidget* returnBtn;							// 0x120
		struct TEWGraphicButtonWidget* serverSelectBtn;						// 0x124
		struct TEWGraphicButtonWidget* quitGameBtn;							// 0x128
		struct TEWLabel* gameConfigBtnLabel;								// 0x12C
		struct TEWLabel* returnBtnLabel;									// 0x130
		struct TEWLabel* serverSelectBtnLabel;								// 0x134
		struct TEWLabel* quitGameLabel;										// 0x138

	};
	static_assert(sizeof(TNTTaskBarWidget) == 0x140, "TNTTaskBarWidget size isn't 0x140.");
	static_assert(sizeof(TNTTaskBarWidget) <= 0x140, "TNTTaskBarWidget size is upper than 0x140.");
	static_assert(sizeof(TNTTaskBarWidget) >= 0x140, "TNTTaskBarWidget size is lower than 0x140.");
#pragma pack(pop)
}