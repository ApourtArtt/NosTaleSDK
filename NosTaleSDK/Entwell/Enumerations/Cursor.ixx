module;
#include <stdint.h>
export module Cursor;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class Cursor : uint8_t
	{
		WINDOWS = 0x00,
		NORMAL = 0x01,
		STOP = 0x02,
		HAND = 0x03,
		HAND_PRESSED = 0x04,
		FINGER = 0x05,
		TALK = 0x06,
		ATTACK = 0x07,
		VERTICAL_ARROWS = 0x08,
		PET_ATTACK = 0x09,
		PET_MOVE = 0x0A,
		TEXT = 0xFC
	};
#pragma pack(pop)
}