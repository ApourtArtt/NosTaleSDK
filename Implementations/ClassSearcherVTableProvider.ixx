module;
#include <string>
#include <map>
#include <Windows.h>
#include <Psapi.h>
export module ClassSearcherVTableProvider;
import VTableProvider;
import MemoryUtils;
import Logger;

export class ClassSearcherVTableProvider : public NosTaleSDK::Interfaces::VTableProvider
{
public:
	ClassSearcherVTableProvider(NosTaleSDK::Interfaces::Logger& Logger)
		: NosTaleSDK::Interfaces::VTableProvider(Logger)
	{
		MODULEINFO mInfo = NosTaleSDK::Utils::GetModuleInfo();
		base = (DWORD)mInfo.lpBaseOfDll;
		size = (DWORD)mInfo.SizeOfImage;
		memoryData.resize(size);
		memcpy(memoryData.data(), (char*)base, size);
	}

	[[nodiscard]] bool Load() override
	{
		return true;
	}

	[[nodiscard]] bool Unload() override
	{
		return true;
	}

	bool RegisterPattern(const std::string& ClassName)
	{
		if (patterns.contains(ClassName))
			return false;

		patterns.emplace(ClassName, 0);

		return true;
	}

	[[nodiscard]] uintptr_t Get(const std::string& ClassName) override
	{
		if (!patterns.contains(ClassName))
			return 0;

		auto& res = patterns.at(ClassName);
		if (res != 0)
			return res;

		auto addr = search(ClassName);
		patterns[ClassName] = addr;
		return addr;
	}

private:
	// https://github.com/ApourtArtt/DelphiClassInfo
	uintptr_t search(const std::string& ClassName)
	{
		std::string pattern = getPattern(ClassName);
		uint32_t pos = memoryData.find(pattern);
		if (pos == std::string::npos)
			return 0;
		uint32_t addr = base + pos;

		for (uint32_t j = addr - 4;; j--)
		{
			if (j < base)
				return 0;
			if (*(uint32_t*)j == addr)
			{
				return j - 0x20;
			}
		}
		return 0;
	}

	std::string getPattern(const std::string& className)
	{
		std::string pattern;
		pattern += (char)className.size();
		pattern += className;
		return pattern;
	}

	std::string memoryData;
	uintptr_t base, size;

	std::map<std::string, uintptr_t> patterns;
};