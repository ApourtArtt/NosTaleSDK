#include "ServChan.h"

ServChan::ServChan()
{
	auto memAddr = PatternScan(
		"\xe8\x00\x00\x00\x00\x66\x8b\x00\x00\x8b\x15\x00\x00\x00\x00\x66\x89\x02\xa1\x00\x00\x00\x00\x8b\x00",
		"x????xx??xx????xxxx????xx",
		11
	);

	address = *(uintptr_t*)memAddr;
	address = *(uintptr_t*)address;
}

short ServChan::GetServer() const
{
	return (*(uintptr_t*)address & 0xff);
}

short ServChan::GetChannel() const
{
	return ((*(uintptr_t*)address >> 0x10) & 0xff);
}
