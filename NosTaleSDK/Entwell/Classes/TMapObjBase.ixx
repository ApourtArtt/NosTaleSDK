module;
#include <stdint.h>
export module TMapObjBase;
import TObject;
import Position;
import Bgra;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapObjBase : public TObject
	{
		int8_t entityType;							// 0x004
		char unknown[3];							// 0x005
		uint32_t entityId;							// 0x008
		Properties::Logical::Position position;		// 0x00C
		int32_t currentTimestamp;					// 0x010
		char* textOverHead;							// 0x014
		char* unknown2;								// 0x018
		int32_t timestampTextOverHead;				// 0x01C -1 when no message
		int32_t unknown3;							// 0x020 probably same as above but for unknown2
		struct TSmallIntList* unknown4;				// 0x024 Switching 0x04 of this class to 0 hides the message
		TSmallIntList* unknown5;					// 0x028 probably same as above but for unknown4
		Properties::Graphical::Bgra entityColor;	// 0x02C Note: changing alpha will not work, change the variable below
		uint8_t entityAlpha;						// 0x030
		char unknown6[3];							// 0x031
		float unknown7;								// 0x034 changes on animation (sitting, moving, passively)
		float unknown8;								// 0x038 max(1, unknown9)
		bool showCircleUnderEntity;					// 0x03C
		char unknown9[3];							// 0x03D
		struct TLBSMultiTextureCache* skinTexture;	// 0x040
		float entitySize;							// 0x044 0.02 is already big, normal is around 0.008
		float entityHitBox;							// 0x048
		uint32_t unknown10;							// 0x04C related to map and mount
		uint32_t unknown11;							// 0x050 same as above
		float x;									// 0x054 copy
		float z;									// 0x058 copy
		float y;									// 0x05C copy
		float x2;									// 0x060
		float z2;									// 0x064
		float y2;									// 0x068
		float xOffset;								// 0x06C copy
		float zOffset;								// 0x070 copy
		float yOffset;								// 0x074 copy
		float xOffset2;								// 0x078
		float zOffset2;								// 0x07C
		float yOffset2;								// 0x080
		int32_t unknown12;							// 0x084 related to invisibility (if < threshold, then invisible, etc)
		int32_t unknown13;							// 0x088 related to size of the entity, reset on camera/entity move
		uint8_t unknown14;							// 0x08C
		uint8_t unknown15;							// 0x08D
		uint8_t unknown16;							// 0x08E
		char unknown17;								// 0x08F
		int32_t unknown18;							// 0x090
		int32_t unknown19;							// 0x094
		uint8_t unknown20;							// 0x098
		char unknown21[3];							// 0x099
		int32_t unknown22;							// 0x09C Related to TMarkWidget
	};
	static_assert(sizeof(TMapObjBase) == 0xA0, "TMapObjBase size isn't 0xA0.");
	static_assert(sizeof(TMapObjBase) <= 0xA0, "TMapObjBase size is upper than 0xA0.");
	static_assert(sizeof(TMapObjBase) >= 0xA0, "TMapObjBase size is lower than 0xA0.");
#pragma pack(pop)
}