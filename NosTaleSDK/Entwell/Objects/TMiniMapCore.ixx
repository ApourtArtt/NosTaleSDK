module;
#include <stdint.h>
export module TMiniMapCore;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMiniMapCore : public TEWControlWidget
	{
		char unknown12[16];							//0x68
	};
	static_assert(sizeof(TMiniMapCore) == 0x78, "TMiniMapCore does not have a size of 0x78.");
#pragma pack(pop)
}