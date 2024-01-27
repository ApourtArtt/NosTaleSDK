module;
#include <stdint.h>
export module TNosTaleGame;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosTaleGame : public TObject
	{
		struct TGameRootWidget* gameRootWidget;  //0x04
		uint32_t lastPulseSecond;               //0x08 pulse lastPulseSecond 0
		uint32_t sessionTime;                   //0x0C This number is used to time when the "pulse" packet is going to be sent
		int32_t isCharacterConnected;           //0x10
	};
	static_assert(sizeof(TNosTaleGame) == 0x14, "TNosTaleGame does not have a size of 0x14.");
#pragma pack(pop)
}