module;
#include <string>
#include <vector>
export module VTableProvider;
import Logger;

namespace NosTaleSDK::Interfaces
{
	export class VTableProvider
	{
	public:
		VTableProvider(Logger& Logger)
			: logger(Logger)
		{}
		virtual ~VTableProvider() {}
		[[nodiscard]] virtual bool Load() = 0;
		[[nodiscard]] virtual bool Unload() = 0;
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;

	protected:
		Logger& logger;
	};
}