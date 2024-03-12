#include <Windows.h>

HMODULE dllHandle{ nullptr };
FARPROC addyShowNostaleSplash{ nullptr };
FARPROC addyFreeNostaleSplash{ nullptr };

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash() noexcept
{
	__asm
	{
		pushad;
		pushfd;

		call addyShowNostaleSplash;

		popfd;
		popad;
		ret;
	}
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash() noexcept
{
	__asm
	{
		pushad;
		pushfd;

		call addyFreeNostaleSplash;

		popfd;
		popad;

		xor eax, eax;
		ret;
	}
}

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID)
{
	if (dllHandle)
		return TRUE;

	dllHandle = LoadLibraryA("EWSF.dll");
	if (!dllHandle)
	{
		MessageBoxA(nullptr, "EWSF.dll was not found", "Please reach out to us on Discord.", 0);
		return FALSE;
	}

	addyShowNostaleSplash = GetProcAddress(dllHandle, "ShowNostaleSplash");
	if (!addyShowNostaleSplash)
	{
		MessageBoxA(nullptr, "ShowNostaleSplash was not found", "Please reach out to us on Discord.", 0);
		return FALSE;
	}

	addyFreeNostaleSplash = GetProcAddress(dllHandle, "FreeNostaleSplash");
	if (!addyFreeNostaleSplash)
	{
		MessageBoxA(nullptr, "FreeNostaleSplash was not found", "Please reach out to us on Discord.", 0);
		return FALSE;
	}

	return TRUE;
}