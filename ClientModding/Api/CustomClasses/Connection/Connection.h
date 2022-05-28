#pragma once
#include "ServChan.h"

/**
 * @brief Holds related connection classes.
 */
class Connection
{
public:
	Connection();

	[[nodiscard]] bool Initialize();

	ServChan servChan;

private:
};
