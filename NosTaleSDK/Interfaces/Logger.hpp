#pragma once
#include <string>
#include <source_location>
#include "Interface.hpp"

namespace NosTaleSDK::Interfaces
{
	class Logger : public Interface
	{
	public:
		virtual ~Logger() {}
		virtual void Info(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Debug(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Warn(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Error(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Fatal(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Flush() = 0;

	private:
		[[nodiscard]] virtual bool load() = 0;
		[[nodiscard]] virtual bool unload() = 0;
	};
}