#pragma once
#include <cstring>
#include <charconv>
#include <optional>

template <typename T>
[[nodiscard]] static std::optional<T> ToNumber(const char* str) noexcept
{
	if (!str) [[unlikely]]
		return std::nullopt;

	T var = 0;
	auto [p, ec] = std::from_chars(str, str + strlen(str), var);

	if (ec != std::errc()) [[unlikely]]
		return std::nullopt;

	return { static_cast<T>(var) };
}

template <typename T>
[[nodiscard]] static T ToNumberUnsafe(const char* str) noexcept
{
	T var = 0;
	std::from_chars(str, str + strlen(str), var);
	return static_cast<T>(var);
}