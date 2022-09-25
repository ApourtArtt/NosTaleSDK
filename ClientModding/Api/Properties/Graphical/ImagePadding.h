#pragma once
#include <stdint.h>
#pragma pack(push, 1)

/**
 * @brief Game widget image padding representation.
 */
class ImagePadding
{
public:
	ImagePadding()
		: ImagePadding(0, 0, 0, 0, 0, 0)
	{}

	ImagePadding(int16_t WidthLeft, int16_t WidthMiddle, int16_t WidthRight, int16_t HeightTop, int16_t HeightMiddle, int16_t HeightBot)
		: widthMiddle(WidthMiddle)
		, heightMiddle(HeightMiddle)
		, posRight(WidthLeft + WidthMiddle)
		, posBot(HeightTop + HeightMiddle)
		, widthLeft(WidthLeft)
		, heightTop(HeightTop)
		, widthRight(WidthRight)
		, heightBot(HeightBot)
	{}

	ImagePadding(int16_t WidthMiddle, int16_t HeightMiddle, int16_t PosRight, int16_t PosBot, int16_t WidthLeft, int16_t HeightTop, int16_t WidthRight, int16_t HeightBot)
		: widthMiddle(WidthMiddle)
		, heightMiddle(HeightMiddle)
		, posRight(PosRight)
		, posBot(PosBot)
		, widthLeft(WidthLeft)
		, heightTop(HeightTop)
		, widthRight(WidthRight)
		, heightBot(HeightBot)
	{}

	void setWidthMiddle(int16_t w)	{ widthMiddle = w; }
	void setHeightMiddle(int16_t h)	{ heightMiddle = h; }
	void setPosRight(int16_t p)		{ posRight = p; }
	void setPosBot(int16_t p)		{ posBot = p; }
	void setWidthLeft(int16_t w)	{ widthLeft = w; }
	void setHeightTop(int16_t h)	{ heightTop = h; }
	void setWidthRight(int16_t w)	{ widthRight = w; }
	void setHeightBot(int16_t h)	{ heightBot = h; }

	const int16_t getWidthMiddle()	const { return widthMiddle; }
	const int16_t getHeightMiddle()	const { return heightMiddle; }
	const int16_t getPosRight()		const { return posRight; }
	const int16_t getPosBot()		const { return posBot; }
	const int16_t getWidthLeft()	const { return widthLeft; }
	const int16_t getHeightTop()	const { return heightTop; }
	const int16_t getWidthRight()	const { return widthRight; }
	const int16_t getHeightBot()	const { return heightBot; }

private:
	int16_t widthMiddle;	// 0x00
	int16_t heightMiddle;	// 0x02

	int16_t posRight;		// 0x04
	int16_t posBot;			// 0x06

	int16_t widthLeft;		// 0x08
	int16_t heightTop;		// 0x0A

	int16_t widthRight;		// 0x0C
	int16_t heightBot;		// 0x0E
};
static_assert(sizeof(ImagePadding) == 0x10, "ImagePadding does not have a size of 0x10.");

#pragma pack(pop)