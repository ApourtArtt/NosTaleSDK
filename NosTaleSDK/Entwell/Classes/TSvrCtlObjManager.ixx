module;
export module TSvrCtlObjManager;
import TObject;
import Position;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSvrCtlObjManager : public TObject
	{
		Properties::Logical::Position position;		// 0x004
		Properties::Logical::Position goalPosition;	// 0x008
		struct TByteList* unknown;					// 0x00C
		char unknown2[140];							// 0x010
	};
	static_assert(sizeof(TSvrCtlObjManager) == 0x9C, "TSvrCtlObjManager size isn't 0x9C.");
	static_assert(sizeof(TSvrCtlObjManager) <= 0x9C, "TSvrCtlObjManager size is upper than 0x9C.");
	static_assert(sizeof(TSvrCtlObjManager) >= 0x9C, "TSvrCtlObjManager size is lower than 0x9C.");
#pragma pack(pop)
}