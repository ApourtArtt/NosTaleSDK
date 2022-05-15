#pragma once
#include "../../../DelphiClasses/TNTGameOptionWidget.h"
#include "../../../DelphiClasses/TEWGraphicButtonWidget.h"
#include "../../../DelphiClasses/TEWButtonWidget.h"

/**
 * @brief Singleton wrapper around the game TGameOptionWidget structure.
 */
class GameOptionWidget
{
public:
	GameOptionWidget(GameOptionWidget& other) = delete;
	void operator=(const GameOptionWidget& other) = delete;
	static GameOptionWidget& getInstance();
private:
	GameOptionWidget();

	static void __fastcall on_fpsComboBoxArrowButton_clicked();
	static void __fastcall on_fps30Button_Clicked();
	static void __fastcall on_fps60Button_Clicked();
	static void __fastcall on_fps120Button_Clicked();
	static void __fastcall on_fps144Button_Clicked();
	static void __fastcall on_fps240Button_Clicked();
	static void __fastcall on_fpsUnlimitedButton_Clicked();
	static void __fastcall on_resolutionComboBoxArrowButton_clicked();
	static void __fastcall on_resolution1920x1080Button_clicked();
	static void __fastcall on_resolution1024x768Button_clicked();
	static void __fastcall on_resolution1280x1024Button_clicked();
	static void __fastcall on_resolution1280x800Button_clicked();
	static void __fastcall on_resolution1440x900Button_clicked();
	static void __fastcall on_resolution1024x700Button_clicked();
	static void __fastcall on_resolution1680x1050Button_clicked();
	static void __fastcall on_resolutionFullScreenWindowed_clicked();
	static void __fastcall on_keyBindButton_clicked();

	void setFpsComboItemsVisible(bool state);
	void setResolutionComboItemsVisible(bool state);

	/**
	 * @brief Add our custom widgets to the game widget.
	 */
	void makeBeautiful();
	void getAddresses();

private:
	TNTGameOptionWidget* gameOptionWidget;
	TEWLabel* fpsLabel;
	TEWButtonWidget* fpsComboBox;
	TEWButtonWidget* fps30Button;
	TEWButtonWidget* fps60Button;
	TEWButtonWidget* fps120Button;
	TEWButtonWidget* fps144Button;
	TEWButtonWidget* fps240Button;
	TEWButtonWidget* fpsUnlimitedButton;
	TEWGraphicButtonWidget* fpsComboBoxArrowButton;
	TEWButtonWidget* resolutionComboBox;
	TEWButtonWidget* resolution1024x768Button;
	TEWButtonWidget* resolution1280x1024Button;
	TEWButtonWidget* resolution1280x800Button;
	TEWButtonWidget* resolution1440x900Button;
	TEWButtonWidget* resolution1024x700Button;
	TEWButtonWidget* resolution1680x1050Button;
	TEWButtonWidget* resolution1920x1080Button;
	TEWButtonWidget* resolutionFullScreenWindowed;
	TEWGraphicButtonWidget* resolutionComboBoxArrowButton;
	TEWGraphicButtonWidget* keyBindButton;
	bool isFpsMenuVisible;
	bool isResolutionMenuVisible;
};