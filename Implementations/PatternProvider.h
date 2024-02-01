#pragma once

#include <cstdint>
#include <map>
#include <string>
import AddressProvider;

class PatternProvider : public NosTaleSDK::Providers::AddressProvider
{
public:
	struct PatternDef
	{
		std::string pattern;
		std::string mask;
		int32_t offset;
		uint32_t startFrom;
	};

	bool RegisterPattern(const std::string& AddressName, const PatternDef& Pattern)
	{
		if (patterns_.contains(AddressName))
			return false;

		patterns_.emplace(AddressName, Pattern);

		return true;
	}

	[[nodiscard]] uintptr_t Get(const std::string& AddressName) override
	{
		if (!patterns_.contains(AddressName))
			return 0;
		auto [pattern, mask, offset, startFrom] = patterns_.at(AddressName);
		return NosTaleSDK::Utils::PatternScan(pattern.c_str(), mask.c_str(), offset, startFrom);
	}

private:
	std::map<std::string, PatternDef> patterns_;
};