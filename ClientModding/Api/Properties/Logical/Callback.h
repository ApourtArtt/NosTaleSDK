#pragma once
#include <stdint.h>

/**
 * @brief Game callback representation mainly used for adding funtionality to widgets.
 */
class Callback
{
public:
	template <typename CbFn, typename CbArg>
	Callback(CbFn CallbackAddress, CbArg CallbackWidget)
		: callbackAddress((int32_t)CallbackAddress)
		, callbackArgument((int32_t)CallbackWidget)
	{}

	Callback()
		: callbackAddress(0)
		, callbackArgument(0)
	{}

private:
	int32_t callbackAddress;	// 0x00
	int32_t callbackArgument;	// 0x04
};
