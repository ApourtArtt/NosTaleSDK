module;
#include <string>
#include <vector>
export module VTableProvider;

namespace NosTaleSDK::Providers
{
	export class VTableProvider
	{
	public:
		virtual ~VTableProvider() {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;
	};
}