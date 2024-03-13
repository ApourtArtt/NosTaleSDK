#include <cstdint>

#pragma pack(push, 1)
struct TObject
{
    uint32_t vTable; // 0x00
};
static_assert(sizeof(TObject) == 0x4, "TObject size is not equal to 0x4.");
static_assert(sizeof(TObject) <= 0x4, "TObject size is higher than 0x4.");
static_assert(sizeof(TObject) >= 0x4, "TObject size is lower than 0x4.");
#pragma pack(pop)
