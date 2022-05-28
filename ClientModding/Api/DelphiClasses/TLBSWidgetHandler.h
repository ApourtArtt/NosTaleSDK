#pragma once
#include "TGameRootWidget.h"
#pragma pack(push, 1)

class TLBSWidgetHandler : public TObject
{
public:
	TGameRootWidget* getGameRootWidget() { return gameRootWidget; }

	static TLBSWidgetHandler* getNosTaleUniqueInstance()
	{
		auto patternAddr = PatternScan(
			"\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3",
			"xx????xxxx????x????x",
			2
		);

		Logger::Log("[TLBSWidgetHandler] Pattern address: %x", patternAddr);

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