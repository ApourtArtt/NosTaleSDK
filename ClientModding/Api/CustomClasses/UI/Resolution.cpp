#include "Resolution.h"

constexpr int HOOK_SIZE = 30;
DWORD jmpBackAddy;
WindowBase* windowBase;
std::vector <ScreenResolution> resolutions;

void __declspec(naked) resolutionHook()
{
	__asm
	{
		pushad;
		pushfd;
	}

	int buttonID;

	__asm
	{
		mov buttonID, edx;
	}

	if (buttonID < resolutions.size())
	{
		windowBase->x = resolutions[buttonID].x;
		windowBase->y = resolutions[buttonID].y;
	}

	__asm
	{
		popfd;
		popad;
		jmp jmpBackAddy;
	}
}

Resolution::Resolution()
{
	getAddresses();

	resolutions =
	{
		ScreenResolution(800, 600),
		ScreenResolution(1024, 768),
		ScreenResolution(1280, 1024),
		ScreenResolution(1280, 800),
		ScreenResolution(1440, 900),
		ScreenResolution(1024, 700),
		ScreenResolution(1680, 1050),
		ScreenResolution(1920, 1080),
	};
}

void Resolution::SetResolution(int resolutionID)
{
	DWORD callAddy = funcAddy;
	DWORD TGameRootWidget = TGameRootWidgetPtr;

	__asm
	{
		mov eax, TGameRootWidget;
		mov edx, resolutionID;
		call callAddy;
	}
}

void Resolution::getAddresses()
{
	windowBase = **(WindowBase***)PatternScan(
		"\x8B\x1D\x00\x00\x00\x00\x8A\x1B\xA1\x00\x00\x00\x00",
		"xx????xxx????",
		2
	);

	funcAddy = (DWORD)PatternScan(
		"\x53\x8b\xda\xe8\x00\x00\x00\x00\x8b\xd3\xe8\x00\x00\x00\x00\x8b\x0d",
		"xxxx????xxx????xx",
		0
	);

	checkAddress = (DWORD)PatternScan(
		"\x83\xe8\x00\x73\x00\x89\x35",
		"xx?x?xx",
		2
	);

	hookAddy = (DWORD)PatternScan(
		"\x8b\x14\xc5\x00\x00\x00\x00\x8b\x0d\x00\x00\x00\x00\x89\x11\x8b\x04\xc5",
		"xxx????xx????xxxxx",
		0
	);

	PatchSingleByte((BYTE*)checkAddress, (BYTE)'\x20'); // Set number of max resolutions to 0x20 = 32
	Hook((void*)hookAddy, resolutionHook, HOOK_SIZE);
	jmpBackAddy = hookAddy + HOOK_SIZE;

	TGameRootWidgetPtr = (DWORD)NewCharacterStandardInfoWidget::getInstance().getGameRootWidget();
}
