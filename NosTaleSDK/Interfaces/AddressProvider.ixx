module;
#include <string>
#include <vector>
#include <memory>
export module AddressProvider;
import Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class AddressProvider : public Interface
	{
	public:
		AddressProvider(std::shared_ptr<Logger> Logger)
			: logger(Logger)
		{}
		virtual ~AddressProvider() {}
		[[nodiscard]] virtual uintptr_t GetOne(const std::string& AddressName) = 0;
		[[nodiscard]] virtual std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) = 0;

	protected:
		std::shared_ptr<Logger> logger;

	private:
		virtual bool load() = 0;
		virtual bool unload() = 0;
	};
}