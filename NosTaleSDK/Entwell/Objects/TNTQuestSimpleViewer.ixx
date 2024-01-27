module;
#include <stdint.h>
export module TNTQuestSimpleViewer;
import TEWMoveWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTQuestSimpleViewer : public TEWMoveWidget
	{
		struct TEWGraphicButtonWidget* collapseBtn;							//0x80
		struct TEWGraphicButtonWidget* openQuestsBtn;							//0x84
		struct TEWCustomPanelWidget* innerPanel;								//0x88	
		struct TEWGraphicButtonWidget* collapseQuestDetailsBtn;				//0x8C
		struct TEWStringListView* innerPanelText;								//0x90
		struct TEWStringListView* unknownText;									//0x94
		struct TEWControlWidgetEX* questMarker;								//0x98
		struct TEWCustomPanelWidget* unknownPanels[8];							//0x9C
		struct TEWGraphicButtonWidget* secondCollapseQuestDetailsBtn;			//0xBC
		struct TEWGraphicButtonWidget* unknownBtns[7];							//0xC0
		struct TEWStringListView* unknownTexts[16];							//0xDC
		struct TEWControlWidgetEX* unknownControlWidgets[8];					//0x11C
		struct TEWCustomPanelWidget* unknownPanels2[5];						//0x13C
		struct TEWGraphicButtonWidget* unknownBtns2[5];						//0x150
		struct TEWStringListView* unknownBtns3[10];							//0x164
		bool isInnerPanelOpen;											//0x18C
		char unknown14[3];												//0x18D
		int16_t innerPanelHeight;										//0x190
		char unknown15[26];												//0x192
	};
	static_assert(sizeof(TNTQuestSimpleViewer) == 0x1AC, "TNTQuestSimpleViewer does not have a size of 0x1AC");
#pragma pack(pop)
}