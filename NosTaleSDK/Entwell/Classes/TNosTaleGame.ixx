module;
#include <stdint.h>
export module TNosTaleGame;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosTaleGame : public TObject
	{
		struct TGameRootWidget* gameRootWidget;	// 0x004
		uint32_t lastPulseSecond;               // 0x008 pulse lastPulseSecond 0
		uint32_t sessionTime;                   // 0x00C This number is used to time when the "pulse" packet is going to be sent
		int32_t isCharacterConnected;           // 0x010
	};
	static_assert(sizeof(TNosTaleGame) == 0x14, "TNosTaleGame size isn't 0x14.");
	static_assert(sizeof(TNosTaleGame) <= 0x14, "TNosTaleGame size is upper than 0x14.");
	static_assert(sizeof(TNosTaleGame) >= 0x14, "TNosTaleGame size is lower than 0x14.");
#pragma pack(pop)
}