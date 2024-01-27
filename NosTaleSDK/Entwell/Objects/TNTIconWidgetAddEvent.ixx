module;
export module TNTIconWidgetAddEvent;
import TNTIconWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconWidgetAddEvent : public TNTIconWidget
	{
		char unknown22[20];			//0xCC
		char unknownCallback[8];	//0xE0
	};
	static_assert(sizeof(TNTIconWidgetAddEvent) == 0xE8, "TNTIconWidgetAddEvent does not have a size of 0xE8.");
#pragma pack(pop)
}