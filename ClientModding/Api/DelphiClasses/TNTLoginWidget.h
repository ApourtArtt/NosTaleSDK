#pragma once
#include "TLBSWidget.h"
#pragma pack(push, 1)

class TNTLoginWidget : public TLBSWidget
{
public:
	static constexpr std::string_view NAME = "TNTLoginWidget";

protected:
	char unknown3[0x18]; // 0x24
};
static_assert(sizeof(TNTLoginWidget) == 0x3C, "TNTLoginWidget does not have a size of 0x3C.");

#pragma pack(pop)
