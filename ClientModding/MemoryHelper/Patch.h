#pragma once
#include <Windows.h>

/**
 * @brief Nop memory addresses.
 * 
 * @param dest Address to nop
 * @param size Size of the bytes we want to nop
 * @return true if success, false if not
 */
static bool Nop(BYTE* dest, unsigned int size)
{
	DWORD oldProtect;
	return
		VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &oldProtect) &&
		memset(dest, 0x90, size) &&
		VirtualProtect(dest, size, oldProtect, &oldProtect);
}

/**
 * @brief Change asm instruction bytes.
 * 
 * @param dest Address to change bytes
 * @param src Custom bytes to make the change
 * @param size Number of bytes we will change
 * @return true if success, false if not
 */
static bool Patch(BYTE* dest, BYTE* src, unsigned int size)
{
	DWORD oldProtect;
	return
		VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &oldProtect) &&
		memcpy(dest, src, size) &&
		VirtualProtect(dest, size, oldProtect, &oldProtect);
}

/**
 * @brief Change 1 byte in memory.
 * 
 * @param dest Address of the byte to write
 * @param newByte The byte we want to write
 * @return true if success, false if not
 */
static bool PatchSingleByte(BYTE* dest, BYTE newByte)
{
	return Patch(dest, &newByte, 1);
}

/**
 * @brief Perform a hook.
 * 
 * @param dest Address to hook
 * @param src Custom function to use in the hook
 * @param size Number of bytes of the instruction we are hooking
 * @param copy Optional byte array for saving the original bytes
 * @return true if success, false if not
 */
static bool Hook(void* dest, void* src, unsigned int size, void* copy = nullptr)
{
	DWORD curProtection;

	if (copy != nullptr)
		memcpy(copy, dest, size);

	if (!VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &curProtection) || !memset(dest, 0x90, size))
		return false;
	DWORD relativeAddress = ((DWORD)src - (DWORD)dest) - 5;
	*(BYTE*)dest = 0xE9;
	*(DWORD*)((DWORD)dest + 1) = relativeAddress;
	DWORD temp;
	return VirtualProtect(dest, size, curProtection, &temp);
}
