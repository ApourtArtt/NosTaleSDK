#include "GameRootWidget.h"

GameRootWidget& GameRootWidget::getInstance()
{
	static GameRootWidget instance;
	return instance;
}

void GameRootWidget::toggle()
{
	if (gameRootWidget == nullptr) return;

	if (gameRootWidget->isVisible())
	{
		toggleOff();
		return;
	}

	toggleOn();
}

void GameRootWidget::toggleOn()
{
	if (gameRootWidget == nullptr) return;
	gameRootWidget->setVisible(true);
}

void GameRootWidget::toggleOff()
{
	if (gameRootWidget == nullptr) return;
	gameRootWidget->setVisible(false);
}

GameRootWidget::GameRootWidget()
{
	gameRootWidget = NewCharacterStandardInfoWidget::getInstance().getGameRootWidget();
}
