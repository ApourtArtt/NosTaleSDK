module;
export module TStrings;
import TPersistent;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TStrings : public TPersistent
	{
		char TStringsDefined;		// 0x04
		char FDelimiter;			// 0x05
		char FQuoteChar;			// 0x06
		char FNameValueSeparator;	// 0x07
		int FUpdateCount;			// 0x08
		void* IStringAdapter;		// 0x0C
	};
	static_assert(sizeof(TStrings) == 0x10, "TStrings does not have a size of 0x10.");
#pragma pack(pop)
}