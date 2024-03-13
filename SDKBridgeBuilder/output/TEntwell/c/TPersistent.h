#include <cstdint>

#pragma pack(push, 1)
struct TPersistent
{
    uint32_t vTable; // 0x00 Inherited from TObject
};
static_assert(sizeof(TPersistent) == 0x4, "TPersistent does not have a size of 0x4.");
static_assert(sizeof(TPersistent) <= 0x4, "TPersistent's size is higher than 0x4.");
static_assert(sizeof(TPersistent) >= 0x4, "TPersistent's size is lower than 0x4.");
#pragma pack(pop)