#pragma once
#include "TLBSWidget.h"
#pragma pack(push, 1)

class TGameRootWidget : public TLBSWidget
{

};
static_assert(sizeof(TGameRootWidget) == 0x24, "TGameRootWidget does not have a size of 0x24");

#pragma pack(pop)
