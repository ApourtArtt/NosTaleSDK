#pragma once
#include <stdint.h>

namespace NosTaleSDK::Entwell::Enums
{
#pragma pack(push, 1)
	// Might be an array used to get a real cursor object: http://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Controls.TControl.Cursor
	enum class Cursor : uint8_t
	{
		CURSOR_WINDOWS			= 0x00,
		CURSOR_NORMAL			= 0x01,
		CURSOR_STOP				= 0x02,
		CURSOR_HAND				= 0x03,
		CURSOR_HAND_PRESSED		= 0x04,
		CURSOR_FINGER			= 0x05,
		CURSOR_TALK				= 0x06,
		CURSOR_ATTACK			= 0x07,
		CURSOR_VERTICAL_ARROWS	= 0x08,
		CURSOR_PET_ATTACK		= 0x09,
		CURSOR_PET_MOVE			= 0x0A,
		CURSOR_TEXT				= 0xFC
	};
#pragma pack(pop)
}