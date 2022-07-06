// https://github.com/ApourtArtt/DelphiClassInfo

#pragma once
#include <string>
#include <map>
#include <vector>
#include <Windows.h>
#include <Psapi.h>
#include "../../Utils/Logger.h"

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
	[[nodiscard]] static bool Initialize()
	{
		auto _ = Logger::PushPopModuleName("ClassSearcher");

		std::vector<std::string> classesName{
			"TEWButtonWidget",
			"TEWCaptionBar",
			"TEWControlWidget",
			"TEWControlWidgetEvent",
			"TEWControlWidgetEX",
			"TEWCustomButtonWidget",
			"TEWCustomFormWidget",
			"TEWCustomPanelWidget",
			"TEWEditWidget",
			"TEWGraphicButtonWidget",
			"TEWLabel",
			"TEWLabels",
			"TEWMoveWidget",
			"TEWParentMoveWidget",
			"TEWScrollBar",
			"TEWScrollBarThumb",
			"TEWScrollBarTrack",
			"TGameRootWidget",
			"TLBSCamera",
			"TLBSRotDamper",
			"TLBSWidget",
			"TLBSWidgetHandler",
			"TLBSWidgetList",
			"TList",
			"TMapPlayerObj",
			"TNTCItemDataList",
			"TNTConsignmentWidget",
			"TNTConstStringList",
			"TNTCoverIcon",
			"TNTDataList",
			"TNTGameOptionWidget",
			"TNTIconWidget",
			"TNTIntHeadList",
			"TNTItemList",
			"TNTLoginWidget",
			"TNTMaskingGaugeWidget",
			"TNTMonsterSummaryInfoWidget",
			"TNTNewCharacterSkillInfoWidget",
			"TNTNewCharacterStandardInfoWidget",
			"TNTNewServerSelectWidget2",
			"TNTNonMemIntHeadList",
			"TNTPartySummaryInfoWidget",
			"TNTQuickSlotWidget",
			"TNTSpecialaListInfoWidget",
			"TNTSpecialDragonFx",
			"TNTSpecialWingFx",
			"TNTTimeAniIcon",
			"TObject",
			"TPlayerObjManager",
			"TSceneManager",
		};

		MODULEINFO mInfo = { 0 };
		HMODULE hModuleExe = GetModuleHandle(nullptr);
		if (hModuleExe == 0)
		{
			Logger::Error("Failed getting module handle");
			return false;
		}
		GetModuleInformation(GetCurrentProcess(), hModuleExe, &mInfo, sizeof(MODULEINFO));
		DWORD base = (DWORD)mInfo.lpBaseOfDll;
		DWORD size = (DWORD)mInfo.SizeOfImage;
		data.resize(size);
		memcpy(data.data(), (char*)base, size);

		for (size_t i = 0; i < classesName.size(); i++)
		{
			std::string pattern = getPattern(classesName[i]);
			int pos = data.find(pattern);
			if (pos == std::string::npos)
			{
				Logger::Error("Failed finding class %s", classesName[i].c_str());
				return false;
			}
			int addr = base + pos;

			for (int32_t j = addr - 4;; j--)
			{
				if (j < base)
				{
					Logger::Error("Failed finding class %s", classesName[i].c_str());
					return false;
				}
				if (*(int32_t*)j == addr)
				{
					classesInfo.emplace(classesName[i], ClassInfo(classesName[i], *(int32_t*)(j + 4), j - 0x20, *(int32_t*)j));
					Logger::Log("Class %s = %x", classesName[i].c_str(), j - 0x20);
					break;
				}
			}
		}

		Logger::Success("Successfully initialized");
		return true;
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
