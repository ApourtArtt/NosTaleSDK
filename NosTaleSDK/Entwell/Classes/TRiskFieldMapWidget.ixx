module;
export module TRiskFieldMapWidget;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TRiskFieldMapWidget : public TEWControlWidget
	{
		char unknown[1160];
	};
	static_assert(sizeof(TRiskFieldMapWidget) == 0x4F0, "TRiskFieldMapWidget size isn't 0x4F0.");
	static_assert(sizeof(TRiskFieldMapWidget) <= 0x4F0, "TRiskFieldMapWidget size is upper than 0x4F0.");
	static_assert(sizeof(TRiskFieldMapWidget) >= 0x4F0, "TRiskFieldMapWidget size is lower than 0x4F0.");
#pragma pack(pop)
}