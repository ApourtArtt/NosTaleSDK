#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TNTSpecialaListInfoWidget /* Yes, they really typo-ed there. */ : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTSpecialaListInfoWidget";

protected:
	char unknown20[0x420]; // 0xBC
};
static_assert(sizeof(TNTSpecialaListInfoWidget) == 0x04DC, "TNTSpecialaListInfoWidget does not have a size of 0x04DC.");

#pragma pack(pop)
