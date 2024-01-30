module;
export module TPersistent;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TPersistent : public TObject
	{
	};
	static_assert(sizeof(TPersistent) == 0x4, "TPersistent size isn't 0x4.");
	static_assert(sizeof(TPersistent) <= 0x4, "TPersistent size is upper than 0x4.");
	static_assert(sizeof(TPersistent) >= 0x4, "TPersistent size is lower than 0x4.");
#pragma pack(pop)
}