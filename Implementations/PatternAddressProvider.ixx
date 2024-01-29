module;
#include <string>
#include <map>
export module PatternAddressProvider;
import AddressProvider;
import MemoryUtils;
import Logger;

export class PatternAddressProvider : public NosTaleSDK::Interfaces::AddressProvider
{
public:
	struct PatternDef
	{
		std::string pattern;
		std::string mask;
		int32_t offset;
		uint32_t startFrom;
	};

	PatternAddressProvider(std::shared_ptr<NosTaleSDK::Interfaces::Logger> Logger)
		: NosTaleSDK::Interfaces::AddressProvider(Logger)
	{}

	bool RegisterPattern(const std::string& AddressName, const PatternDef& Pattern)
	{
		if (patterns.contains(AddressName) || !results.contains(AddressName))
			return false;

		patterns.emplace(AddressName, Pattern);
		results.emplace(AddressName, std::vector<uintptr_t>());

		return true;
	}

	[[nodiscard]] uintptr_t GetOne(const std::string& AddressName) override
	{
		if (!patterns.contains(AddressName) || !results.contains(AddressName))
			return 0;

		auto& res = results.at(AddressName);
		if (res.size() > 0)
			return res[0];

		auto& pattern = patterns.at(AddressName);
		auto address = NosTaleSDK::Utils::PatternScan(pattern.pattern.c_str(), pattern.mask.c_str(), pattern.offset, pattern.startFrom);
		results[AddressName].push_back(address);
		return address;
	}

	[[nodiscard]] std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) override
	{
		if (!patterns.contains(AddressName) || !results.contains(AddressName))
			return {};

		auto& pattern = patterns.at(AddressName);

		auto& res = results.at(AddressName);
		if (HowMany == int32_t(res.size()))
			return res;

		uint32_t startFrom = pattern.startFrom;
		while (HowMany > 0 || HowMany == -1)
		{
			HowMany--;
			uintptr_t currAdd = NosTaleSDK::Utils::PatternScan(pattern.pattern.c_str(), pattern.mask.c_str(), pattern.offset, startFrom);
			if (currAdd == 0)
				break;
			results[AddressName].push_back(currAdd);
			startFrom = currAdd;
		}

		return results.at(AddressName);
	}

private:
	bool load() override
	{
		return true;
	}

	bool unload() override
	{
		return true;
	}

	std::map<std::string, PatternDef> patterns;
	std::map<std::string, std::vector<uintptr_t>> results;
};