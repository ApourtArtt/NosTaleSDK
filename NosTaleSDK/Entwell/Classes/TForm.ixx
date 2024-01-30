module;
#include <stdint.h>
export module TForm;
import TCustomForm;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TForm : public TCustomForm
	{
	};
	static_assert(sizeof(TForm) == 0x2F8, "TForm size isn't 0x2F8.");
	static_assert(sizeof(TForm) <= 0x2F8, "TForm size is upper than 0x2F8.");
	static_assert(sizeof(TForm) >= 0x2F8, "TForm size is lower than 0x2F8.");
#pragma pack(pop)
}