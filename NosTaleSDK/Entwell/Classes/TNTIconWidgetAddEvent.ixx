module;
export module TNTIconWidgetAddEvent;
import TNTIconWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconWidgetAddEvent : public TNTIconWidget
	{
		char unknown48[4];							// 0x0CC
		Properties::Logical::Callback unknown49;	// 0x0D0
		Properties::Logical::Callback unknown50;	// 0x0D8
		char unknown51[8];							// 0x0E0
	};
	static_assert(sizeof(TNTIconWidgetAddEvent) == 0xE8, "TNTIconWidgetAddEvent size isn't 0xE8.");
	static_assert(sizeof(TNTIconWidgetAddEvent) <= 0xE8, "TNTIconWidgetAddEvent size is upper than 0xE8.");
	static_assert(sizeof(TNTIconWidgetAddEvent) >= 0xE8, "TNTIconWidgetAddEvent size is lower than 0xE8.");
#pragma pack(pop)
}