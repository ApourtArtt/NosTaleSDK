module;
#include <cstdint>
export module TNTDataList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

    // Template declaration for TNTDataList
    export template<class T>
        struct TNTDataList : public TList<T>
    {
        // Constructors can be added here if needed
    };

    static_assert(sizeof(TNTDataList<void*>) == 0x10, "TNTDataList does not have a size of 0x10.");

#pragma pack(pop)
}
