#pragma once
#include "TObject.h"
#pragma pack(push, 1)

typedef int32_t auraStyleId;

class TNTSpecialDragonFx
{
public:
	void setAuraStyle(auraStyleId AuraStyle) { auraStyle = AuraStyle; }
	void setWeirdCounter(int32_t WeirdCounter) { weirdCounter = WeirdCounter; }

protected:
	char unknown[0xC]; // 0x00
	int32_t weirdCounter; // 0x0C
	auraStyleId auraStyle; // 0x10
	char unknown2[4]; // 0x14
};
static_assert(sizeof(TNTSpecialDragonFx) == 0x18, "TNTSpecialDragonFx does not have a size of 0x18.");

#pragma pack(pop)
