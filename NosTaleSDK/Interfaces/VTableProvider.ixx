module;
#include <string>
#include <vector>
#include <memory>
export module VTableProvider;
import Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class VTableProvider : public Interface
	{
	public:
		VTableProvider(std::shared_ptr<Logger> Logger)
			: logger(Logger)
		{}
		virtual ~VTableProvider() {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;

	protected:
		std::shared_ptr<Logger> logger;

	private:
		virtual bool load() = 0;
		virtual bool unload() = 0;
	};
}