module;
export module TNTTrayWidget;
import TEWControlWidgetEX;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTrayWidget : public TEWControlWidgetEX
	{
		uint32_t unknown20;													// 0x068
		uint32_t unknown21;													// 0x06C
		uint32_t unknown22;													// 0x070
		uint32_t unknown23;													// 0x074
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown24;	// 0x078
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown25;	// 0x07C
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown26;	// 0x080
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown27;	// 0x084
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown28;	// 0x088
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown29;	// 0x08C
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown30;	// 0x090
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown31;	// 0x094
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown32;	// 0x098
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown33;	// 0x09C
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown34;	// 0x0A0
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown35;	// 0x0A4
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown36;	// 0x0A8
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown37;	// 0x0AC
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown38;	// 0x0B0
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown39;	// 0x0B4
		char unknown40[16];													// 0x0B8
		uint32_t unknown41;													// 0x0C8
		char unknown42[12];													// 0x0CC
		uint32_t unknown43;													// 0x0D8
		uint32_t unknown44;													// 0x0DC
		uint32_t unknown45;													// 0x0E0
		uint32_t unknown46;													// 0x0E4
		uint32_t unknown47;													// 0x0E8
		uint32_t unknown48;													// 0x0EC
		uint32_t unknown49;													// 0x0F0
		char unknown50[60];													// 0x0F4
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown51;	// 0x130
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown52;	// 0x134
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown53;	// 0x138
		struct NosTaleSDK::Entwell::Properties::Logical::String* unknown54;	// 0x13C
		char unknown55;														// 0x140
		uint8_t unknown56;													// 0x141
		char unknown57[2];													// 0x142
		uint32_t unknown58;													// 0x144
		uint8_t unknown59;													// 0x148
		char unknown60[3];													// 0x149
		uint32_t unknown61;													// 0x14C
		uint8_t unknown62;													// 0x150
		char unknown63[3];													// 0x151
		uint32_t unknown64;													// 0x154
		uint8_t unknown65;													// 0x158
		char unknown66[3];													// 0x159
		uint32_t unknown67;													// 0x15C
		uint8_t unknown68;													// 0x160
		char unknown69[3];													// 0x161
		uint32_t unknown70;													// 0x164
		uint8_t unknown71;													// 0x168
		char unknown72[3];													// 0x169
		uint32_t unknown73;													// 0x16C
		uint8_t unknown74;													// 0x170
		char unknown75[3];													// 0x171
		uint32_t unknown76;													// 0x174
		struct TEWRollOverButtonWidget* unknown77;							// 0x178
		struct TEWCustomPanelWidget* unknown78;								// 0x17C
		struct TEWCustomPanelWidget* unknown79;								// 0x180
		struct TEWStringListView* unknown80;								// 0x184
		struct TEWStringListView* unknown81;								// 0x188
	};
	static_assert(sizeof(TNTTrayWidget) == 0x18C, "TNTTrayWidget size isn't 0x18C.");
	static_assert(sizeof(TNTTrayWidget) <= 0x18C, "TNTTrayWidget size is upper than 0x18C.");
	static_assert(sizeof(TNTTrayWidget) >= 0x18C, "TNTTrayWidget size is lower than 0x18C.");
#pragma pack(pop)
}