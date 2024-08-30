#include "PatternAddressProvider.hpp"
#include <format>
#include "../NosTaleSDK/Utils/MemoryHelper.hpp"
#include "../NosTaleSDK/Utils/StringObfuscator.hpp"
#include "../NosTaleSDK/Utils/FormatString.hpp"

PatternAddressProvider::PatternAddressProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger)
	: AddressProvider(Logger)
{
	RegisterPattern(obf("NosTaleSDK::Entwell::Classes::TLBSWidgetHandler::Singleton"), {
		"\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3",
		obf("xx????xxxx????x????x"), 2, 0, { 0, 0 } });

	RegisterPattern(obf("NosTaleSDK::Entwell::Classes::TEWRingArrayList::Singleton"), {
		"\xe8\x00\x00\x00\x00\x84\xc0\x74\x00\xa1\x00\x00\x00\x00\x8b\x00\xe8\x00\x00\x00\x00\x8b\xd8\x8b\x47\x60\x89\x43\x60",
		obf("x????xxx?x????xxx????xxxxxxxx"), 10, 0 });

	RegisterPattern(obf("NosTaleSDK::Entwell::Classes::TNTCItemDataList::Singleton"), {
		obf("\xe8\x00\x00\x00\x00\x8b\x55\xa0\x58\xe8\x00\x00\x00\x00\x75\x00\xa1\x00\x00\x00\x00\x8b\x10\xff\x52\x08\x8b\xd7\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00"),
		"x????xxxxx????x?x????xxxxxxxx????x????", 17, 0 });

	RegisterPattern(obf("NosTaleSDK::Entwell::Classes::TNTClient::Singleton"), {
		obf("\x2e\x00\x00\x00\xa1\xb4\x51\x73\x00\x8b\x00\xba\x10\x5c\x6c\x00"),
		"xxxx?????xxx????", 5, 0 });

	RegisterPattern(obf("NosTaleSDK::Entwell::Value::ServerId"), {
		obf("\xe8\x00\x00\x00\x00\x66\x8b\x00\x00\x8b\x15\x00\x00\x00\x00\x66\x89\x02\xa1\x00\x00\x00\x00\x8b\x00"),
		"x????xx??xx????xxxx????xx", 11, 0 });

}

bool PatternAddressProvider::RegisterPattern(const std::string& AddressName, const PatternDef& Pattern)
{
	if (patterns_.contains(AddressName) || results_.contains(AddressName))
		return false;

	patterns_.emplace(AddressName, Pattern);
	results_.emplace(AddressName, std::vector<uintptr_t>());

	return true;
}

bool PatternAddressProvider::RegisterPattern(const std::string& AddressName, uintptr_t Address)
{
	if (results_.contains(AddressName))
		results_[AddressName].push_back(Address);
	else
		results_.emplace(AddressName, Address);

	return true;
}

[[nodiscard]] uintptr_t PatternAddressProvider::GetOne(const std::string& AddressName)
{
	if (!results_.contains(AddressName))
	{
		logger_->Error(NosTaleSDK::Utils::FormatString(obf("PatternScan failed for {}"), AddressName.c_str()));
		return 0;
	}

	if (const auto& res = results_.at(AddressName); res.size() > 0)
	{
		logger_->Debug(NosTaleSDK::Utils::FormatString(obf("PatternScan successfully found [{}] for {}"), res.at(0), AddressName.c_str()));
		return res.at(0);
	}

	if (!patterns_.contains(AddressName))
	{
		logger_->Error(NosTaleSDK::Utils::FormatString(obf("No pattern for {}"), AddressName.c_str()));
		return 0;
	}

	const auto& [pattern, mask, offset, startFrom, deref] = patterns_.at(AddressName);
	uintptr_t address = NosTaleSDK::Utils::PatternScan(pattern, mask.c_str(), offset, startFrom);
	if (address == 0)
	{
		logger_->Error(NosTaleSDK::Utils::FormatString(obf("PatternScan failed for {}"), AddressName.c_str()));
		return 0;
	}

	for (uint32_t i = 0; i < deref.size(); i++)
	{
		address = *(uintptr_t*)(address + deref[i]);
		if (address == 0)
		{
			logger_->Error(NosTaleSDK::Utils::FormatString(obf("PatternScan failed for {}"), AddressName.c_str()));
			return 0;
		}
	}

	results_[AddressName].push_back(address);
	logger_->Debug(NosTaleSDK::Utils::FormatString(obf("PatternScan successfully found [{}] for {}"), address, AddressName.c_str()));
	return address;
}

[[nodiscard]] std::vector<uintptr_t> PatternAddressProvider::GetMany(const std::string& AddressName, int32_t HowMany)
{
	if (!patterns_.contains(AddressName) || !results_.contains(AddressName))
		return {};

	const auto& pattern = patterns_.at(AddressName);

	if (auto& res = results_.at(AddressName); HowMany == static_cast<int32_t>(res.size()))
		return res;

	uint32_t startFrom = pattern.startFrom;
	while (HowMany != 0)
	{
		HowMany--;
		uintptr_t currAdd = NosTaleSDK::Utils::PatternScan(pattern.pattern, pattern.mask.c_str(), pattern.offset, startFrom);
		if (currAdd == 0)
		{
			logger_->Error(NosTaleSDK::Utils::FormatString(obf("PatternScan failed for {}"), AddressName.c_str()));
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