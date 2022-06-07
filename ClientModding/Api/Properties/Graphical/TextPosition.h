#pragma once
#include <stdint.h>
#include <cstring>
#include "String.h"
#include "../Logical/String.h"
#pragma pack(push, 1)

class TextPosition
{
public:
	TextPosition()
		: TextPosition(0, 0, 0, 0, nullptr, false)
	{}

	TextPosition(int16_t X, int16_t Y, int16_t PxPerLine, int16_t LineSpacing, WString* Text, bool IsVisible)
		: x(X)
		, y(Y)
		, pxPerLine(PxPerLine)
		, lineSpacing(LineSpacing)
		, text(nullptr)
		, isVisible(IsVisible)
		, padding{ 0, 0, 0 }
	{
		if (Text != nullptr && Text->get() != nullptr)
			text = Text->get();
	}

	void move(int16_t incX, int16_t incY)
	{
		setX(x + incX);
		setY(y + incY);
	}

	void setPxPerLine(int16_t px) { pxPerLine = px; }

	void setX(int16_t X) { x = X; }
	void setY(int16_t Y) { y = Y; }

	const int16_t getX() const { return x; }
	const int16_t getY() const { return y; }
	wchar_t* getText() const { return text; }
	void setText(wchar_t* Text) { text = Text; }
	void setVisible(bool Visible) { isVisible = Visible; }

	/*static unsigned char* get(std::vector<TextPosition> texts)
	{
		size_t size = 0x8 + sizeof(TextPosition) * texts.size() + 30; // @TODO : remove this +30, but maybe requires +1 ?
		unsigned char* output = new unsigned char[size];

		size_t s = texts.size();

		memcpy(output, "\x01\x00\x00\x00", 4);
		memcpy((output + 0x04), (char*)&s, sizeof(s));
		for (size_t i = 0; i < s; i++)
			memcpy((output + (0x08 + i * sizeof(TextPosition))), reinterpret_cast<unsigned char*>(&texts[i]), sizeof(TextPosition));



		return output;
	}*/

private:
	// @TODO : Double check x/y and pxPerLine/lineSpacing
	int16_t x;					// 0x00
	int16_t y;					// 0x02
	int16_t pxPerLine;			// 0x04
	int16_t lineSpacing;		// 0x06
	wchar_t* text;				// 0x08
	bool isVisible;				// 0x0C
	unsigned char padding[3];	// 0x0D
};
static_assert(sizeof(TextPosition) == 0x10, "TextPosition does not have a size of 0x0B.");

#pragma pack(pop)