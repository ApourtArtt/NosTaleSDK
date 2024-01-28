module;
#include <string>
#include <vector>
export module VTableProvider;
import Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class VTableProvider : public Interface
	{
	public:
		VTableProvider(Logger& Logger)
			: logger(Logger)
		{}
		virtual ~VTableProvider() {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;

	protected:
		Logger& logger;
	};
}