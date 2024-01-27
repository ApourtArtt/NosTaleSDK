module;
export module TEWCustomButtonWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

	export struct TEWCustomButtonWidget : public TEWCustomPanelWidget
	{
		char unknown17[4];						// 0x00A4
		bool clickedAndHovered;					// 0x00A8
		bool hovered;							// 0x00A9
		char unknown18[6];						// 0x00AA
		char callback[0x08];						// 0x00B0 //Callback.h
		char unknown19[8];						// 0x00B8
		bool unknown20;							// 0x00C0 Strange behaviour : unknown8 ^= 1 on every click on button, but not when triggered by keyboard
		char unknown21;							// 0x00C1
		bool makeSound;							// 0x00C2
		char unknown23[21];						// 0x00C3 some things with a pointer and bool
	};
	static_assert(sizeof(TEWCustomButtonWidget) == 0x00D8, "TEWCustomButtonWidget does not have a size of 0x00D8.");
#pragma pack(pop)
}