#pragma once
#include <string>
#include <map>
#include <memory>
#include "../NosTaleSDK/Interfaces/VTableProvider.hpp"

class ClassSearcherVTableProvider final : public NosTaleSDK::Interfaces::VTableProvider
{
public:
	explicit ClassSearcherVTableProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger);

	bool RegisterVTableName(const std::string& Pseudonym, const std::string& ClassName);
	[[nodiscard]] uintptr_t Get(const std::string& Pseudonym) override;

private:
	// https://github.com/ApourtArtt/DelphiClassInfo
	uintptr_t search(const std::string& ClassName);
	static std::string getPattern(const std::string& ClassName);
	bool load() override;
	bool unload() override;

	std::string memoryData_;
	uintptr_t base_, size_;

	std::map<std::string, std::pair<std::string, uintptr_t>> vTables_;
};