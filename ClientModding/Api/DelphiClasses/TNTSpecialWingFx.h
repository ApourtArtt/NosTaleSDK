#pragma once
#include "TObject.h"
#pragma pack(push, 1)

typedef int32_t wingStyleId;

class TNTSpecialWingFx
{
public:
	void setWingStyle(wingStyleId WingStyle) { wingStyle = WingStyle; }
	void setWeirdCounter(int32_t WeirdCounter) { weirdCounter = WeirdCounter; }

protected:
	char unknown[0xC]; // 0x00
	int32_t weirdCounter; // 0x0C
	wingStyleId wingStyle; // 0x10
	char unknown2[4]; // 0x14
};
static_assert(sizeof(TNTSpecialWingFx) == 0x18, "TNTSpecialWingFx does not have a size of 0x18.");

#pragma pack(pop)
