#pragma once
#include <WTypes.h>
#include "Logger.h"
#include <Windows.h>
#include <stdio.h>

namespace Logger
{
    static FILE* output;
    // TODO: add log time

    static void load()
    {
        AllocConsole();
        freopen_s(&output, "CONOUT$", "w", stdout);
    }

    static void unload()
    {
        fclose(output);
        FreeConsole();
    }

    static void log(const char* message, ...)
    {
        va_list ap;
        va_start(ap, message);
        vfprintf(stdout, message, ap);
        va_end(ap);
    }

    static void log(const wchar_t* message, ...)
    {
        va_list ap;
        va_start(ap, message);
        vfwprintf(stdout, message, ap);
        va_end(ap);
    }

    static void flush()
    {
        fflush(stdout);
    }
};
