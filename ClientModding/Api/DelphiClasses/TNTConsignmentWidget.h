#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWControlWidgetMouseEvent.h"
#include "../../MemoryHelper/PatternScan.h"
#pragma pack(push, 1)

class TNTConsignmentWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTConsignmentWidget";

	[[nodiscard]] static TNTConsignmentWidget* getNtInstance()
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\x66\xba\x0a\x00\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x66\xba\x0a\x00\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00",
				"xxxxx????x????xxxxx????x????", 5
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Failed scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			Logger::Success("Successfully initialized");
		}

		// Note: if it gets delete-d and new-ed, a refresh of the dereferenced address will be required.
		// Since I don't know if this object ever gets deleted (I HIGHLY doubt it), I am not handling it.
		return **(TNTConsignmentWidget***)patternAddr;
	}

	TEWControlWidgetMouseEvent* getBodyWidget() { return content; }

protected:
	char unknown20[4]; // 0x00BC
	TEWControlWidgetMouseEvent* content; // 0x00C0
	char unknown21[0x6B8]; // 0x00C4
};
static_assert(sizeof(TNTConsignmentWidget) == 0x077C, "TNTConsignmentWidget does not have a size of 0x077C.");

#pragma pack(pop)
