module;
#include <stdint.h>
export module TMapObjBase;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapObjBase : public TObject
	{
		int8_t entityType;							// 0x04
		char unknown1[3];							// 0x05 padding
		uint32_t entityId;							// 0x08
		int16_t posx;								// 0x0C
		uint16_t posY;								// 0x0D
		int32_t currentTimestamp;					// 0x10
		char* messageOverHead;						// 0x14
		char* unknown4;								// 0x18 String related?
		int32_t timestampMessageOverHead;			// 0x1C -1 when no message
		int32_t unknown5;							// 0x20 probably same as above but for unknown4
		struct TSmallIntList* unknown6;					// 0x24 Switching 0x04 of this class to 0 hides the message
		struct TSmallIntList* unknown7;					// 0x28 probably same as above but for unknown4
		char entityColor[4];							// 0x2C Note: changing alpha will not work, change the variable below
		uint8_t entityAlpha;						// 0x30
		char unknown8[3];							// 0x31 padding
		float unknown9;								// 0x34 changes on animation (sitting, moving, passively)
		float unknown10;							// 0x38 max(1, unknown9)
		bool showCircleUnderEntity;					// 0x3B
		char unknown11[3];							// 0x3C padding
		struct TLBSMultiTextureCache* textureSkin;			// 0x40
		float entitySize;							// 0x44 0.02 is already big, normal is around 0.008
		float entityHitBox;							// 0x48 the lower it is, the higher is the entity hitbox until 0
		float unknown12;							// 0x4C used when changing map/using locomotion
		float unknown13;							// 0x50 same as above
		float x;									// 0x54 read only copy of x2
		float z;									// 0x58 read only copy of z2
		float y;									// 0x5C read only copy of z2
		float x2;									// 0x60 entity position on the screen
		float z2;									// 0x64 entity position on the screen
		float y2;									// 0x68 entity position on the screen
		float xOffset;								// 0x6C read only copy of xOffset2
		float zOffset;								// 0x70 read only copy of zOffset2
		float yOffset;								// 0x74 read only copy of yOffset2
		float xOffset2;								// 0x78 move the entity from the center on x axis
		float zOffset2;								// 0x7C same, for z
		float yOffset2;								// 0x80 same, for y
		int32_t unknown14;							// 0x84 related to invisibility (if < threshold, then invisible, etc)
		int32_t unknown15;							// 0x88 related to size of the entity, reset on camera/entity move
		int32_t unknown16;							// 0x8C 1 byte + 3 padding
		int32_t unknown17;							// 0x90 set at class (re)initialization but could not find one read
		int32_t unknown18;							// 0x94 same as above
		int32_t unknown19;							// 0x98 if unknown19 != 0 then it enters a condition where unknown20 is checked
		int32_t unknown20;							// 0x9C if unknown20 != 0 it allow to go in a block that can trigger the TMarkWidget (SP6A target) -- need unknown19 to be != 0
	};
	static_assert(sizeof(TMapObjBase) == 0xA0, "TMapObjBase does not have a size of 0xA0.");
#pragma pack(pop)
}