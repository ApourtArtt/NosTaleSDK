module;
#include <string>
#include <map>
#include <memory>
#include <Windows.h>
#include <Psapi.h>
export module ClassSearcherVTableProvider;
import VTableProvider;
import MemoryUtils;
import Logger;

export class ClassSearcherVTableProvider final : public NosTaleSDK::Interfaces::VTableProvider
{
public:
	ClassSearcherVTableProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger)
		: NosTaleSDK::Interfaces::VTableProvider(Logger)
	{
		auto [lpBaseOfDll, SizeOfImage, EntryPoint] = NosTaleSDK::Utils::GetModuleInfo();
		base_ = reinterpret_cast<DWORD>(lpBaseOfDll);
		size_ = SizeOfImage;
		memoryData_.resize(size_);
		memcpy(memoryData_.data(), reinterpret_cast<char*>(base_), size_);
	}

	bool RegisterPattern(const std::string& ClassName)
	{
		if (patterns_.contains(ClassName))
			return false;

		patterns_.emplace(ClassName, 0);

		return true;
	}

	[[nodiscard]] uintptr_t Get(const std::string& ClassName) override
	{
		if (!patterns_.contains(ClassName))
			return 0;

		if (const auto& res = patterns_.at(ClassName); res != 0)
			return res;

		const auto addr = search(ClassName);
		patterns_[ClassName] = addr;
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

	std::map<std::string, uintptr_t> patterns_;
};