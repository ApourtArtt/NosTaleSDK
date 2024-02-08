module;
#include <stdint.h>
export module TNTNewServerSelectWidget2;
import TEWControlWidgetEX;
import DelphiArray;
import TextStyle;
import Position;
import Bgra;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewServerSelectWidget2 : public TEWControlWidgetEX
	{
		struct TEWCustomPanelWidget* communityPanel;				// 0x068 
		struct TEWLabel* communityPanelTitle;						// 0x06C
		struct TEWListView* communitiesNames;						// 0x070
		struct TEWGraphicButtonWidget* hoverCommunitiesButton;		// 0x074
		TEWCustomPanelWidget* selectedCommunityPanel;				// 0x078
		uint32_t unknown25;											// 0x07C
		TEWControlWidgetEX* communitiesTracker;						// 0x080
		int16_t serversId[50];										// 0x084
		TEWControlWidgetEX* communitiesCircles;						// 0x0E8 DelphiArray
		TEWCustomPanelWidget* serverPanel;							// 0x0EC
		TEWCustomPanelWidget* channelPanel;							// 0x0F0
		TEWLabel* serverPanelTitle;									// 0x0F4
		TEWLabel* channelPanelTitle;								// 0x0F8
		TEWListView* serversNames;									// 0x0FC
		TEWListView* channelsNames;									// 0x100
		TEWGraphicButtonWidget* hoverServersButton;					// 0x104
		TEWGraphicButtonWidget* hoverChannelButton;					// 0x108
		TEWCustomPanelWidget* selectedServerPanel;					// 0x10C
		TEWCustomPanelWidget* selectedChannelPanel;					// 0x110
		TEWControlWidgetEX* serversCircles;							// 0x114 DelphiArray
		TEWControlWidgetEX* channelsCircles;						// 0x118 DelphiArray
		TEWControlWidgetEX* serversTracker;							// 0x11C
		struct TEWButtonWidget* exitButton;							// 0x120
		uint8_t unknown42;											// 0x124
		Properties::Graphical::TextStyle mouseOnYTextStyle;			// 0x125
		Properties::Graphical::TextStyle hoveredTextStyle;			// 0x130
		Properties::Graphical::TextStyle selectedTextStyle;			// 0x13B
		Properties::Graphical::TextStyle unused;					// 0x146
		Properties::Graphical::TextStyle normalChannelTextStyle;	// 0x151
		Properties::Graphical::TextStyle busyChannelTextStyle;		// 0x15C
		Properties::Graphical::TextStyle fullChannelTextStyle;		// 0x167
		Properties::Graphical::TextStyle unused2;					// 0x172
		Properties::Graphical::TextStyle unused3;					// 0x17D
		Properties::Graphical::TextStyle unused4;					// 0x188
		Properties::Logical::Position exitButtonPosition;			// 0x193
		uint32_t unknown58;											// 0x197
		Properties::Graphical::Bgra channelCirclesNormalColors;		// 0x19B
		Properties::Graphical::Bgra channelCirclesSpecialColors;	// 0x19F
		char unknown62;												// 0x1A3
		int32_t selectedServerId;									// 0x1A4
		uint32_t unknown64;											// 0x1A8 related to server
		int32_t currentChannelId;									// 0x1AC
		uint32_t unknown65;											// 0x1B0
		int32_t currentCommunityId;									// 0x1B4
		int32_t selectedCommunityId;								// 0x1B8
		uint32_t unknown68;											// 0x1BC
		uint32_t unknown69;											// 0x1C0
		int16_t serversIdList[70];									// 0x1C4
		bool isThereAnyChannel;										// 0x250
		char unknown72[3];											// 0x251
		uint32_t unknown73;											// 0x254
		uint32_t unknown74;											// 0x258
		uint32_t unknown75;											// 0x25C
		int16_t unknown76;											// 0x260
		uint16_t unknown77;											// 0x262
	};
	static_assert(sizeof(TNTNewServerSelectWidget2) == 0x264, "TNTPartySummaryInfoWidget size isn't 0x264.");
	static_assert(sizeof(TNTNewServerSelectWidget2) <= 0x264, "TNTPartySummaryInfoWidget size is upper than 0x264.");
	static_assert(sizeof(TNTNewServerSelectWidget2) >= 0x264, "TNTPartySummaryInfoWidget size is lower than 0x264.");
#pragma pack(pop)
}