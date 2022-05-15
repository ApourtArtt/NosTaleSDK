#pragma once
#include "Fps.h"
#include "Resolution.h"
#include "SkillsCooldown.h"
#include "KeyBindManager.h"

/**
 * @brief Singleton class that holds all related UI classes.
 */
class UI
{
public:
	UI(UI& other) = delete;
	void operator=(const UI& other) = delete;
	static UI& getInstance();

public:
	Fps fps;
	Resolution resolution;
	SkillsCooldown skillsCooldown;

private:
	UI() {}

};
