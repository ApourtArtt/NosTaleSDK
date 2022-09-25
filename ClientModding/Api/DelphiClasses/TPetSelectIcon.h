#pragma once
#include "TNTTimeAniIcon.h"
#pragma pack(push, 1)

class TPetSelectIcon : public TNTTimeAniIcon
{
public:
	[[nodiscard]] explicit TPetSelectIcon(TLBSWidget* Parent, Border Border)
		: TNTTimeAniIcon(ClassSearcher::GetClassInfoFromName("TPetSelectIcon").GetVTable(), 0x1, Parent, nullptr, Border)
	{}

protected:
	char unknown21[0x14]; // 0x110
};
static_assert(sizeof(TPetSelectIcon) == 0x124, "TPetSelectIcon does not have a size of 0x124");

#pragma pack(pop)
