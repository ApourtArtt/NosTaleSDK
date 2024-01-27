module;
#include <stdint.h>
export module TNTNewFamilyInfoWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewFamilyInfoWidget : public TEWCustomPanelWidget
	{
		char pad_00A4[316]; //0x00A4
	};
	static_assert(sizeof(TNTNewFamilyInfoWidget) == 0x1E0, "TNTNewFamilyInfoWidget does not have a size of 0x1E0");
#pragma pack(pop)
}