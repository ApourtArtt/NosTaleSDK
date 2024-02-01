module;
#include <stdint.h>
export module TNTQuestSimpleViewer;
import TEWMoveWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTQuestSimpleViewer : public TEWMoveWidget
	{
		struct TEWGraphicButtonWidget* collapseBtn;				// 0x080
		TEWGraphicButtonWidget* openQuestsBtn;					// 0x084
		struct TEWCustomPanelWidget* innerPanel;				// 0x088	
		TEWGraphicButtonWidget* collapseQuestDetailsBtn;		// 0x08C
		struct TEWStringListView* innerPanelText;				// 0x090
		TEWStringListView* unknown23;							// 0x094
		struct TEWControlWidgetEX* questMarker;					// 0x098
		TEWCustomPanelWidget* unknown24[8];						// 0x09C
		TEWGraphicButtonWidget* secondCollapseQuestDetailsBtn;	// 0x0BC
		TEWGraphicButtonWidget* unknown25[7];					// 0x0C0
		TEWStringListView* unknown26[16];						// 0x0DC
		TEWControlWidgetEX* unknownControlWidgets[8];			// 0x11C
		TEWCustomPanelWidget* unknown27[5];						// 0x13C
		TEWGraphicButtonWidget* unknown28[5];					// 0x150
		TEWStringListView* unknown29[10];						// 0x164
		bool isInnerPanelOpen;									// 0x18C
		char unknown30[3];										// 0x18D
		int32_t unknown31;										// 0x190
		int32_t titleBarHeight;									// 0x194
		int32_t unknown32;										// 0x198
		char unknown33[16];										// 0x19C
	};
	static_assert(sizeof(TNTQuestSimpleViewer) == 0x1AC, "TNTQuestSimpleViewer size isn't 0x1AC.");
	static_assert(sizeof(TNTQuestSimpleViewer) <= 0x1AC, "TNTQuestSimpleViewer size is upper than 0x1AC.");
	static_assert(sizeof(TNTQuestSimpleViewer) >= 0x1AC, "TNTQuestSimpleViewer size is lower than 0x1AC.");
#pragma pack(pop)
}