module;
#include <stdint.h>
export module TNTNonMemIntHeadList;
import TEWGraphicButtonWidget;
import TNTIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<class T>
	struct TNTNonMemIntHeadList : public TNTIntHeadList<T>
	{
	};
	static_assert(sizeof(TNTNonMemIntHeadList<void*>) == 0x10, "TNTNonMemIntHeadList does not have a size of 0x10.");
#pragma pack(pop)
}