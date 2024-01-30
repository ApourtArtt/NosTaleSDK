module;
export module TNTUnitManager;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTUnitManager : public TObject
	{
		char unknown[4];			// 0x004
		bool unknown2;				// 0x008
		char unknown3[3];			// 0x009
		char unknown4[4];			// 0x00C
		char unknown5[2];			// 0x010
		bool unknown6;				// 0x012
		char unknown7[5];			// 0x013
		bool unknown8;				// 0x018
		char unknown9[7];			// 0x019
		char unknown10[4];			// 0x020
		bool unknown11;				// 0x024
		char unknown12[3];			// 0x025
		char unknown13[4];			// 0x028
		char unknown14[4];			// 0x02C	
	};
	static_assert(sizeof(TNTUnitManager) == 0x30, "TNTUnitManager size isn't 0x30.");
	static_assert(sizeof(TNTUnitManager) <= 0x30, "TNTUnitManager size is upper than 0x30.");
	static_assert(sizeof(TNTUnitManager) >= 0x30, "TNTUnitManager size is lower than 0x30.");
#pragma pack(pop)
}