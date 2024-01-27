module;
#include <stdint.h>
export module TMapMonsterObj;
import TMapMoveObjBase;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapMonsterObj : public TMapMoveObjBase
	{
		char unknown83;			// 0x1AC Something related to monster glow (1=small glow 2=huge glow like shadow monsters in Act 5.2 3+=nothing)
		char unknown84[3];		// 0x1AD probably padding
		char unknown85[4];		// 0x1B0 most probably a pointer to something
		int16_t morphVnum;		// 0x1B4
		int16_t shadowType;		// 0x1B6 if value is 2034 or 2049 the shadow is above the entity, if the value is 2371, the display removes every pseudonyms and life/mana bars - seems to have some logic with a list
		char relou[4];			// 0x1B8 pointer to a struct storing monster info
		char unknown86;			// 0x1BC something if & 0x7F
		char unknown87[3];		// 0x1BD probably padding
		float unknown88;		// 0x1C0 1.0 - no W or R found
		char unknown89[4];		// 0x1C4
		char unknown90[4];		// 0x1C8
		char unknown91[4];		// 0x1CC
	};
	static_assert(sizeof(TMapMonsterObj) == 0x1D4, "TMapMonsterObj does not have a size of 0x1D0.");
#pragma pack(pop)
}