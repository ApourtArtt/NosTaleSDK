module;
#include <string>
#include <map>
#include <memory>
#include <Windows.h>
#include <Psapi.h>
#include <format>
export module ClassSearcherVTableProvider;
import VTableProvider;
import MemoryUtils;
import Logger;

export class ClassSearcherVTableProvider final : public NosTaleSDK::Interfaces::VTableProvider
{
public:
	explicit ClassSearcherVTableProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger)
		: VTableProvider(Logger)
	{
		auto [lpBaseOfDll, SizeOfImage, EntryPoint] = NosTaleSDK::Utils::GetModuleInfo();
		base_ = reinterpret_cast<DWORD>(lpBaseOfDll);
		size_ = SizeOfImage;
		memoryData_.resize(size_);
		memcpy(memoryData_.data(), reinterpret_cast<char*>(base_), size_);
	}

	bool RegisterVTableName(const std::string& Pseudonym, const std::string& ClassName)
	{
		if (vTables_.contains(Pseudonym))
			return false;

		std::pair<std::string, uintptr_t> pair = { ClassName, 0 };
		vTables_.emplace(Pseudonym, pair);

		return true;
	}

	[[nodiscard]] uintptr_t Get(const std::string& Pseudonym) override
	{
		if (!vTables_.contains(Pseudonym))
			return 0;

		auto& res = vTables_.at(Pseudonym);
		if (res.second != 0)
			return res.second;

		const auto addr = search(res.first);
		logger_->Info(std::format("VTable for {} is {}", Pseudonym.c_str(), addr));
		vTables_[Pseudonym].second = addr;
		return addr;
	}

private:
	// https://github.com/ApourtArtt/DelphiClassInfo
	uintptr_t search(const std::string& ClassName)
	{
		const std::string pattern = getPattern(ClassName);
		const uint32_t pos = memoryData_.find(pattern);
		if (pos == std::string::npos)
			return 0;
		const uint32_t addr = base_ + pos;

		for (uint32_t j = addr - 4;; j--)
		{
			if (j < base_)
				return 0;
			if (*reinterpret_cast<uint32_t*>(j) == addr)
			{
				return j - 0x20;
			}
		}
	}

	static std::string getPattern(const std::string& ClassName)
	{
		std::string pattern;
		pattern += static_cast<char>(ClassName.size());
		pattern += ClassName;
		return pattern;
	}

	bool load() override
	{
		return true;
	}

	bool unload() override
	{
		return true;
	}

	std::string memoryData_;
	uintptr_t base_, size_;

	std::map<std::string, std::pair<std::string, uintptr_t>> vTables_;
};