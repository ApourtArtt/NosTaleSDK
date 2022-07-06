#pragma once
#include <stdint.h>

class Callback
{
public:
	template <typename CbFn, typename CbArg>
	Callback(CbFn Fn, CbArg Arg)
		: fn((int32_t)Fn)
		, arg((int32_t)Arg)
	{}

	Callback()
		: fn(0)
		, arg(0)
	{}

	[[nodiscard]] int32_t getFunc() noexcept { return fn; }
	[[nodiscard]] int32_t getArg() noexcept { return arg; }

private:
	int32_t fn; // 0x00
	int32_t arg; // 0x04
};
