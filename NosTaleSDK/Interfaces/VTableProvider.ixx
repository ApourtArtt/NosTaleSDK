module;
#include <string>
#include <vector>
export module VTableProvider;

namespace NosTaleSDK::Interfaces
{
	export class VTableProvider
	{
	public:
		virtual ~VTableProvider() {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;
	};
}