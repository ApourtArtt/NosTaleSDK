#include "PatternAddressProvider.hpp"
#include <format>
#include "../NosTaleSDK/Utils/MemoryHelper.hpp"

bool PatternAddressProvider::RegisterPattern(const std::string& AddressName, const PatternDef& Pattern)
{
	if (patterns_.contains(AddressName) || results_.contains(AddressName))
		return false;

	patterns_.emplace(AddressName, Pattern);
	results_.emplace(AddressName, std::vector<uintptr_t>());

	return true;
}

[[nodiscard]] uintptr_t PatternAddressProvider::GetOne(const std::string& AddressName)
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

	const auto& [pattern, mask, offset, startFrom, deref] = patterns_.at(AddressName);
	uintptr_t address = NosTaleSDK::Utils::PatternScan(pattern, mask.c_str(), offset, startFrom);
	if (address == 0)
	{
		logger_->Error(std::format("PatternScan failed for {}", AddressName.c_str()));
		return 0;
	}

	for (uint32_t i = 0; i < deref.size(); i++)
	{
		address = *(uintptr_t*)(address + deref[i]);
		if (address == 0)
		{
			logger_->Error(std::format("PatternScan failed for {}", AddressName.c_str()));
			return 0;
		}
	}

	results_[AddressName].push_back(address);
	logger_->Debug(std::format("PatternScan successfully found [{}] for {}", address, AddressName.c_str()));
	return address;
}

[[nodiscard]] std::vector<uintptr_t> PatternAddressProvider::GetMany(const std::string& AddressName, int32_t HowMany)
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
		{
			logger_->Error(std::format("PatternScan failed for {}", AddressName.c_str()));
			return {};
		}
		results_[AddressName].push_back(currAdd);
		startFrom = currAdd;
	}

	return results_.at(AddressName);
}

bool PatternAddressProvider::load()
{
	return true;
}

bool PatternAddressProvider::unload()
{
	return true;
}