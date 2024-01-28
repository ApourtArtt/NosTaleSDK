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
		[[nodiscard]] virtual bool Load() = 0;
		[[nodiscard]] virtual bool Unload() = 0;
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;
	};
}