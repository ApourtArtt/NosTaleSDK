module;
export module TPersistent;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TPersistent : public TObject
	{
	};
	static_assert(sizeof(TPersistent) == 0x04, "TPersistent does not have a size of 0x04.");
#pragma pack(pop)
}