module;
#include <stdint.h>
export module TSvrCtlObjManager;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSvrCtlObjManager : public TObject
	{
		int16_t currentPosX;		// 0x04
		int16_t currentPosY;		// 0x06
		int16_t goalPosX;			// 0x08
		int16_t goalPosY;			// 0x0A
		struct TByteList* unknown1;	// 0x0C
		char unknown2[0x8C];		// 0x10
	};
	static_assert(sizeof(TSvrCtlObjManager) == 0x9C, "TSvrCtlObjManager does not have a size of 0x9C.");
#pragma pack(pop)
}