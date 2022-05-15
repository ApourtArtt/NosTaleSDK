#include "Fps.h"

Fps::Fps() : address(GetAddress())
{
}

void Fps::SetRefreshRate(int RefreshRate)
{
	*(uintptr_t*)address = RefreshRate;
}

void Fps::SetFps(int Fps)
{
	if (Fps == 0) *(uintptr_t*)address = 5000;
	else if (Fps <= 60) *(uintptr_t*)address = 1000 / Fps;
	else *(uintptr_t*)address = 500 / Fps;
}

uintptr_t Fps::GetAddress()
{
	return *(uintptr_t*)PatternScan(
		"\xA3\x60\xC7\x6F\x00\xEB\x0A",
		"x????xx",
		1
	);
}
