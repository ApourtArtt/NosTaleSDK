#pragma once
#include <string>
#include <vector>

[[nodiscard]] static std::string Join(const std::vector<std::string> strings, const std::string& delimiter = " ", int offset = 0) noexcept
{
	std::string output;

	if (strings.size() > offset) [[unlikely]]
		output = strings[offset];

	for (int i = offset + 1; i < strings.size(); i++) [[likely]]
		output += delimiter + strings[i];

	return output;
}

template<typename T>
std::vector<T> Slice(std::vector<T>& arr, int start, int end)
{
    std::vector<T> result(start - end + 1);
    copy(arr.begin() + start, arr.begin() + end + 1, result.begin());

    return result;
}