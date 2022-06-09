#pragma once
#include "TGameRootWidget.h"
#include "../../MemoryHelper/PatternScan.h"
#pragma pack(push, 1)

class TLBSWidgetHandler : public TObject
{
public:
	TGameRootWidget* getGameRootWidget()
	{
		if (gameRootWidget == nullptr)
		{
			auto _ = Logger::PushPopModuleName("TLBSWidgetHandler");
			Logger::Error("gameRootWidget == nullptr");
		}
		return gameRootWidget;
	}

	static TLBSWidgetHandler* getNosTaleUniqueInstance()
	{
		static bool init = false;
		static void* patternAddr = nullptr;

		if (!init)
		{
			auto _ = Logger::PushPopModuleName("TLBSWidgetHandler");

			init = true;
			patternAddr = PatternScan(
				"\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3",
				"xx????xxxx????x????x", 2
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Fail scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			Logger::Success("Successfully initialized");
		}

		// Note: if it gets delete-d and new-ed, a refresh of the dereferenced address will be required.
		// Since I don't know if this object ever gets deleted (I HIGHLY doubt it), I am not handling it.
		return **(TLBSWidgetHandler***)patternAddr;
	}

private:
	int32_t TNosTaleMainF; // 0x0004 TODO: class named TNosTaleMainF
	uint16_t aspectRatioX; // 0x0008
	uint16_t aspectRatioY; // 0x000A
	TGameRootWidget* gameRootWidget; // 0x000C
	char padding[0x2f8];
};
static_assert(sizeof(TLBSWidgetHandler) == 0x0308, "TLBSWidgetHandler does not have a size of 0x0308.");

#pragma pack(pop)
