module;
export module TNTUnitManager;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTUnitManager : public TObject
	{
		char unknown1[4];			// 0x04
		bool ce_truc;				// 0x08
		char unknown2[3];			// 0x09 prob padding
		char unknown3[4];			// 0x0C
		char unknown4[2];			// 0x10
		bool unknown5;				// 0x12
		char unknown6[5];			// 0x13
		bool unknown7;				// 0x18
		char unknown8[7];			// 0x19
		char unknown9[4];			// 0x20
		bool unknown10;				// 0x24
		char unknown11[3];			// 0x25
		char unknown12[4];			// 0x28
		char unknown13[4];			// 0x2C	
	};
	static_assert(sizeof(TNTUnitManager) == 0x30, "TNTUnitManager does not have a size of 0x30.");
#pragma pack(pop)
}