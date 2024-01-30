module;
export module TNTHintWidget;
import TEWLabels;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTHintWidget : public TEWLabels
	{
		uint32_t unknown22;	// 0x088
		uint32_t unknown23; // 0x08C
		uint8_t unknown24;	// 0x090
		char unknown25[3];	// 0x091
		uint32_t unknown26; // 0x094
		uint32_t unknown27; // 0x098
		char unknown28[4];	// 0x09C
	};
	static_assert(sizeof(TNTHintWidget) == 0xA0, "TNTHintWidget size isn't 0xA0.");
	static_assert(sizeof(TNTHintWidget) <= 0xA0, "TNTHintWidget size is upper than 0xA0.");
	static_assert(sizeof(TNTHintWidget) >= 0xA0, "TNTHintWidget size is lower than 0xA0.");
#pragma pack(pop)
}