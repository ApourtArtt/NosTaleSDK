#include "KeyBindManager.h"

DWORD originalFunctionAddress = 0;
DWORD TNostaleGameAddress = 0;
KeyModifier keyModifiers = KeyModifier::NO_MODIFIER;
KeyCode* keyCode = nullptr;
KeyBind currentKeyBind;
KeyBind original;

void __declspec(naked) keyBindHook()
{
	// Save original paremeters
	__asm
	{
		mov TNostaleGameAddress, eax;
		mov keyCode, edx;
		mov keyModifiers, cl;
	}

	currentKeyBind.first = *keyCode;
	currentKeyBind.second = keyModifiers;

	// Compare if key is in our map as a value
	if (KeyBindManager::getInstance().contains(currentKeyBind, original))
	{
		// If key is a modified key we redirect the function to the original key
		if (original != currentKeyBind)
		{
			*keyCode = original.first;
			keyModifiers = original.second;
		}
	}

	/* Uncomment this only on final release or while testing*/
	else
	{
		__asm
		{
			ret;
		}
	}

	// Call original function and return
	__asm
	{
		mov eax, TNostaleGameAddress;
		mov edx, keyCode;
		mov cl, keyModifiers;
		call originalFunctionAddress;
		ret;
	}
}

KeyBindManager::KeyBindManager()
{
	getAddresses();
	hookFunction();
	initializeKeys();
}

KeyBindManager& KeyBindManager::getInstance()
{
	static KeyBindManager instance;
	return instance;
}

KeyBindManager::~KeyBindManager()
{
	delete trmpHook;
}

bool KeyBindManager::setCustomKey(const KeyBind& original, const KeyBind& newKey)
{
	if (keyBinds.contains(original))
	{
		keyBinds[original] = newKey;
		return true;
	}

	return false;
}

const KeyBind& KeyBindManager::getCustomKey(const KeyBind& originalKey)
{
	return keyBinds[originalKey];
}

bool KeyBindManager::contains(const KeyBind& customKey, KeyBind& result)
{
	for (auto it = keyBinds.begin(); it != keyBinds.end(); ++it)
	{
		if (it->second == customKey)
		{
			result = it->first;
			return true;
		}
	}

	return false;
}

void KeyBindManager::getAddresses()
{
	hookAddress = (DWORD)PatternScan(
		"\xe8\x00\x00\x00\x00\x5f\x5e\x5b\x5d\xc2\x00\x00\x55\x8b\xec\x80\xb8",
		"x????xxxxx??xxxxx",
		0
	);

	// Get the address from the [call xxxxxxxx] instruction
	originalFunctionAddress = *(DWORD*)(hookAddress + 1) + HOOK_SIZE + hookAddress;
}

void KeyBindManager::hookFunction()
{
	trmpHook = new TrampolineHook((LPVOID)hookAddress, keyBindHook, HOOK_SIZE, false);
}

void KeyBindManager::initializeKeys()
{
	// General keys
	keyBinds.emplace(KeyBind(KeyCode::M, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::M, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::C, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::C, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::X, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::X, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::N, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::N, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::I, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::I, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::K, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::K, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::O, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::O, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::P, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::P, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::J, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::J, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::L, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::L, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::G, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::G, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::V, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::V, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F11, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F11, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::ESC, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::ESC, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::Z, KeyModifier::CTRL), KeyBind(KeyCode::Z, KeyModifier::CTRL));

	// Quick list
	keyBinds.emplace(KeyBind(KeyCode::TAB, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::TAB, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::SPACE, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::SPACE, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::Z, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::Z, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_0, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_0, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_1, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_1, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_2, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_2, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_3, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_3, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_4, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_4, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_5, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_5, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_6, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_6, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_7, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_7, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_8, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_8, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_9, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::_9, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::Q, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::Q, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::W, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::W, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::E, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::E, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::R, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::R, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::T, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::T, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::_0, KeyModifier::CTRL), KeyBind(KeyCode::_0, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_1, KeyModifier::CTRL), KeyBind(KeyCode::_1, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_2, KeyModifier::CTRL), KeyBind(KeyCode::_2, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_3, KeyModifier::CTRL), KeyBind(KeyCode::_3, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_4, KeyModifier::CTRL), KeyBind(KeyCode::_4, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_5, KeyModifier::CTRL), KeyBind(KeyCode::_5, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_6, KeyModifier::CTRL), KeyBind(KeyCode::_6, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_7, KeyModifier::CTRL), KeyBind(KeyCode::_7, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_8, KeyModifier::CTRL), KeyBind(KeyCode::_8, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_9, KeyModifier::CTRL), KeyBind(KeyCode::_9, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::Q, KeyModifier::CTRL), KeyBind(KeyCode::Q, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::W, KeyModifier::CTRL), KeyBind(KeyCode::W, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::E, KeyModifier::CTRL), KeyBind(KeyCode::E, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::R, KeyModifier::CTRL), KeyBind(KeyCode::R, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::T, KeyModifier::CTRL), KeyBind(KeyCode::T, KeyModifier::CTRL));
	keyBinds.emplace(KeyBind(KeyCode::_0, KeyModifier::ALT), KeyBind(KeyCode::_0, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_1, KeyModifier::ALT), KeyBind(KeyCode::_1, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_2, KeyModifier::ALT), KeyBind(KeyCode::_2, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_3, KeyModifier::ALT), KeyBind(KeyCode::_3, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_4, KeyModifier::ALT), KeyBind(KeyCode::_4, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_5, KeyModifier::ALT), KeyBind(KeyCode::_5, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_6, KeyModifier::ALT), KeyBind(KeyCode::_6, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_7, KeyModifier::ALT), KeyBind(KeyCode::_7, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_8, KeyModifier::ALT), KeyBind(KeyCode::_8, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::_9, KeyModifier::ALT), KeyBind(KeyCode::_9, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::Q, KeyModifier::ALT), KeyBind(KeyCode::Q, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::W, KeyModifier::ALT), KeyBind(KeyCode::W, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::E, KeyModifier::ALT), KeyBind(KeyCode::E, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::R, KeyModifier::ALT), KeyBind(KeyCode::R, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::T, KeyModifier::ALT), KeyBind(KeyCode::T, KeyModifier::ALT));

	// Mates
	keyBinds.emplace(KeyBind(KeyCode::A, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::A, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::S, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::S, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::D, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::D, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::H, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::H, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F1, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F1, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F2, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F2, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F3, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F3, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F4, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::F4, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::Q, KeyModifier::SHIFT), KeyBind(KeyCode::Q, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::W, KeyModifier::SHIFT), KeyBind(KeyCode::W, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::E, KeyModifier::SHIFT), KeyBind(KeyCode::E, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::R, KeyModifier::SHIFT), KeyBind(KeyCode::R, KeyModifier::SHIFT));

	// Emotes
	keyBinds.emplace(KeyBind(KeyCode::Q, KeyModifier::ALT), KeyBind(KeyCode::Q, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::W, KeyModifier::ALT), KeyBind(KeyCode::W, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::E, KeyModifier::ALT), KeyBind(KeyCode::E, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::R, KeyModifier::ALT), KeyBind(KeyCode::R, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::T, KeyModifier::ALT), KeyBind(KeyCode::T, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::Y, KeyModifier::ALT), KeyBind(KeyCode::Y, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::U, KeyModifier::ALT), KeyBind(KeyCode::U, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::I, KeyModifier::ALT), KeyBind(KeyCode::I, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::O, KeyModifier::ALT), KeyBind(KeyCode::O, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::P, KeyModifier::ALT), KeyBind(KeyCode::P, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::A, KeyModifier::ALT), KeyBind(KeyCode::A, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::S, KeyModifier::ALT), KeyBind(KeyCode::S, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::D, KeyModifier::ALT), KeyBind(KeyCode::D, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::F, KeyModifier::ALT), KeyBind(KeyCode::F, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::G, KeyModifier::ALT), KeyBind(KeyCode::G, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::H, KeyModifier::ALT), KeyBind(KeyCode::H, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::J, KeyModifier::ALT), KeyBind(KeyCode::J, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::K, KeyModifier::ALT), KeyBind(KeyCode::K, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::L, KeyModifier::ALT), KeyBind(KeyCode::L, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::Z, KeyModifier::ALT), KeyBind(KeyCode::Z, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::X, KeyModifier::ALT), KeyBind(KeyCode::X, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::C, KeyModifier::ALT), KeyBind(KeyCode::C, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::V, KeyModifier::ALT), KeyBind(KeyCode::V, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::B, KeyModifier::ALT), KeyBind(KeyCode::B, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::N, KeyModifier::ALT), KeyBind(KeyCode::N, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::M, KeyModifier::ALT), KeyBind(KeyCode::M, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::COMMA, KeyModifier::ALT), KeyBind(KeyCode::COMMA, KeyModifier::ALT));
	keyBinds.emplace(KeyBind(KeyCode::MINUS, KeyModifier::ALT), KeyBind(KeyCode::MINUS, KeyModifier::ALT));

	// Others (Not custom but needed to make the game work)
	keyBinds.emplace(KeyBind(KeyCode::ENTER, KeyModifier::NO_MODIFIER), KeyBind(KeyCode::ENTER, KeyModifier::NO_MODIFIER));
	keyBinds.emplace(KeyBind(KeyCode::F1, KeyModifier::SHIFT), KeyBind(KeyCode::F1, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F2, KeyModifier::SHIFT), KeyBind(KeyCode::F2, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F3, KeyModifier::SHIFT), KeyBind(KeyCode::F3, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F4, KeyModifier::SHIFT), KeyBind(KeyCode::F4, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F5, KeyModifier::SHIFT), KeyBind(KeyCode::F5, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F6, KeyModifier::SHIFT), KeyBind(KeyCode::F6, KeyModifier::SHIFT));
	keyBinds.emplace(KeyBind(KeyCode::F7, KeyModifier::SHIFT), KeyBind(KeyCode::F7, KeyModifier::SHIFT));
}
