#pragma once
#include <Windows.h>
#include <mutex>
#include <stack>
#include <iostream>
#include <functional>
#include <string>
#include <stdarg.h>
#include <chrono>
#include <format>
#include <source_location>

class Logger
{
private:
    inline static std::string indent;
    inline static std::mutex mu;
    inline static std::stack<std::string> moduleNames;

    class Defer
    {
    public:
        Defer(std::function<void()> F) : f(F) {}
        ~Defer() { f(); }

    private:
        std::function<void()> f;
    };

    // https://stackoverflow.com/a/66402319/10771848
    struct FormatWithLocation
    {
        const char* value;
        std::source_location loc;

        FormatWithLocation(const char* s, const std::source_location& l = std::source_location::current())
            : value(s), loc(l)
        {}
    };

    inline static constexpr char RESET[] = "\033[0m";
    inline static constexpr char RED[] = "\033[31m";
    inline static constexpr char GREEN[] = "\033[32m";

public:

    static void Flush() { fflush(stdout); }

    static void Load(const std::string& Filename = "")
    {
        AllocConsole();
        freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hConsole, &mode);
        mode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hConsole, mode);
    }

    static void Unload()
    {
        FreeConsole();
    }

    [[nodiscard]] static std::string GetTime()
    {
        using namespace std::chrono;
        auto tp = system_clock::now();
        auto dp = floor<days>(tp);
        year_month_day ymd{ dp };
        hh_mm_ss time{ floor<milliseconds>(tp - dp) };
        return std::format("[{} {:%T}]", ymd, time);
    }

    template <typename... Args>
    static void Log(const char* msg, Args&&... args)
    {
        mu.lock();

        printf("%s", GetTime().c_str());

        for (size_t i = 1; i < moduleNames.size(); i++)
            printf("%s", indent.c_str());
        if (moduleNames.size() > 0)
            printf("[%s] ", moduleNames.top().c_str());

        printf(msg, args...);
        printf("\n");

        mu.unlock();
    }

    template <typename... Args>
    static void Success(const char* msg, Args&&... args)
    {
        mu.lock();

        printf("%s%s", GetTime().c_str(), GREEN);

        for (size_t i = 1; i < moduleNames.size(); i++)
            printf("%s", indent.c_str());
        if (moduleNames.size() > 0)
            printf("[%s] ", moduleNames.top().c_str());

        printf(msg, args...);
        printf("%s\n", RESET);

        mu.unlock();
    }

    template <typename... Args>
    static void Error(FormatWithLocation fmt, Args&&... args)
    {
        mu.lock();

        printf("%s%s", GetTime().c_str(), RED);

        for (size_t i = 1; i < moduleNames.size(); i++)
            printf("%s", indent.c_str());
        if (moduleNames.size() > 0)
            printf("[%s] ", moduleNames.top().c_str());

        printf("file: %s:%d:%d (%s)\n", fmt.loc.file_name(), fmt.loc.line(), fmt.loc.column(), fmt.loc.function_name());
        printf(fmt.value, args...);
        printf("%s\n", RESET);

        Flush();

        mu.unlock();
    }

    static void PushModuleName(const std::string& Name)
    {
        auto t = GetTime();
        mu.lock();
        moduleNames.push(Name);
        mu.unlock();
    }

    static void PopModuleName()
    {
        mu.lock();
        moduleNames.pop();
        mu.unlock();
    }

    [[nodiscard]] static Defer PushPopModuleName(const std::string& Name)
    {
        PushModuleName(Name);
        Log("");
        return Defer(PopModuleName);
    }

    static void IndentModuleName(const std::string& Indent)
    {
        mu.lock();
        indent = Indent;
        mu.unlock();
    }
};