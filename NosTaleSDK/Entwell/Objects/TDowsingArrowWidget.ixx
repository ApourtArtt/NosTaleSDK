module;
#include <stdint.h>
export module TDowsingArrowWidget;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	template<typename T> class TNTIntHeadList;
	export struct TDowsingArrowWidget : public TEWControlWidget
	{
		TNTIntHeadList<void*>* list; // It is not void* but something that stores int16_t posX, int16_t posY, int32_t mapId and maybe some other data - can it be used to exploit hidden TS research?
	};
	static_assert(sizeof(TDowsingArrowWidget) == 0x6C, "TDowsingArrowWidget does not have a size of 0x6C.");

#pragma pack(pop)
}