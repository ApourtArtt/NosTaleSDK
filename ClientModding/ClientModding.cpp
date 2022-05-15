#include "ClientModding.h"
#include "Api/DelphiClasses/ClassSearcher.h" // TODO: To delete once using widgets

ClientModding::ClientModding()
	//: connection()
	//, mapCommon()
	//, discordMng()
{
	//discordMng.Start();

	ClassSearcher::Initialize({
		"TEWButtonWidget",
		"TEWCaptionBar",
		"TEWControlWidget",
		"TEWControlWidgetEvent",
		"TEWControlWidgetEX",
		"TEWCustomButtonWidget",
		"TEWCustomFormWidget",
		"TEWCustomPanelWidget",
		"TEWEditWidget",
		"TEWGraphicButtonWidget",
		"TEWLabel",
		"TEWLabels",
		"TEWMoveWidget",
		"TEWScrollBar",
		"TEWScrollBarThumb",
		"TEWScrollBarTrack",
		"TGameRootWidget",
		"TLBSCamera",
		"TLBSRotDamper",
		"TLBSWidget",
		"TLBSWidgetList",
		"TList",
		"TNTCoverIcon",
		"TNTDataList",
		"TNTGameOptionWidget",
		"TNTIconWidget",
		"TNTItemList",
		"TNTMonsterSummaryInfoWidget",
		"TNTNewCharacterSkillInfoWidget",
		"TNTNewCharacterStandardInfoWidget",
		"TNTQuickSlotWidget",
		"TNTTimeAniIcon",
		"TObject",
		"TSceneManager",
	});
	Logger::log("Classes loaded OK");
}

ClientModding::~ClientModding()
{

}

void ClientModding::Tick()
{
}
