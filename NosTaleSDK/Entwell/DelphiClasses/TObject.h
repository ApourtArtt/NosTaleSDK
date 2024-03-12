#include <stdint.h>

#pragma pack(push, 1)
struct TObject
{
	uint32_t vTable; // 0x00
};
static_assert(sizeof(TObject) == 0x04, "TObject does not have a size of 0x04.");
#pragma pack(pop)