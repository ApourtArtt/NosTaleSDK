#pragma once
#include <stdint.h>

// http://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Controls.TControl.BoundsRect
namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	class BoundsRect
	{
	public:
		BoundsRect(int16_t TopLeftX = 0, int16_t TopLeftY = 0, int16_t BotRightX = 0, int16_t BotRightY = 0);

		void SetTop(int16_t TopLeftX, int16_t TopLeftY);
		void SetBot(int16_t BotRightX, int16_t BotRightY);
		void SetWidth(int16_t Width);
		void SetHeight(int16_t Height);

		int16_t GetTopLeftX() const;
		int16_t GetTopLeftY() const;
		int16_t GetBotRightX() const;
		int16_t GetBotRightY() const;
		int16_t GetWidth() const;
		int16_t GetHeight() const;

	private:
		int16_t topLeftX;	// 0x000
		int16_t topLeftY;	// 0x002
		int16_t botRightX;  // 0x004
		int16_t botRightY;	// 0x006
	};
	static_assert(sizeof(BoundsRect) == 0x8, "BoundsRect size isn't 0x8.");
	static_assert(sizeof(BoundsRect) <= 0x8, "BoundsRect size is higher than 0x8.");
	static_assert(sizeof(BoundsRect) >= 0x8, "BoundsRect size is lower than 0x8.");
#pragma pack(pop)
}