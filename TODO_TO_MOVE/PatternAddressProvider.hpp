#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>7
#include "../NosTaleSDK/Interfaces/AddressProvider.hpp"

class PatternAddressProvider final : public NosTaleSDK::Interfaces::AddressProvider
{
public:
	struct PatternDef
	{
		const char* pattern;
		std::string mask;
		int32_t offset = 0;
		uint32_t startFrom = 0;
		std::vector<int32_t> derefOffsets = {};
	};

	explicit PatternAddressProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger);

	// Find address from a pattern
	bool RegisterPattern(const std::string& AddressName, const PatternDef& Pattern);
	// Directly set an address
	bool RegisterPattern(const std::string& AddressName, uintptr_t Address);

	[[nodiscard]] uintptr_t GetOne(const std::string& AddressName) override;
	[[nodiscard]] std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) override;

private:
	bool load() override;
	bool unload() override;

	std::map<std::string, PatternDef> patterns_;
	std::map<std::string, std::vector<uintptr_t>> results_;
};