module;
#include <string>
#include <source_location>
#include <chrono>
#include <mutex>
#include <format>
#include <Windows.h>
export module ConsoleLogger;
import Logger;

export class ConsoleLogger : public NosTaleSDK::Interfaces::Logger
{
public:
	void Info(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[INFO] file: {}:{}:{} ({}) {}\n{}\n",
			Location.file_name(),
			Location.line(),
			Location.column(),
			Location.function_name(),
			GetTime().c_str(),
			Msg.c_str()
		), LIGHT_BLUE);
	}

	void Debug(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[DEBUG] file: {}:{}:{} ({}) {}\n{}\n",
			Location.file_name(),
			Location.line(),
			Location.column(),
			Location.function_name(),
			GetTime().c_str(),
			Msg.c_str()
		), LIGHT_BLUE);
	}

	void Warn(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[WARN] file: {}:{}:{} ({}) {}\n{}\n",
			Location.file_name(),
			Location.line(),
			Location.column(),
			Location.function_name(),
			GetTime().c_str(),
			Msg.c_str()
		), LIGHT_BLUE);
	}

	void Error(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[ERROR] file: {}:{}:{} ({}) {}\n{}\n",
			Location.file_name(),
			Location.line(),
			Location.column(),
			Location.function_name(),
			GetTime().c_str(),
			Msg.c_str()
		), LIGHT_BLUE);
		Flush();
	}

	void Fatal(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[FATAL] file: {}:{}:{} ({}) {}\n{}\n",
			Location.file_name(),
			Location.line(),
			Location.column(),
			Location.function_name(),
			GetTime().c_str(),
			Msg.c_str()
		), LIGHT_BLUE);
		Flush();
	}

	void Flush() override
	{
		mu.lock();
		fflush(stdout);
		mu.unlock();
	}

private:
	[[nodiscard]] std::string GetTime()
	{
		auto time = std::chrono::utc_clock::now();
		return std::format("{:%Y/%m/%d %T}", time);
	}

	void log(const std::string msg, const char color[])
	{
		mu.lock();
		printf("%s%s%s", color, msg.c_str(), RESET);
		mu.unlock();
	}

	bool load() override
	{
		FreeConsole();

		if (!AllocConsole())
			return false;

		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsole == nullptr)
			return false;

		DWORD mode;
		if (!GetConsoleMode(hConsole, &mode))
			return false;

		mode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hConsole, mode);
		return true;
	}

	bool unload() override
	{
		return FreeConsole();
	}

	std::mutex mu;

	inline static constexpr char RESET[] = "\033[0m";
	inline static constexpr char LIGHT_BLUE[] = "\033[36m"; // Info
	inline static constexpr char YELLOW[] = "\033[93m"; // Debug
	inline static constexpr char ORANGE[] = "\033[33m"; // Warn
	inline static constexpr char RED[] = "\033[91m"; // Error
	inline static constexpr char DARK_RED[] = "\033[31m"; // Fatal
};