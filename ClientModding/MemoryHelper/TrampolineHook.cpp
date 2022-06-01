#include "TrampolineHook.h"
#include <Windows.h>
#include <iostream>
#include "Patch.h"

namespace
{
    constexpr int PUSHAD_OPCODE = 0x60;
    constexpr int PUSHFD_OPCODE = 0x9C;
    constexpr int CALL_OPCODE = 0xE8;
    constexpr int POPFD_OPCODE = 0x9D;
    constexpr int POPAD_OPCODE = 0x61;
    constexpr int JMP_OPCODE = 0xE9;
    constexpr int NOP_OPCODE = 0x90;
    constexpr int TRAMPOLINE_INSTRUCTIONS_SIZE = 14;
}

TrampolineHook::TrampolineHook(LPVOID target, LPVOID hook, int len, bool ExecuteOriginalBytes)
{
    this->target = target;
    this->hook = hook;
    this->len = len;
    this->executeOriginalBytes = ExecuteOriginalBytes;
    this->trampoline = 0;

    for (int i = 0; i < 10; i++)
        nopArray[i] = 0x90;

    if (!HookFunction())
        printf("Error hooking function\n");
}

TrampolineHook::~TrampolineHook()
{
    UnHookFunction();
}

bool TrampolineHook::CreateTrampoline()
{
    DWORD oldProtect;
    int trampolineSize = len + TRAMPOLINE_INSTRUCTIONS_SIZE;

    // Allocate memory for the trampoline function
    trampoline = VirtualAlloc(NULL, trampolineSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!trampoline)
        return false;

    // Compute the adresses beforehand (for clarity)
    DWORD pushRegsAddy = (DWORD)trampoline;
    DWORD hookCallAddy = pushRegsAddy + 2;
    DWORD popRegsAddy = hookCallAddy + 5;
    DWORD bytesBackUpAddy = popRegsAddy + 2;
    DWORD jumpBackAddy = bytesBackUpAddy + len;
    DWORD hookRelativeAddress = (DWORD)hook - hookCallAddy - 5;
    DWORD jumpBackRelativeAddress = (DWORD)target + len - jumpBackAddy - 5;

    /* Write trampoline to memory
    *
    * PUSHAD                        ; back up the registers
    * PUSHFD                        ; back up the flags
    * CALL hook                     ; call our hook function
    * POPFD                         ; restore the flags
    * POPAD                         ; restore the resgisters
    * ...                           ; execute overwritten bytes
    * JMP target + len              ; jmp back to the original function
    *
    */

    * (BYTE*)pushRegsAddy = PUSHAD_OPCODE;              // PUSHAD
    *(BYTE*)(pushRegsAddy + 1) = PUSHFD_OPCODE;         // PUSHFD
    *(BYTE*)(hookCallAddy) = CALL_OPCODE;               // CALL opcode
    *(DWORD*)(hookCallAddy + 1) = hookRelativeAddress;  // Write call addy
    *(BYTE*)popRegsAddy = POPFD_OPCODE;                 // POPFD
    *(BYTE*)(popRegsAddy + 1) = POPAD_OPCODE;           // POPAD

    if (executeOriginalBytes)
    {
        // Write original bytes
        if (memcpy_s((LPVOID)bytesBackUpAddy, len, originalBytes, len))
        {
            VirtualFree(trampoline, 0, MEM_RELEASE);
            return false;
        }
    }

    else
    {
        // Write nop bytes
        if (memcpy_s((LPVOID)bytesBackUpAddy, len, nopArray, len))
        {
            VirtualFree(trampoline, 0, MEM_RELEASE);
            return false;
        }
    }

    *(BYTE*)jumpBackAddy = JMP_OPCODE;                      // JMP opcode
    *(DWORD*)(jumpBackAddy + 1) = jumpBackRelativeAddress;  // Write jump addy

    // Change the access protection to make the trampoline function executable
    if (!VirtualProtect(trampoline, trampolineSize, PAGE_EXECUTE_READ, &oldProtect) || !FlushInstructionCache(GetCurrentProcess(), trampoline, trampolineSize))
    {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return false;
    }

    return true;
}

bool TrampolineHook::HookFunction()
{
    DWORD oldProtect;

    // Change access protection of the target functions's bytes where the jump will be written
    if (!VirtualProtect(target, len, PAGE_EXECUTE_READWRITE, &oldProtect))
        return false;

    // Back up current bytes of the instructions
    if (memcpy_s(originalBytes, len, target, len))
        return false;

    // Create the trampoline that will call our function, do the overwritten instructions and jump back to the original func
    if (!CreateTrampoline())
        return false;

    // Set bytes to NOP
    memset(target, 0x90, len);

    // Write the JMP opcode
    *(BYTE*)target = JMP_OPCODE;

    // Write relative address of the jump
    DWORD relativeAddress = (DWORD)trampoline - (DWORD)target - 5;
    *(DWORD*)((DWORD)target + 1) = relativeAddress;

    // Restore the old access protection of the target function
    VirtualProtect(target, len, oldProtect, &oldProtect);

    return true;
}

bool TrampolineHook::UnHookFunction()
{
    DWORD oldProtect;

    // Change access protection of the target function bytes where the backup will be restored
    if (!VirtualProtect(target, len, PAGE_EXECUTE_READWRITE, &oldProtect))
        return false;

    // Restore the original bytes of the instructions previously overwritten
    if (memcpy_s(target, len, originalBytes, len))
        return false;

    // Restore the old access protection of the target function
    if (!VirtualProtect(target, len, oldProtect, &oldProtect))
        return false;

    // Free the memory allocated for the trampoline
    return VirtualFree(trampoline, 0, MEM_RELEASE);
}
