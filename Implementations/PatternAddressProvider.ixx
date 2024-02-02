module;
#include <format>
#include <string>
#include <map>
#include <memory>
#include <vector>
export module PatternAddressProvider;
import AddressProvider;
import MemoryUtils;
import Logger;

export class PatternAddressProvider final : public NosTaleSDK::Interfaces::AddressProvider
{
public:
	struct PatternDef
	{
		const char* pattern;
		std::string mask;
		int32_t offset = 0;
		uint32_t startFrom = 0;
	};

	explicit PatternAddressProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger)
		: AddressProvider(Logger)
	{}

	bool RegisterPattern(const std::string& AddressName, const PatternDef& Pattern)
	{
		if (patterns_.contains(AddressName) || results_.contains(AddressName))
			return false;

		patterns_.emplace(AddressName, Pattern);
		results_.emplace(AddressName, std::vector<uintptr_t>());

		return true;
	}

	[[nodiscard]] uintptr_t GetOne(const std::string& AddressName) override
	{
		if (!patterns_.contains(AddressName) || !results_.contains(AddressName))
		{
			logger_->Error(std::format("PatternScan failed for {}", AddressName.c_str()));
			return 0;
		}

		if (const auto& res = results_.at(AddressName); res.size() > 0)
		{
			logger_->Debug(std::format("PatternScan successfully found [{}] for {}", res.at(0), AddressName.c_str()));
			return res.at(0);
		}

		const auto& [pattern, mask, offset, startFrom] = patterns_.at(AddressName);
		const auto address = NosTaleSDK::Utils::PatternScan(pattern, mask.c_str(), offset, startFrom);

		results_[AddressName].push_back(address);
		logger_->Debug(std::format("PatternScan successfully found [{}] for {}", address, AddressName.c_str()));
		return address;
	}

	[[nodiscard]] std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) override
	{
		if (!patterns_.contains(AddressName) || !results_.contains(AddressName))
			return {};

		// ReSharper disable once CppUseStructuredBinding
		const auto& pattern = patterns_.at(AddressName);

		if (auto& res = results_.at(AddressName); HowMany == static_cast<int32_t>(res.size()))
			return res;

		uint32_t startFrom = pattern.startFrom;
		while (HowMany > 0 || HowMany == -1)
		{
			HowMany--;
			uintptr_t currAdd = NosTaleSDK::Utils::PatternScan(pattern.pattern, pattern.mask.c_str(), pattern.offset, startFrom);
			if (currAdd == 0)
				break;
			results_[AddressName].push_back(currAdd);
			startFrom = currAdd;
		}

		return results_.at(AddressName);
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

	std::map<std::string, PatternDef> patterns_;
	std::map<std::string, std::vector<uintptr_t>> results_;
};