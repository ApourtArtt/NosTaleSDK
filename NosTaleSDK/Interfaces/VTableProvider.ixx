module;
#include <string>
#include <memory>
export module VTableProvider;
import Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class VTableProvider : public Interface
	{
	public:
		explicit VTableProvider(const std::shared_ptr<Logger>& Logger)
			: logger_(Logger)
		{}

		~VTableProvider() override {}
		[[nodiscard]] virtual uintptr_t Get(const std::string& ClassName) = 0;

	protected:
		std::shared_ptr<Logger> logger_;

	private:
		bool load() override = 0;
		bool unload() override = 0;
	};
}