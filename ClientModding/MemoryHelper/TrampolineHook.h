#pragma once
#include <Windows.h>
#include <iostream>

class TrampolineHook
{
public:
    TrampolineHook(LPVOID target, LPVOID hook, int len, bool ExecuteOriginalBytes = true);
    ~TrampolineHook();

private:
    bool CreateTrampoline();
    bool HookFunction();
    bool UnHookFunction();

private:
    LPVOID target;
    LPVOID hook;
    LPVOID trampoline;
    BYTE originalBytes[10]{ 0 };
    BYTE nopArray[10]{ 0 };
    int len;
    bool executeOriginalBytes;
};

