#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Logger.hpp"

namespace NosTaleSDK::Interfaces
{
	class AddressProvider : public Interface
	{
	public:
		explicit AddressProvider(const std::shared_ptr<Logger>& Logger)
			: logger_(Logger)
		{}

		virtual ~AddressProvider() {}
		[[nodiscard]] virtual uintptr_t GetOne(const std::string& AddressName) = 0;
		[[nodiscard]] virtual std::vector<uintptr_t> GetMany(const std::string& AddressName, int32_t HowMany = -1) = 0;

	protected:
		std::shared_ptr<Logger> logger_;

	private:
		[[nodiscard]] virtual bool load() = 0;
		[[nodiscard]] virtual bool unload() = 0;
	};
}