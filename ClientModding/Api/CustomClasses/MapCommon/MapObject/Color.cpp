#include "Color.h"

Color::Color() : address(GetAddress())
{
	//Logger::log("%x", address);
}

void Color::SetRed(float Red)
{
	*(float*)(address + 0x04) = Red;
}

void Color::SetGreen(float Green)
{
	*(float*)(address + 0x08) = Green;
}

void Color::SetBlue(float Blue)
{
	*(float*)(address + 0x0C) = Blue;
}

void Color::SetRedDelta(float Red)
{
	*(float*)(address + 0x24) = Red;
}

void Color::SetGreenDelta(float Green)
{
	*(float*)(address + 0x28) = Green;
}

void Color::SetBlueDelta(float Blue)
{
	*(float*)(address + 0x2C) = Blue;
}

uintptr_t Color::GetAddress()
{
	return *(uintptr_t*)*(uintptr_t*)PatternScan(
		"\xA5\xA5\xA5\xA5\x5F\x5E\xA1\x00\x00\x00\x00\x56\x57\x8B\xF7\x8D\x78\x04\xA5\xA5\xA5\xA5\x5F\x5E",
		"xxxxxxx????xxxxxxxxxxxxx",
		7
	);
}
