module;
#include <stdint.h>
export module TNTNewCharacterSkillInfoWidget;
import TEWCustomFormWidget;
import Icon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];								// 0x0BC
		struct TEWGraphicButtonWidget* trainingBtn;		// 0x0C0
		TEWGraphicButtonWidget* skillBtn;				// 0x0C4
		TEWGraphicButtonWidget* tattooBtn;				// 0x0C8
		TEWGraphicButtonWidget* motionBtn;				// 0x0CC
		int32_t tabIndex;								// 0x0D0
		TEWCustomPanelWidget* mainDisplayBg;			// 0x0D4
		TEWCustomPanelWidget* descPanel;				// 0x0D8
		TEWCustomPanelWidget* tabTitlePanel;			// 0x0DC
		TEWCustomPanelWidget* skillBonusLabelPanel;		// 0x0E0
		struct TEWLabel* tabTitleLabel;					// 0x0E4
		TEWLabel* skillBonusLabel;						// 0x0E8
		TEWLabel* cpRemainingLabel;						// 0x0EC
		struct TNTTimeAniIcon* aSlotsAniIcons[24];      // 0x0F0
		int16_t unknown39;								// 0x150
		int16_t nbIconDisplayed;						// 0x152
		struct TNTItemList* trainingList;				// 0x154
		TNTItemList* skillList;							// 0x158
		TNTItemList* tattooList;						// 0x15C
		TNTItemList* motionList;         				// 0x160
		struct TEWScrollBar* scrollBar;					// 0x164
		struct TNTIconWidget* skillBonusIcons[4];       // 0x168
		struct TEWStringListView* description;			// 0x178
		TEWLabel* unknownLabel;							// 0x17C
		TEWLabel* trainingTabLabel;						// 0x180
		TEWLabel* skillTabLabel;						// 0x184
		TEWLabel* tattooTabLabel;						// 0x188
		TEWLabel* motionTabLabel;						// 0x18C
		TEWCustomPanelWidget* tattooDescPanel[2];		// 0x190
		struct TEWLabels* tattooName[2];				// 0x198
		TEWStringListView* tattooDesc[2];				// 0x1A0
		int32_t unknown40;								// 0x1A8
		int32_t unknown41;								// 0x1AC
		TEWGraphicButtonWidget* skillRefundBtn;			// 0x1B0
		TEWStringListView* skillRefundBtnText;			// 0x1B4
		Properties::Graphical::Icon* selectedIconProp;	// 0x1B8
		uint32_t unknown42;								// 0x1BC
		uint32_t iconId;								// 0x1C0
		char unknown43[8];								// 0x1C4
		uint32_t unknown44;								// 0x1CC
		char unknown45[4];								// 0x1D0
		uint32_t unknown46;								// 0x1D4
		bool unknown47;									// 0x1D8
		char unknown48[15];       						// 0x1D9
	};
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E8, "TNTNewCharacterSkillInfoWidget size isn't 0x1E8.");
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) <= 0x1E8, "TNTNewCharacterSkillInfoWidget size is upper than 0x1E8.");
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) >= 0x1E8, "TNTNewCharacterSkillInfoWidget size is lower than 0x1E8.");
#pragma pack(pop)
}