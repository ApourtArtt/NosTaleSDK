// https://github.com/ApourtArtt/DelphiClassInfo

#pragma once
#include <string>
#include <map>
#include <vector>
#include <Windows.h>
#include <Psapi.h>

class ClassInfo
{
public:
	ClassInfo() : size(0), addrPtrVTable(0), addrPtrName(0) {}
	ClassInfo(const std::string& Name, uint32_t Size, uintptr_t AddrPtrVTable, uintptr_t AddrPtrName)
		: name(Name)
		, size(Size)
		, addrPtrVTable(AddrPtrVTable)
		, addrPtrName(AddrPtrName)
	{}

	const std::string& GetName() const				{ return name; }
	const uint32_t GetClassSize() const				{ return size; }
	const uintptr_t GetAddressPtrVTable() const		{ if (addrPtrVTable == 0) return 0; return addrPtrVTable; }
	const uintptr_t GetVTable() const				{ if (addrPtrVTable == 0) return 0; return *(uintptr_t*)addrPtrVTable; }
	const uintptr_t GetAddressPtrName() const		{ if (addrPtrName == 0) return 0; return  addrPtrName + 1; }
	const uintptr_t GetNameAddress() const			{ if (addrPtrName == 0) return 0; return *(uintptr_t*)(addrPtrName + 1); }

private:
	std::string name;
	uint32_t size;
	uintptr_t addrPtrVTable;
	uintptr_t addrPtrName;
};

class ClassSearcher
{
public:
	static bool Initialize(const std::vector<std::string>& ClassesName)
	{
		MODULEINFO mInfo = { 0 };
		HMODULE hModuleExe = GetModuleHandle(NULL);
		if (hModuleExe == 0) return false;
		GetModuleInformation(GetCurrentProcess(), hModuleExe, &mInfo, sizeof(MODULEINFO));
		DWORD base = (DWORD)mInfo.lpBaseOfDll;
		DWORD size = (DWORD)mInfo.SizeOfImage;
		data.resize(size);
		memcpy(data.data(), (char*)base, size);

		for (auto& className : ClassesName)
		{
			std::string pattern = getPattern(className);
			int pos = data.find(pattern);
			if (pos == std::string::npos)
				return false;
			int addr = base + pos;

			for (int32_t i = addr - 4;; i--)
			{
				if (i < base)
					return false;
				if (*(int32_t*)i == addr)
				{
					classesInfo.emplace(className, ClassInfo(className, *(int32_t*)(i + 4), i - 0x20, *(int32_t*)i));
					break;
				}
			}
		}
	}

	static const ClassInfo& GetClassInfoFromName(const std::string& ClassName)
	{
		return classesInfo[ClassName];
	}

private:
	static std::string getPattern(const std::string& className)
	{
		std::string pattern;
		pattern += className.size();
		pattern += className;
		return pattern;
	}

	inline static std::string data;
	inline static std::map<std::string, ClassInfo> classesInfo;
};
