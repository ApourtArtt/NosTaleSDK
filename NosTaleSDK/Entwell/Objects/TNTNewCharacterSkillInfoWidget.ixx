module;
#include <stdint.h>
export module TNTNewCharacterSkillInfoWidget;
import TEWCustomFormWidget;
import TNTItemList;
import TNTTimeAniIcon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
	{
		char pad_00BC[52]; //0x00BC
		TNTTimeAniIcon* aSlotsAniIcons[24]; //0x00F0
		char pad_0150[0x10]; //0x0150
		TNTItemList* motionList; // 0x0160
		char pad[128]; // 0x164
	};
	static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E4, "TNTNewCharacterSkillInfoWidget does not have a size of 0x1E4");
#pragma pack(pop)
}