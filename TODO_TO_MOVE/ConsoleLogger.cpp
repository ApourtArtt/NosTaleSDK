#include <Windows.h>
#include <format>
#include <chrono>
#include "../NosTaleSDK/Utils/StringObfuscator.hpp"
#include "../NosTaleSDK/Utils/FormatString.hpp"
#include "ConsoleLogger.hpp"

void ConsoleLogger::Info(const std::string& Msg, const std::source_location& Location)
{
	log(NosTaleSDK::Utils::FormatString(obf("\t[INFO] {}\n{}\n"),
		GetTime().c_str(),
		Msg.c_str()
	), LIGHT_BLUE);
}

void ConsoleLogger::Debug(const std::string& Msg, const std::source_location& Location)
{
	log(NosTaleSDK::Utils::FormatString(obf("\t[DEBUG] file: {}:{}:{} ({}) {}\n{}\n"),
		Location.file_name(),
		Location.line(),
		Location.column(),
		Location.function_name(),
		GetTime().c_str(),
		Msg.c_str()
	), YELLOW);
}

void ConsoleLogger::Warn(const std::string& Msg, const std::source_location& Location)
{
	log(NosTaleSDK::Utils::FormatString(obf("\t[WARN] file: {}:{}:{} ({}) {}\n{}\n"),
		Location.file_name(),
		Location.line(),
		Location.column(),
		Location.function_name(),
		GetTime().c_str(),
		Msg.c_str()
	), ORANGE);
}

void ConsoleLogger::Error(const std::string& Msg, const std::source_location& Location)
{
	log(NosTaleSDK::Utils::FormatString(obf("\t[ERROR] file: {}:{}:{} ({}) {}\n{}\n"),
		Location.file_name(),
		Location.line(),
		Location.column(),
		Location.function_name(),
		GetTime().c_str(),
		Msg.c_str()
	), RED);
	Flush();
}

void ConsoleLogger::Fatal(const std::string& Msg, const std::source_location& Location)
{
	log(NosTaleSDK::Utils::FormatString(obf("\t[FATAL] file: {}:{}:{} ({}) {}\n{}\n"),
		Location.file_name(),
		Location.line(),
		Location.column(),
		Location.function_name(),
		GetTime().c_str(),
		Msg.c_str()
	), DARK_RED);
	Flush();
}

void ConsoleLogger::Flush()
{
	mu_.lock();
	fflush(stdout);
	mu_.unlock();
}

[[nodiscard]] std::string ConsoleLogger::GetTime()
{
	auto const time = std::chrono::utc_clock::now();
	return std::format("{0:%x} {0:%T}", time);
}

void ConsoleLogger::log(const std::string& Msg, const char Color[])
{
	mu_.lock();
	printf(obf("%s%s%s"), Color, Msg.c_str(), RESET);
	mu_.unlock();
}

bool ConsoleLogger::load()
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

bool ConsoleLogger::unload()
{
	return FreeConsole();
}