#pragma once
#include "TNTDataList.h"

// TODO: Find uknown values (probably 2 integers)

/**
 * @brief Representation of the game TNTItemList structure.
 */
template<class T>
class TNTItemList : public TNTDataList<T>
{

protected:
	char uknown[8];
};