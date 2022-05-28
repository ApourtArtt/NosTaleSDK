#pragma once
#include <WTypes.h>
#include <Windows.h>
#include <stdio.h>
#include <chrono>
#include <string>
#include <iostream>
#include <mutex>

namespace Logger
{
    static FILE* output;
    inline static std::mutex writer;

    static void Load(const std::string& Filename = "CONOUT$")
    {
        AllocConsole();
        freopen_s(&output, Filename.c_str(), "w", stdout);
    }

    static void Unload()
    {
        fclose(output);
        FreeConsole();
    }

    [[nodiscard]] static std::string GetTime()
    {
        using namespace std::chrono;
        auto tp = system_clock::now();
        auto dp = floor<days>(tp);
        year_month_day ymd{ dp };
        hh_mm_ss time{ floor<milliseconds>(tp - dp) };
        std::string res;
        res.reserve(30); // "[dd/mm/yyyy hh:mm:ss.mmmmmm] "
        res = "["
            + std::to_string(static_cast<unsigned>(ymd.day()))
            + "/"
            + std::to_string(static_cast<unsigned>(ymd.month()))
            + "/"
            + std::to_string(static_cast<int>(ymd.year()))
            + " "
            + std::to_string(time.hours().count())
            + ":"
            + std::to_string(time.minutes().count())
            + ":"
            + std::to_string(time.seconds().count())
            + "."
            + std::to_string(time.subseconds().count())
            + "] ";
        return res;
    }


    static void Log(const char* message, ...)
    {
        writer.lock();

        printf("%s", GetTime().c_str());

        va_list ap;
        va_start(ap, message);
        vfprintf(stdout, message, ap);
        va_end(ap);

        printf("\n");

        writer.unlock();
    }

    static void Log(const wchar_t* message, ...)
    {
        writer.lock();

        printf("%s", GetTime().c_str());

        va_list ap;
        va_start(ap, message);
        vfwprintf(stdout, message, ap);
        va_end(ap);

        printf("\n");

        writer.unlock();
    }

    static void Flush()
    {
        fflush(stdout);
    }
};
