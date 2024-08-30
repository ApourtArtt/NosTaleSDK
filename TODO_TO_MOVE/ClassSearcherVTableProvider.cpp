#include <format>
#include <Windows.h>
#include "ClassSearcherVTableProvider.hpp"
#include "../NosTaleSDK/Utils/MemoryHelper.hpp"
#include "../NosTaleSDK/Utils/StringObfuscator.hpp"
#include "../NosTaleSDK/Utils/FormatString.hpp"

ClassSearcherVTableProvider::ClassSearcherVTableProvider(const std::shared_ptr<NosTaleSDK::Interfaces::Logger>& Logger)
	: VTableProvider(Logger)
{
	auto [lpBaseOfDll, SizeOfImage, EntryPoint] = NosTaleSDK::Utils::GetModuleInfo();
	base_ = reinterpret_cast<DWORD>(lpBaseOfDll);
	size_ = SizeOfImage;
	memoryData_.resize(size_);
	memcpy(memoryData_.data(), reinterpret_cast<char*>(base_), size_);

	registerVTableHelper(obf("TEWCustomPanelWidget"));
	registerVTableHelper(obf("TEWLabel"));
	registerVTableHelper(obf("TLBSWidgetList"));
	registerVTableHelper(obf("TNosRevCmdList"));
	registerVTableHelper(obf("TNTLoginWidget"));
}

bool ClassSearcherVTableProvider::RegisterVTableName(const std::string& Pseudonym, const std::string& ClassName)
{
	if (vTables_.contains(Pseudonym))
		return false;

	std::pair<std::string, uintptr_t> pair = { ClassName, 0 };
	vTables_.emplace(Pseudonym, pair);

	return true;
}

[[nodiscard]] uintptr_t ClassSearcherVTableProvider::Get(const std::string& Pseudonym)
{
	if (!vTables_.contains(Pseudonym))
		return 0;

	auto& res = vTables_.at(Pseudonym);
	if (res.second != 0)
		return res.second;

	const auto addr = *reinterpret_cast<uintptr_t*>(search(res.first));
	logger_->Debug(NosTaleSDK::Utils::FormatString(obf("VTable for {} is {}"), Pseudonym.c_str(), addr));
	vTables_[Pseudonym].second = addr;
	return addr;
}

// https://github.com/ApourtArtt/DelphiClassInfo
uintptr_t ClassSearcherVTableProvider::search(const std::string& ClassName)
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

std::string ClassSearcherVTableProvider::getPattern(const std::string& ClassName)
{
	std::string pattern;
	pattern += static_cast<char>(ClassName.size());
	pattern += ClassName;
	return pattern;
}

bool ClassSearcherVTableProvider::load()
{
	return true;
}

bool ClassSearcherVTableProvider::unload()
{
	return true;
}

void ClassSearcherVTableProvider::registerVTableHelper(const std::string& ClassName)
{
	RegisterVTableName(obf("NosTaleSDK::Entwell::Classes::") + ClassName + obf("::VTable"), ClassName);
}
