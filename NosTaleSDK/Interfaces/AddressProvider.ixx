module;
#include <string>
#include <vector>
export module AddressProvider;

namespace NosTaleSDK::Interfaces
{
	export class AddressProvider
	{
	public:
		virtual ~AddressProvider() {}
		[[nodiscard]] virtual bool Load() = 0;
		[[nodiscard]] virtual bool Unload() = 0;
		[[nodiscard]] virtual uintptr_t GetOne(const std::string& AddressName) = 0;
		[[nodiscard]] virtual std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) = 0;
	};
}