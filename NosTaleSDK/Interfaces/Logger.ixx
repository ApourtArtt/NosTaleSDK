module;
#include <string>
#include <vector>
#include <source_location>
export module Logger;
import Interface;

namespace NosTaleSDK::Interfaces
{
	export class Logger : public Interface
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
		virtual bool load() = 0;
		virtual bool unload() = 0;
	};
}