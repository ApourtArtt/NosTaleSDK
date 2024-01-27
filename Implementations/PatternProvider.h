#pragma once

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
		if (patterns.contains(AddressName))
			return false;

		patterns.emplace(AddressName, Pattern);

		return true;
	}

	[[nodiscard]] uintptr_t Get(const std::string& AddressName) override
	{
		if (!patterns.contains(AddressName))
			return 0;
		auto pattern = patterns.at(AddressName);
		return NosTaleSDK::Utils::PatternScan(pattern.pattern.c_str(), pattern.mask.c_str(), pattern.offset, pattern.startFrom);
	}

private:
	std::map<std::string, PatternDef> patterns;
};