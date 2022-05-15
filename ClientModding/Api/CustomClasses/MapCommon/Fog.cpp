#include "Fog.h"

Fog::Fog() : address(GetAddress())
{
}

void Fog::SetBlue(uint8_t Blue)
{
	*(uint8_t*)(address + 0x00) = Blue;
}

void Fog::SetGreen(uint8_t Green)
{
	*(uint8_t*)(address + 0x01) = Green;
}

void Fog::SetRed(uint8_t Red)
{
	*(uint8_t*)(address + 0x02) = Red;
}

void Fog::SetFirstFog(float Value)
{
	*(float*)(address + 0x08) = Value;
}

void Fog::SetSecondFog(float Value)
{
	*(float*)(address + 0x0C) = Value;
}

uintptr_t Fog::GetAddress()
{
	return *(uintptr_t*)*(uintptr_t*)PatternScan(
		"\x80\x3D\x00\x00\x00\x00\x00\x74\x00\xA1\x00\x00\x00\x00\x8B\x00\x50\x6A",
		"xx????xx?x????xxxx",
		10
	);
}
