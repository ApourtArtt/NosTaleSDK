#pragma once
#include "../../../MemoryHelper/TrampolineHook.h"
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"
#include "../../Enums/KeyCode.h"
#include "../../Enums/KeyModifier.h"
#include <map>

typedef std::pair<KeyCode, KeyModifier> KeyBind;

/**
 * @brief Singleton class that hook game function and allow use to use custom keybinds.
 */
class KeyBindManager
{
public:
	KeyBindManager(KeyBindManager& other) = delete;
	void operator=(const KeyBindManager& other) = delete;
	static KeyBindManager& getInstance();

	~KeyBindManager();

	/**
	 * @brief Change a custom key from the original value.
	 * 
	 * @param original Original key bind to redirect
	 * @param newKey New key bind that will be used instead of the original key
	 * @return true if success, false if not
	 */
	bool setCustomKey(const KeyBind& original, const KeyBind& newKey);

	/**
	 * @brief Search for value instead of key in the std::map.
	 * 
	 * @param originalKey the value
	 * @return const reference to the key
	 */
	const KeyBind& getCustomKey(const KeyBind& originalKey);

	/**
	 * @brief Search in the map for value instead of key.
	 *
	 * @param customKey the value we want to search for
	 * @param result if value is found key will be stored here
	 * @return true if value exist, false if not
	 */
	bool contains(const KeyBind& customKey, KeyBind& result);

private:
	KeyBindManager();

	void getAddresses();
	void hookFunction();
	void initializeKeys();

private:
	static constexpr int HOOK_SIZE = 5;
	DWORD hookAddress;
	TrampolineHook* trmpHook;
	std::map <KeyBind /* original key */, KeyBind /* custom key*/> keyBinds;
};
