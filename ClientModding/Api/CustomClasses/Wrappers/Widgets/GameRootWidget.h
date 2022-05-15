#pragma once
#include "../../../DelphiClasses/TGameRootWidget.h"
#include "NewCharacterStandardInfoWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"

/**
 * @brief Singleton wrapper around the game TGameRootWidget structure.
 */
class GameRootWidget
{
public:
	GameRootWidget(GameRootWidget& other) = delete;
	void operator=(const GameRootWidget& other) = delete;
	static GameRootWidget& getInstance();

	void toggle();
	void toggleOn();
	void toggleOff();

private:
	GameRootWidget();

private:
	TGameRootWidget* gameRootWidget;
};