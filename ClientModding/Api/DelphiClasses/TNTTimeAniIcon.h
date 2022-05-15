#pragma once
#include "TNTIconWidget.h"
#pragma pack(push, 1)

class TNTTimeAniIcon : public TNTIconWidget
{
public:
	char pad_00CC[48]; //0x00CC
	uint32_t coolDownProgressBgra; //0x00FC
	uint32_t currentCoolDownTime; //0x0100 (ms)
	uint32_t coolDownTime; //0x0104 (ms)
	char pad_0108[4]; //0x0108
	uint8_t isBackGroundTransparent; //0x010C
	char pad_010D[1]; //0x010D
	uint8_t isOnCooldown; //0x010E
	char pad_010F[1]; //0x010F
}; //Size: 0x0110
static_assert(sizeof(TNTTimeAniIcon) == 0x110);


#pragma pack(pop)
