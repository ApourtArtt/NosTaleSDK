#pragma once
#include "../../../DelphiClasses/TNTNewCharacterStandardInfoWidget.h"
#include "../../../DelphiClasses/TGameRootWidget.h"

/**
 * @brief Singleton wrapper around the game TNTNewCharacterStandardInfoWidget structure.
 */
class NewCharacterStandardInfoWidget
{
public:
	NewCharacterStandardInfoWidget(NewCharacterStandardInfoWidget& other) = delete;
	void operator=(const NewCharacterStandardInfoWidget& other) = delete;
	static NewCharacterStandardInfoWidget& getInstance();

	TGameRootWidget* getGameRootWidget();

private:
	NewCharacterStandardInfoWidget();
	void getAddresses();

	/**
	 * @brief Make changes to create our custom widget.
	 */
	void makeBeautiful();
	void makeMainWidgetBeautiful();
	void makeCharacterWidgetBeautiful();
	void makePartnerWidgetBeautiful();
	void makePetWidgetBeautiful();

private:
	TNTNewCharacterStandardInfoWidget* characterStandardInfoWidget;
};