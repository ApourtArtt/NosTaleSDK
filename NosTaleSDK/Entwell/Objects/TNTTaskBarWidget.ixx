module;
#include <stdint.h>
export module TNTTaskBarWidget;
import TEWCustomFormWidget;
import TEWGraphicButtonWidget;
import TEWLabel;
import TNTNewCharacterStandardInfoWidget;
import TNTWebBrowserFormWidget;
import TEWRollOverButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTaskBarWidget : public TEWCustomFormWidget
	{
		char unknown22[4];											// 0xBC
		TEWRollOverButtonWidget* helpButton;						// 0xC0
		TEWRollOverButtonWidget* noteButton;						// 0xC4
		TEWRollOverButtonWidget* parcelButton;						// 0xC8
		TEWRollOverButtonWidget* characterButton;					// 0xCC
		TEWRollOverButtonWidget* skillsButton;						// 0xD0
		TEWRollOverButtonWidget* inventoryButton;					// 0xD4
		TEWRollOverButtonWidget* unusedButton;						// 0xD8
		TEWRollOverButtonWidget* questButton;						// 0xDC
		TEWRollOverButtonWidget* minilandButton;					// 0xE0
		TEWRollOverButtonWidget* messengerButton;					// 0xE4
		TEWRollOverButtonWidget* unusedButton2;						// 0xE8
		TNTWebBrowserFormWidget* guideWebBrowser;					// 0xEC
		void* nosmallMemoWrite;										// 0xF0 TNTNosMallMemoWrite
		void* nosmallTotalWidget;									// 0xF4 TNTNosMallTotalWidget
		TNTNewCharacterStandardInfoWidget* characterInfoWidget;		// 0xF8
		void* skillInfoWidget;										// 0xFC TNTNewCharacterSkillInfoWidget
		void* inventoryInfoWidget;									// 0x100 TNTNewCharacterInventoryInfoWidget
		void* nosmallTotalWidget2;									// 0x104 TNTNosMallTotalWidget
		TNTNewCharacterStandardInfoWidget* characterInfoWidget2;	// 0x104
		void* miniLandInfoWidget;									// 0x108 TNTMinilandInfoWidget
		void* buddyWidget;											// 0x10C TBuddyWidget
		void* systemOptionWidget;									// 0x110 TNTSystemOptionWidget
		TEWCustomPanelWidget* hintWidget;							// 0x114
		TEWLabel* hintText;											// 0x118
		TEWGraphicButtonWidget* gameConfigurationBtn;				// 0x11C
		TEWGraphicButtonWidget* returnBtn;							// 0x120
		TEWGraphicButtonWidget* serverSelectBtn;					// 0x124
		TEWGraphicButtonWidget* quitGameBtn;						// 0x128
		TEWLabel* gameConfigBtnLabel;								// 0x12C
		TEWLabel* returnBtnLabel;									// 0x130
		TEWLabel* serverSelectBtnLabel;								// 0x134
		TEWLabel* quitGameLabel;									// 0x138

	};
	static_assert(sizeof(TNTTaskBarWidget) == 0x140, "TNTTaskBarWidget does not have a size of 0x140.");
#pragma pack(pop)
}