#pragma once
#include "TNTIntHeadList.h"
#pragma pack(push, 1)

typedef TNTIntHeadList<char*> TNTConstStringList;
static_assert(sizeof(TNTConstStringList) == 0x10, "TNTConstStringList does not have a size of 0x10.");

#pragma pack(pop)
