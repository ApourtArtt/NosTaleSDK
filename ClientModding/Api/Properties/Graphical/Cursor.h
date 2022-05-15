#pragma once
#include <stdint.h>

// TODO: Add documentation

enum class Cursor : int8_t
{
	// There are some cursors < 0 but will they be ever used ?
	WindowsNormal = 0x00,
	Normal = 0x01,
	Locked = 0x02,
	Hand = 0x03,
	HandPressed = 0x04,
	Finger = 0x05,
	Dialog = 0x06,
	Sword = 0x07,
	VerticalArrows = 0x08,
	NosmateFight = 0x09,
	NosmateMove = 0x0A
};

inline Cursor operator|(Cursor a, Cursor b)
{
	return static_cast<Cursor>(static_cast<int8_t>(a) | static_cast<int8_t>(b));
}
