module;
#include <string>
export module AddressProvider;

namespace NosTaleSDK::Providers
{
	export class AddressProvider
	{
	public:
		virtual ~AddressProvider() {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& AddressName) = 0;
	};
}