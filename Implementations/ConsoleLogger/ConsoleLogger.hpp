#pragma once

#include <string>
#include <source_location>
#include <mutex>
import Logger;

class ConsoleLogger final : public NosTaleSDK::Interfaces::Logger
{
public:
	void Info(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override;
	void Debug(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override;
	void Warn(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override;
	void Error(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override;
	void Fatal(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override;
	void Flush() override;

private:
	[[nodiscard]] static std::string GetTime();
	void log(const std::string& Msg, const char Color[]);
	bool load() override;
	bool unload() override;

	std::mutex mu_;

	inline static constexpr char RESET[] = "\033[0m";
	inline static constexpr char LIGHT_BLUE[] = "\033[36m"; // Info
	inline static constexpr char YELLOW[] = "\033[93m"; // Debug
	inline static constexpr char ORANGE[] = "\033[33m"; // Warn
	inline static constexpr char RED[] = "\033[91m"; // Error
	inline static constexpr char DARK_RED[] = "\033[31m"; // Fatal
};