module;
export module TNTNewCharacterSkillInfoWidget;
import TEWCustomFormWidget;
import Icon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];															// 0x0BC
		struct TEWGraphicButtonWidget* trainingBtn;									// 0x0C0
		struct TEWGraphicButtonWidget* skillBtn;									// 0x0C4
		struct TEWGraphicButtonWidget* tattooBtn;									// 0x0C8
		struct TEWGraphicButtonWidget* motionBtn;									// 0x0CC
		int32_t tabIndex;															// 0x0D0
		struct TEWCustomPanelWidget* mainDisplayBg;									// 0x0D4
		struct TEWCustomPanelWidget* descPanel;										// 0x0D8
		struct TEWCustomPanelWidget* tabTitlePanel;									// 0x0DC
		struct TEWCustomPanelWidget* skillBonusLabelPanel;							// 0x0E0
		struct TEWLabel* tabTitleLabel;												// 0x0E4
		struct TEWLabel* skillBonusLabel;											// 0x0E8
		struct TEWLabel* cpRemainingLabel;											// 0x0EC
		struct TNTTimeAniIcon* aSlotsAniIcons[24];         							// 0x0F0
		int16_t unknown39;															// 0x150
		int16_t nbIconDisplayed;													// 0x152
		struct TNTItemList* trainingList;											// 0x154
		struct TNTItemList* skillList;												// 0x158
		struct TNTItemList* tattooList;												// 0x15C
		struct TNTItemList* motionList;         									// 0x160
		struct TEWScrollBar* scrollBar;												// 0x164
		struct TNTIconWidget* skillBonusIcons[4];       							// 0x168
		struct TEWStringListView* description;										// 0x178
		struct TEWLabel* unknownLabel;												// 0x17C
		struct TEWLabel* trainingTabLabel;											// 0x180
		struct TEWLabel* skillTabLabel;												// 0x184
		struct TEWLabel* tattooTabLabel;											// 0x188
		struct TEWLabel* motionTabLabel;											// 0x18C
		struct TEWCustomPanelWidget* tattooDescPanel[2];							// 0x190
		struct TEWLabels* tattooName[2];											// 0x198
		struct TEWStringListView* tattooDesc[2];									// 0x1A0
		int32_t unknown40;															// 0x1A8
		int32_t unknown41;															// 0x1AC
		struct TEWGraphicButtonWidget* skillRefundBtn;								// 0x1B0
		struct TEWStringListView* skillRefundBtnText;								// 0x1B4
		struct NosTaleSDK::Entwell::Properties::Graphical::Icon* selectedIconProp;	// 0x1B8
		uint32_t unknown42;															// 0x1BC
		uint32_t iconId;															// 0x1C0
		char unknown43[8];															// 0x1C4
		uint32_t unknown44;															// 0x1CC
		char unknown45[4];															// 0x1D0
		uint32_t unknown46;															// 0x1D4
		bool unknown47;																// 0x1D8
		char unknown48[15];       													// 0x1D9
	};
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E8, "TNTNewCharacterSkillInfoWidget size isn't 0x1E8.");
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) <= 0x1E8, "TNTNewCharacterSkillInfoWidget size is upper than 0x1E8.");
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) >= 0x1E8, "TNTNewCharacterSkillInfoWidget size is lower than 0x1E8.");
#pragma pack(pop)
}