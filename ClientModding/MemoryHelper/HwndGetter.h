#pragma once
#include <TlHelp32.h>
#include <Windows.h>

/**
 * @brief Callback used for finding the game hwnd
 * 
 * @param hwnd HWND of the process we are looping
 * @param lParam Pointer to a custom parameter
 * @return FALSE if we found the HWND, TRUE to keep looping
 */
BOOL CALLBACK EnumWindowsCallBack(HWND hwnd, LPARAM lParam)
{
	constexpr int maxLength = 255;
	wchar_t className[maxLength] = { 0 };
	DWORD PID = 0;

	GetWindowThreadProcessId(hwnd, &PID);
	GetClassName(hwnd, className, maxLength);

	if (PID != GetCurrentProcessId()) return TRUE;
	if (_wcsicmp(className, L"TNostaleMainF")) return TRUE;

	*(HWND*)lParam = hwnd;
	return FALSE;
}

/**
 * @brief The function finds the hwnd of the Nostale window in the current proccess.
 * 
 * @return the HWND 
 */
HWND getHwnd()
{
	HWND hwnd = 0;
	EnumWindows(EnumWindowsCallBack, (LPARAM)&hwnd);
	return hwnd;
}