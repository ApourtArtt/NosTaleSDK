#include "TObject.hpp"

namespace NosTaleSDK::Entwell::DelphiClasses
{
    #pragma pack(push, 1)
    struct TPersistent : TObject
    {
        
    };
    static_assert(sizeof(TPersistent) == 0x4, "TPersistent size is not equal to 0x4.");
    static_assert(sizeof(TPersistent) <= 0x4, "TPersistent size is higher than 0x4.");
    static_assert(sizeof(TPersistent) >= 0x4, "TPersistent size is lower than 0x4.");
    #pragma pack(pop)
}