#pragma once
#include <stdint.h>

class Callback
{
public:
	template <typename CbFn, typename CbArg>
	Callback(CbFn Fn, CbArg Arg)
		: fb((int32_t)Fn)
		, arg((int32_t)Arg)
	{}

	Callback()
		: fb(0)
		, arg(0)
	{}

private:
	int32_t fb; // 0x00
	int32_t arg; // 0x04
};
