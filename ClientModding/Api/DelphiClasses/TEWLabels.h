#pragma once
#include "TEWControlWidgetEX.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Graphical/TextPosition.h"
#pragma pack(push, 1)

// Hatz commented some stuff to be able to get the TextPosition elements inside the array

/* TODO :
* Find unknowns
* Make it possible to configure pxBeforeTextX/Y, x/y
* Rework this class : it is a TEWLabel__s__, so it should be multiple labels (stored in 0x84, as a ptr to another struct)
*/

class TEWLabels : public TEWControlWidgetEX
{
public:
	TEWLabels(TLBSWidget* Parent, Border Border, TextStyle CommonTextStyle, std::vector<std::pair<TextStyle, TextPosition>> texts)
		: TEWControlWidgetEX(ClassSearcher::GetClassInfoFromName("TEWLabels").GetVTable()
		, 0x21, Parent, nullptr, Border)
		, commonTextStyle(CommonTextStyle)
		, textStylePtr(&commonTextStyle) // Does it work ?
		, textPositionArrayPtr(nullptr)
	{
		unknown4 = 0x0f;

		// @TODO
		//pxBeforeTextX = 5;
		//pxBeforeTextY = 5;
		//x = textPosition->x;
		//y = textPosition->y;

		TList<TextStyle> styles = TList<TextStyle>(texts.size());
		TList<TextPosition> positions = TList<TextPosition>(texts.size());

		for (size_t i = 0; i < texts.size(); i++)
		{
			styles.push_back(texts[i].first);
			positions.push_back(texts[i].second);
		}

		textStylePtr = styles.getItems();
		//textPosition = positions.items;
		applyStyle = true;
		nbLines = static_cast<int16_t>(texts.size());
		unknown13 = true;
	}

	void setTextStyle(TextStyle* TextStyle)
	{
		commonTextStyle = *TextStyle;
		textStylePtr = &commonTextStyle;
	}

	//void setTextPosition(TextPosition* TextPosition) { textPosition = TextPosition; }

	TextPosition* getTextPosition(int index)
	{
		if (index < 0 || index > nbLines) return nullptr;
		if (textPositionArrayPtr == nullptr) return nullptr;

		return &textPositionArrayPtr[index];
	}

	const int16_t getNLines() const { return nbLines; }

protected:
	bool unknown13;				// 0x68 Common with the textPositionBytes 0x00 offset
	char unknown14;				// 0x69
	int16_t nbLines;			// 0x6A Common with the textPositionBytes 0x04 offset + Seems like an int8_t and then an unknown
	bool applyStyle;			// 0x6C
	TextStyle commonTextStyle;	// 0x6D
	// Maybe a class for those following 4 int16_t. If not, then still use a TextPosition and assign its members to the variables
	int16_t pxBeforeTextX;		// 0x78
	int16_t pxBeforeTextY;		// 0x7A
	int16_t x;					// 0x7C
	int16_t y;					// 0x7E
	TextStyle* textStylePtr;	// 0x80
	TextPosition* textPositionArrayPtr; // 0x84 Ptr to TextPosition array
};
static_assert(sizeof(TEWLabels) == 0x88, "TEWLabels does not have a size of 0x88.");

#pragma pack(pop)
