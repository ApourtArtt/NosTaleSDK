module;
#include <string>
#include <map>
export module PatternAddressProvider;
import AddressProvider;
import MemoryUtils;

export class PatternAddressProvider : public NosTaleSDK::Providers::AddressProvider
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

	[[nodiscard]] uintptr_t GetOne(const std::string& AddressName) override
	{
		if (!patterns.contains(AddressName))
			return 0;

		auto& pattern = patterns.at(AddressName);
		return NosTaleSDK::Utils::PatternScan(pattern.pattern.c_str(), pattern.mask.c_str(), pattern.offset, pattern.startFrom);
	}

	[[nodiscard]] std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) override
	{
		if (!patterns.contains(AddressName))
			return {};

		auto& pattern = patterns.at(AddressName);

		std::vector<uintptr_t> adds;
		if (HowMany > 0)
			adds.reserve(HowMany);

		uint32_t startFrom = pattern.startFrom;
		while (HowMany > 0 || HowMany == -1)
		{
			HowMany--;
			uintptr_t currAdd = NosTaleSDK::Utils::PatternScan(pattern.pattern.c_str(), pattern.mask.c_str(), pattern.offset, startFrom);
			if (currAdd == 0)
				break;
			adds.push_back(currAdd);
			startFrom = currAdd;
		}

		return adds;
	}

private:
	std::map<std::string, PatternDef> patterns;
};