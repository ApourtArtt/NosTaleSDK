#pragma once
#include <vector>
#include <string>

static std::vector<std::string> Split(const std::string& origin, const std::string& delim)
{
    std::vector<std::string> ret;
    std::string::size_type n = 0;
    std::string::size_type cur = n;
    std::string::size_type delim_size = delim.size();
    while (true)
    {
        n = origin.find(delim, cur);
        if (n == std::string::npos)
        {
            ret.emplace_back(origin, cur, origin.size()-cur);
            break;
        }
        ret.emplace_back(origin, cur, n - cur);
        cur = n + delim_size;
    }
    return ret;
}