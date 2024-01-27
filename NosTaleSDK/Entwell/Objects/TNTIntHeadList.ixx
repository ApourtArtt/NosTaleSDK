module;
#include <stdint.h>
export module TNTIntHeadList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
	template<class T>
	class IntListElement
	{
	public:
		[[nodiscard]] int32_t getVnum() noexcept { return vnum; }
		[[nodiscard]] T getValue() noexcept { return value; }

	protected:
		int32_t vnum;
		T value;
	};

#pragma pack(push, 1)
	export template<class T>
	struct TNTIntHeadList : public TNTDataList<IntListElement<T>*>
	{
	};
	static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) == 0x10, "TNTIntHeadList does not have a size of 0x10.");
#pragma pack(pop)
}