#include <cstdint>

#pragma pack(push, 1)
struct TObject
{
    uint32_t vTable; // 0x00 
};
static_assert(sizeof(TObject) == 0x4, "TObject does not have a size of 0x4.");
static_assert(sizeof(TObject) <= 0x4, "TObject's size is higher than 0x4.");
static_assert(sizeof(TObject) >= 0x4, "TObject's size is lower than 0x4.");
#pragma pack(pop)