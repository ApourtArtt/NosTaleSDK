module;
#include <stdint.h>
export module TNTCharacterInventoryInfoWidget;
import TEWCustomFormWidget;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCharacterInventoryInfoWidget : public TEWCustomFormWidget
	{
		char unknown38[4];												// 0x0BC
		uint8_t scrollWidgetChangedCount;								// 0x0C0
		uint8_t unknown39;												// 0x0C1
		uint16_t nbTotalItemByScrollStep;								// 0x0C2
		uint32_t unknown40;												// 0x0C4
		char unknown44[4];												// 0x0C8
		Properties::Logical::DelphiWString* unknown45;						// 0x0CC
		char unknown46[20];												// 0x0D0
		struct TEWLabel* unknown47;										// 0x0E4
		struct TNTIconWidget* icon[60];									// 0x0E8
		TEWLabel* equipTabLabel;										// 0x1D8
		TEWLabel* mainTabLabel;											// 0x1DC
		TEWLabel* etcTabLabel;											// 0x1E0
		TEWLabel* additionalTabLabel;									// 0x1E4
		struct TEWRollOverButtonWidget* additionalBtn;					// 0x1E8
		TEWRollOverButtonWidget* fishBtn;								// 0x1EC
		struct TEWGraphicButtonWidget* equipBtn;						// 0x1F0
		TEWGraphicButtonWidget* mainBtn;								// 0x1F4
		TEWGraphicButtonWidget* etcBtn;									// 0x1F8
		struct TEWScrollBar* scrollBar;									// 0x1FC
		int8_t equipNumberBaseItem;										// 0x200
		int8_t mainNumberBaseItem;										// 0x201
		int8_t etcNumberBaseItem;										// 0x202
		uint8_t equipScrollBarIndex;									// 0x203
		uint8_t mainScrollBarIndex;										// 0x204
		uint8_t etcScrollBarIndex;										// 0x205
		char unknown48[2];												// 0x206
		TEWRollOverButtonWidget* sortBtn;								// 0x208
		TEWCustomPanelWidget* strangePanel;								// 0x20D
		TEWLabel* unknownLabel;											// 0x210
		uint8_t indexTab;												// 0x214
		char unknown49[7];												// 0x215
		struct TNTItemList* equipItemList;								// 0x21C
		TNTItemList* mainItemList;										// 0x220
		TNTItemList* etcItemList;										// 0x224
		uint32_t unknown50; 											// 0x228 related to wear sp
		char unknown51[4];												// 0x22C
		uint8_t classType;												// 0x230
		char unknown52[3];												// 0x231
		uint32_t goldAmount;											// 0x234
		char unknown53[8];												// 0x231
		uint32_t unknown54;												// 0x240
		struct TNTIconWidgetAddEvent* deleteBtn;						// 0x244
		struct TNTCardInventoryInfoWidget* cardInventoryWidget;			// 0x248
		struct TNTCostumeInventoryInfoWidget* costumeInventoryWidget;	// 0x24C
		struct TNTFishInfoWidget* fishWidget;							// 0x250
		struct TNTNewCharacterStandardInfoWidget* characterInfoWidget;	// 0x254
		uint32_t unknown55;												// 0x258
	};
	static_assert(sizeof(TNTCharacterInventoryInfoWidget) == 0x25C, "TNTCharacterInventoryInfoWidget size isn't 0x25C.");
	static_assert(sizeof(TNTCharacterInventoryInfoWidget) <= 0x25C, "TNTCharacterInventoryInfoWidget size is upper than 0x25C.");
	static_assert(sizeof(TNTCharacterInventoryInfoWidget) >= 0x25C, "TNTCharacterInventoryInfoWidget size is lower than 0x25C.");
#pragma pack(pop)
}