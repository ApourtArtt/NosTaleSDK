module;
#include <stdint.h>
export module Cursor;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	enum class Cursor : uint8_t
	{
		Windows = 0x00,
		Normal = 0x01,
		Stop = 0x02,
		Hand = 0x03,
		HandPressed = 0x04,
		Finger = 0x05,
		Talk = 0x06,
		Attack = 0x07,
		VerticalArrows = 0x08,
		PetAttack = 0x09,
		PetMove = 0x0A,
		Text = 0xFC
	};
#pragma pack(pop)
}