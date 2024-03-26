#pragma once
#include <string>
#include <memory>
#include "Logger.h"

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
		[[nodiscard]] virtual bool load() = 0;
		[[nodiscard]] virtual bool unload() = 0;
	};
}