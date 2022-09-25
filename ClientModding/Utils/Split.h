#pragma once
#include <vector>
#include <string>

[[nodiscard]] static std::vector<std::string> Split(const std::string& origin, const std::string& delim) noexcept
{
    std::vector<std::string> ret;
    std::string::size_type n = 0;
    std::string::size_type cur = n;
    std::string::size_type delim_size = delim.size();
    while (true) [[likely]]
    {
        n = origin.find(delim, cur);
        if (n == std::string::npos) [[unlikely]]
        {
            ret.emplace_back(origin, cur, origin.size()-cur);
            break;
        }
        ret.emplace_back(origin, cur, n - cur);
        cur = n + delim_size;
    }
    return ret;
}
