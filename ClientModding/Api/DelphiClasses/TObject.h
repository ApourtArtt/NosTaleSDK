#pragma once
#include <stdint.h>
#include "ClassSearcher.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TObject structure.
 */
class TObject
{
public:
	TObject()
		: vTable(ClassSearcher::GetClassInfoFromName("TObject").GetVTable())
	{}

	TObject(uint32_t vTableAddy)
		: vTable(vTableAddy)
	{}

	uint32_t getVTable() const { return vTable; }

	template<typename T>
	static T* deepCopy(T* Object)
	{
		T* output = new T;
		memcpy(output, Object, sizeof(*Object));
		return output;
	}

protected:
	uint32_t vTable; // 0x00
};
static_assert(sizeof(TObject) == 0x04, "TObject does not have a size of 0x04.");

#pragma pack(pop)
