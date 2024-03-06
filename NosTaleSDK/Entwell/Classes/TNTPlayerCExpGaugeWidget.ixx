module;
export module TNTPlayerCExpGaugeWidget;
import TEWCustomPanelWidget;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTPlayerCExpGaugeWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];									// 0x0A4
		struct TEWGuageWithHintWidget* levelGauge;			// 0x0A8
		TEWGuageWithHintWidget* jobGauge;					// 0x0AC
		TEWGuageWithHintWidget* heroLevelGauge;				// 0x0B0
		TEWCustomPanelWidget* unknown31;					// 0x0B4
		TEWGuageWithHintWidget* rageGauge;					// 0x0B8
		TEWCustomPanelWidget* unknown32;					// 0x0BC
		TEWCustomPanelWidget* unknown33;					// 0x0C0
		TEWCustomPanelWidget* unknown34;					// 0x0C4
		Properties::Logical::DelphiArray<char>* unknown35;	// 0x0C8
		Properties::Logical::DelphiArray<char>* unknown36;	// 0x0CC
		Properties::Logical::DelphiArray<char>* unknown37;	// 0x0D0
		Properties::Logical::DelphiArray<char>* unknown38;	// 0x0D4
		Properties::Logical::DelphiArray<char>* unknown39;	// 0x0D8
		Properties::Logical::DelphiArray<char>* unknown40;	// 0x0DC
		Properties::Logical::DelphiArray<char>* unknown41;	// 0x0E0
		Properties::Logical::DelphiArray<char>* unknown42;	// 0x0E4
		char unknown43[8];									// 0x0E8
	};
	static_assert(sizeof(TNTPlayerCExpGaugeWidget) == 0xF0, "TNTPlayerCExpGaugeWidget size isn't 0xF0.");
	static_assert(sizeof(TNTPlayerCExpGaugeWidget) <= 0xF0, "TNTPlayerCExpGaugeWidget size is upper than 0xF0.");
	static_assert(sizeof(TNTPlayerCExpGaugeWidget) >= 0xF0, "TNTPlayerCExpGaugeWidget size is lower than 0xF0.");
#pragma pack(pop)
}