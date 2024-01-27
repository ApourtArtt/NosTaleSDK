module;
#include <stdint.h>
export module TNTMessageBoxWidget;
import TNTCustomMessageWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMessageBoxWidget : public TNTCustomMessageWidget
	{
		struct TEWGraphicButtonWidget* leftButton;		// 0xD0
		struct TEWGraphicButtonWidget* rightButton;	// 0xD4
		char				OnClose[8];		// 0xD8 callback.Arg in my case was TNTUnitManager but I doubt it is stable - don't use it
		char					unknown24[4];	// 0xE0
		char					unknown25[4];	// 0xE4 String freed and realloced, maybe a TextStyle (?)
		wchar_t* arg;			// 0xE8 Delphi string NOT ref counted - often used as a singleshot packet (ex: opening a box, packet sent when accepting, etc)
	};
	static_assert(sizeof(TNTMessageBoxWidget) == 0xF4, "TNTMessageBoxWidget does not have a size of 0xF4");
#pragma pack(pop)
}