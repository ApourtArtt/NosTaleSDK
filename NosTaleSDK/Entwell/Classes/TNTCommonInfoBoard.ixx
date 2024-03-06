module;
#include <stdint.h>
export module TNTCommonInfoBoard;
import TEWFormWidget;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCommonInfoBoard : public TEWFormWidget
	{
		char unknown40[4];													// 0x0C4
		struct TEWStringListView* description;								// 0x0C8
		struct TEWControlWidgetEX* charIconBg;								// 0x0CC
		struct TNTIconViewer* itemImg;										// 0x0D0
		TEWControlWidgetEX* iconBg;											// 0x0D4
		struct TNTIconWidget* carveRuneImg;									// 0x0D8
		struct TEWLabel* carveRuneQuantity;									// 0x0DC
		TEWLabel* carveRuneDamage;											// 0x0E0
		Properties::Logical::DelphiArray<char>* unknown41;								// 0x0E4
		struct TNTItemList* unknown42;										// 0x0E8
		char unknown43[200];												// 0x0EC
		uint8_t unknown44;													// 0x1B4
		char unknown45[3];													// 0x1B5
		uint32_t unknown46;													// 0x1B8
		uint16_t unknown47;													// 0x1BC
		uint8_t unknown48;													// 0x1BE
		uint32_t unknown49;													// 0x1BF
		uint32_t unknown50;													// 0x1C3
		uint16_t unknown51;													// 0x1C7
		uint8_t unknown52;													// 0x1C9
		uint32_t unknown53;													// 0x1CA
		uint32_t unknown54;													// 0x1CE
		uint16_t unknown55;													// 0x1D2
		uint8_t unknown56;													// 0x1D4
		uint32_t unknown57;													// 0x1D5
		uint32_t unknown58;													// 0x1D9
		uint16_t unknown59;													// 0x1DD
		uint8_t unknown60;													// 0x1DF
		uint32_t unknown61;													// 0x1E0
		uint32_t unknown62;													// 0x1E4
		uint16_t unknown63;													// 0x1E8
		uint8_t unknown64;													// 0x1EA
		uint32_t unknown65;													// 0x1EB
		uint32_t unknown66;													// 0x1EF
		uint16_t unknown67;													// 0x1F3
		uint8_t unknown68;													// 0x1F5
		uint32_t unknown69;													// 0x1F6
		uint32_t unknown70;													// 0x1FA
		uint16_t unknown71;													// 0x1FE
		uint8_t unknown72;													// 0x200
		uint32_t unknown73;													// 0x201
		uint32_t unknown74;													// 0x205
		uint16_t unknown75;													// 0x209
		uint8_t unknown76;													// 0x20B
		char unknown77[11];													// 0x20C
		uint32_t unknown78;													// 0x217
		uint32_t unknown79;													// 0x21B
		uint16_t unknown80;													// 0x21F
		uint8_t unknown81;													// 0x221
		uint32_t unknown82;													// 0x222
		uint32_t unknown83;													// 0x226
		uint16_t unknown84;													// 0x22A
		uint8_t unknown85;													// 0x22C
		uint32_t unknown86;													// 0x22D
		uint32_t unknown87;													// 0x231
		uint16_t unknown88;													// 0x235
		uint8_t unknown89;													// 0x237
		uint32_t unknown90;													// 0x238
		uint32_t unknown91;													// 0x23C
		uint16_t unknown92;													// 0x240
		uint8_t unknown93;													// 0x242
		char unknown94;														// 0x243
		TNTIconWidget* unknown95[10];										// 0x244
		struct TEWScrollBarTrack* scrollBarTrack;							// 0x26C
		struct TEWGraphicButtonWidget* closeBtn;							// 0x270
		uint16_t unknown96;													// 0x274
		char unknown97[2];													// 0x276
		uint16_t unknown98;													// 0x278
		char unknown99[2];													// 0x27A
		uint16_t unknown100;												// 0x27C
		char unknown101[2];													// 0x27E
	};
	static_assert(sizeof(TNTCommonInfoBoard) == 0x280, "TNTCommonInfoBoard size isn't 0x280.");
	static_assert(sizeof(TNTCommonInfoBoard) <= 0x280, "TNTCommonInfoBoard size is upper than 0x280.");
	static_assert(sizeof(TNTCommonInfoBoard) >= 0x280, "TNTCommonInfoBoard size is lower than 0x280.");
#pragma pack(pop)
}