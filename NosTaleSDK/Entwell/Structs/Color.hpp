#pragma once
#include <stdint.h>

// http://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Controls.TControl.Color
namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	class Color
	{
	public:
		Color(uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha);

		void SetBlue(uint8_t value);
		void SetGreen(uint8_t value);
		void SetRed(uint8_t value);
		void SetAlpha(uint8_t value);

		uint8_t GetBlue() const;
		uint8_t GetGreen() const;
		uint8_t GetRed() const;
		uint8_t GetAlpha() const;

	private:
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};
	static_assert(sizeof(Color) == 0x4, "Color's size is not 0x4.");
	static_assert(sizeof(Color) <= 0x4, "Color's size is higher than 0x4.");
	static_assert(sizeof(Color) >= 0x4, "Color's size is lower than 0x4.");
#pragma pack(pop)
}