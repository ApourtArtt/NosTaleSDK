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
		virtual void Info(const std::string& Log, const std::source_location& l = std::source_location::current()) = 0;
		virtual void Debug(const std::string& Log, const std::source_location& l = std::source_location::current()) = 0;
		virtual void Warn(const std::string& Log, const std::source_location& l = std::source_location::current()) = 0;
		virtual void Error(const std::string& Log, const std::source_location& l = std::source_location::current()) = 0;
		virtual void Fatal(const std::string& Log, const std::source_location& l = std::source_location::current()) = 0;
		virtual void Flush() = 0;
	};
}