#pragma once
#include "TNTIconWidget.h"
#include "../../../../../Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TNTCoverIcon structure.
 */
class TNTCoverIcon : public TNTIconWidget
{
public:
	TNTCoverIcon(TLBSWidget* Parent, Border Border, Bgra Filter)
		: TNTIconWidget(ClassSearcher::GetClassInfoFromName("TNTCoverIcon").GetVTable()
		, 0x1, Parent, nullptr, Border)
		, filter(Filter)
	{

	}

	void setFilter(Bgra Filter) { filter = Filter; }
	void setUseFilter(bool UseFilter) { useFilter = UseFilter; }

	Bgra getFilter() const { return filter; }
	bool isUsingFilter() const { return useFilter; } bool getUseFilter() const { return isUsingFilter(); }

protected:
	char unknown21[4];	// 0xC4
	Bgra filter;		// 0xC8
	bool useFilter;		// 0xCC
	char unknown22[3];	// 0xCD
};
static_assert(sizeof(TNTCoverIcon) == 0xD0, "TNTCoverIcon does not have a size of 0xD0.");

#pragma pack(pop)