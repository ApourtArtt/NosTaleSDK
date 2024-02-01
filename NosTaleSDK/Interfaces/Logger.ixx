module;
#include <string>
#include <source_location>
export module Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class Logger : public Interface
	{
	public:
		~Logger() override {}
		virtual void Info(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Debug(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Warn(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Error(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Fatal(const std::string& Msg, const std::source_location& Location = std::source_location::current()) = 0;
		virtual void Flush() = 0;

	private:
		bool load() override = 0;
		bool unload() override = 0;
	};
}