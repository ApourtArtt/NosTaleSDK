module;
export module TNTCustomMessageCoreWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCustomMessageCoreWidget : public TEWCustomFormWidget
	{
		char unknown20[4];			// 0xBC
		char* textDisplayed;		// 0xC0 Delphi string ref counted
		char unknown21[4];			// 0xC4
		struct TEWLabels* labels;			// 0xC8
		struct TEWLabels* labels2;			// 0xCC
		char unknown22[4];			// 0xCC
	};
	static_assert(sizeof(TNTCustomMessageCoreWidget) == 0xD4, "TNTCustomMessageCoreWidget does not have a size of 0xD4");
#pragma pack(pop)
}