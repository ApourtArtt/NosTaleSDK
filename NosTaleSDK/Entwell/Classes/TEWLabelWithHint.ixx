module;
export module TEWLabelWithHint;
import TEWLabel;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWLabelWithHint : public TEWLabel
	{
		Properties::Logical::String* hintText;	// 0x090
	};
	static_assert(sizeof(TEWLabelWithHint) == 0x94, "TEWLabelWithHint size isn't 0x94.");
	static_assert(sizeof(TEWLabelWithHint) <= 0x94, "TEWLabelWithHint size is upper than 0x94.");
	static_assert(sizeof(TEWLabelWithHint) >= 0x94, "TEWLabelWithHint size is lower than 0x94.");
#pragma pack(pop)
}