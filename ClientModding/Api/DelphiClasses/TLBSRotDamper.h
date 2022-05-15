#pragma once
#include "TObject.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TLBSRotDamper struture.
 */
class TLBSRotDamper : public TObject
{
public:
	char pad_0004[84]; //0x0004
	float min; //0x0058
	float max; //0x005C
	float def; //0x0060
}; //Size: 0x0064
static_assert(sizeof(TLBSRotDamper) == 0x64, "TLBSRotDamper does not have a size of 0x64");

#pragma pack(pop)