module;
#include <string>
#include <source_location>
#include <mutex>
#include <Windows.h>
#include <format>
//#include <chrono>
export module ConsoleLogger;
import Logger;

export class ConsoleLogger final : public NosTaleSDK::Interfaces::Logger
{
public:
	void Info(const std::string& Msg, const std::source_location& Location = std::source_location::current()) override
	{
		log(std::format("\t[INFO] {}\n{}\n",
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
		), YELLOW);
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
		), ORANGE);
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
		), RED);
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
		), DARK_RED);
		Flush();
	}

	void Flush() override
	{
		mu_.lock();
		fflush(stdout);
		mu_.unlock();
	}

private:	
	[[nodiscard]] static std::string GetTime()
	{
		return "";
		//auto const time = std::chrono::utc_clock::now();
		//return std::format("{0:%x} {0:%T}", time);
	}

	void log(const std::string& Msg, const char Color[])
	{
		mu_.lock();
		printf("%s%s%s", Color, Msg.c_str(), RESET);
		mu_.unlock();
	}

	bool load() override
	{
		FreeConsole();

		if (!AllocConsole())
			return false;

		freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
		const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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

	std::mutex mu_;

	inline static constexpr char RESET[] = "\033[0m";
	inline static constexpr char LIGHT_BLUE[] = "\033[36m"; // Info
	inline static constexpr char YELLOW[] = "\033[93m"; // Debug
	inline static constexpr char ORANGE[] = "\033[33m"; // Warn
	inline static constexpr char RED[] = "\033[91m"; // Error
	inline static constexpr char DARK_RED[] = "\033[31m"; // Fatal
};