#include "GameOptionWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../UI/UI.h"
#include "../../UI/KeyBindWidget.h"

GameOptionWidget& GameOptionWidget::getInstance()
{
	static GameOptionWidget instance;
	return instance;
}

void GameOptionWidget::makeBeautiful()
{
	if (gameOptionWidget == nullptr) return;

	const int COMBO_BOX_WIDTH = 90;
	const int COMBO_BOX_HEIGHT = 17;
	const int ARROW_BUTTON_WIDTH = 17;
	const int ARROW_BUTTON_HEIGHT = 18;

	// Hide default resolution buttons
	gameOptionWidget->resolution1024x700Button->setVisible(false);
	gameOptionWidget->resolution1024x768Button->setVisible(false);
	gameOptionWidget->resolution1280x1024Button->setVisible(false);
	gameOptionWidget->resolution1280x800Button->setVisible(false);
	gameOptionWidget->resolution1440x900Button->setVisible(false);
	gameOptionWidget->resolution1680x1050Button->setVisible(false);
	gameOptionWidget->fullScreenWindowModeButton->setVisible(false);

	// Move resolution label
	gameOptionWidget->resolutionLabel->moveWidget(0, 20);

	// Move window mode checkbox
	gameOptionWidget->windowModeButton->setVisible(false);
	gameOptionWidget->windowModeLabel->setVisible(false);

	// Create fps limit label
	fpsLabel = new TEWLabel(
		gameOptionWidget->displayConfigurationWidget,
		Border(12, 68, 238, 15),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::TopLeft),
		TextPosition(1, 1, 236, 13, new WString(L"FPS limit"), true)
	);

	// Main fps combo widget
	fpsComboBox = new TEWButtonWidget(
		gameOptionWidget->displayConfigurationWidget,
		Border(89, 68, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({ 
			PictureView(269, 272, 9, 17), 
			PictureView(278, 272, 4, 17), 
			PictureView(265, 272, 4, 17) 
		})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fpsComboBoxArrowButton_clicked, 0),
		4,
		1,												
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"- - -"), true)
	);

	// Fps combo box arrow
	fpsComboBoxArrowButton = new TEWGraphicButtonWidget(
		gameOptionWidget->displayConfigurationWidget,
		Border(180, 68, ARROW_BUTTON_WIDTH, ARROW_BUTTON_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(476, 381, 17, 18),
			PictureView(494, 381, 17, 18)
		})),
		ImagePadding(),
		Callback(on_fpsComboBoxArrowButton_clicked, 0),
		0,
		2
	);

	// Combo items
	fps30Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 110, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
		})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fps30Button_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"30"), true)
	);

	fps60Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 127, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fps60Button_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"60"), true)
	);

	fps120Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 144, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fps120Button_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"120"), true)
	);

	fps144Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 161, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fps144Button_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"144"), true)
	);

	fps240Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 178, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fps240Button_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"240"), true)
	);

	fpsUnlimitedButton = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 195, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_fpsUnlimitedButton_Clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"Unlimited"), true)
	);

	// Create resolution combo box
	resolutionComboBox = new TEWButtonWidget(
		gameOptionWidget->displayConfigurationWidget,
		Border(89, 46, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolutionComboBoxArrowButton_clicked, 0),
		4,
		1,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"- - -"), true)
	);

	resolutionComboBoxArrowButton = new TEWGraphicButtonWidget(
		gameOptionWidget->displayConfigurationWidget,
		Border(180, 46, ARROW_BUTTON_WIDTH, ARROW_BUTTON_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(476, 381, 17, 18),
			PictureView(494, 381, 17, 18)
			})),
		ImagePadding(),
		Callback(on_resolutionComboBoxArrowButton_clicked, 0),
		0,
		2
	);

	resolution1024x700Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 88, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1024x700Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1024x700"), true)
	);

	resolution1024x768Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 105, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1024x768Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1024x768"), true)
	);

	resolution1280x1024Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 122, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1280x1024Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1280x1024"), true)
	);

	resolution1280x800Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 139, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1280x800Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1280x800"), true)
	);

	resolution1440x900Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 156, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1440x900Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1440x900"), true)
	);

	resolution1680x1050Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 173, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1680x1050Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1680x1050"), true)
	);

	resolution1920x1080Button = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 190, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolution1920x1080Button_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"1920x1080"), true)
	);

	resolutionFullScreenWindowed = new TEWButtonWidget(
		gameOptionWidget,
		Border(89, 207, COMBO_BOX_WIDTH, COMBO_BOX_HEIGHT),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
			})),
		ImagePadding(4, 82, 4, 0, 17, 0),
		Callback(on_resolutionFullScreenWindowed_clicked, 0),
		4,
		3,
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(4, 242, 177, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(3, 1, 88, 17, new WString(L"FullScreen"), true)
	);

	// Move bottom buttons
	gameOptionWidget->resetUIPositionButton->moveWidget(-60, 0);
	gameOptionWidget->confirmButton->moveWidget(-60, 0);
	gameOptionWidget->confirmButton->incrementSize(120, 0);
	gameOptionWidget->confirmLabel->incrementSize(120, 0);
	gameOptionWidget->confirmLabel->setPxPerLine(gameOptionWidget->confirmButton->getWidth() - 2);

	// Create key bind button
	keyBindButton = new TEWGraphicButtonWidget(
		gameOptionWidget->bottomWidget,
		Border(129, 5, 119, 28),
		Bgra(255, 255, 255, 255),
		ImageData(
			1593835585,
			512,
			512,
			new PictureDisplayer({
				PictureView(289, 481, 3, 2),
				PictureView(280, 464, 9, 17),
				PictureView(289, 464, 3, 17),
				PictureView(292, 464, 10, 17),
				PictureView(292, 481, 10, 2),
				PictureView(292, 483, 10, 13),
				PictureView(289, 483, 3, 13),
				PictureView(280, 483, 9, 13),
				PictureView(280, 481, 9, 2),
				PictureView(370, 496, 3, 2),
				PictureView(361, 479, 9, 17),
				PictureView(370, 479, 3, 17),
				PictureView(373, 479, 10, 17),
				PictureView(373, 496, 10, 2),
				PictureView(373, 498, 10, 13),
				PictureView(370, 498, 3, 13),
				PictureView(361, 498, 9, 13),
				PictureView(361, 496, 9, 2),
				PictureView(465, 448, 3, 2),
				PictureView(456, 431, 9, 17),
				PictureView(465, 431, 3, 17),
				PictureView(468, 431, 10, 17),
				PictureView(468, 448, 10, 2),
				PictureView(468, 450, 10, 13),
				PictureView(465, 450, 3, 13),
				PictureView(456, 450, 9, 13),
				PictureView(456, 448, 9, 2)
				})
		),
		ImagePadding(9, 100, 10, 17, -2, 13),
		Callback(on_keyBindButton_clicked, 0),
		5,
		3
	);

	TEWLabel* keyBindLabel = new TEWLabel(
		keyBindButton,
		Border(0, 6, 119, 16),
		TextStyle(1, TextShadowOrientation::ShadowAll, Bgra(255, 219, 187, 255), Bgra(198, 82, 16, 255), TextAlignment::CenteredCentered),
		TextPosition(1, 1, 117, 14, new WString(L"Change keybinds"), true)
	);

	printf("Key bind button = %p\n", keyBindButton);

	keyBindLabel->setVisible(true);
	keyBindButton->addWidget(keyBindLabel);
	keyBindButton->setVisible(true);
	gameOptionWidget->bottomWidget->addWidget(keyBindButton);

	fpsComboBox->setVisible(true);
	fpsLabel->setVisible(true);
	fpsComboBoxArrowButton->setVisible(true);
	resolutionComboBox->setVisible(true);
	resolutionComboBoxArrowButton->setVisible(true);

	gameOptionWidget->displayConfigurationWidget->addWidget(fpsComboBox);
	gameOptionWidget->displayConfigurationWidget->addWidget(fpsLabel);
	gameOptionWidget->displayConfigurationWidget->addWidget(fpsComboBoxArrowButton);
	gameOptionWidget->displayConfigurationWidget->addWidget(resolutionComboBox);
	gameOptionWidget->displayConfigurationWidget->addWidget(resolutionComboBoxArrowButton);
	gameOptionWidget->addWidget(fps30Button);
	gameOptionWidget->addWidget(fps60Button);
	gameOptionWidget->addWidget(fps120Button);
	gameOptionWidget->addWidget(fps144Button);
	gameOptionWidget->addWidget(fps240Button);
	gameOptionWidget->addWidget(fpsUnlimitedButton);
	gameOptionWidget->addWidget(resolution1024x700Button);
	gameOptionWidget->addWidget(resolution1024x768Button);
	gameOptionWidget->addWidget(resolution1280x1024Button);
	gameOptionWidget->addWidget(resolution1280x800Button);
	gameOptionWidget->addWidget(resolution1440x900Button);
	gameOptionWidget->addWidget(resolution1680x1050Button);
	gameOptionWidget->addWidget(resolution1920x1080Button);
	gameOptionWidget->addWidget(resolutionFullScreenWindowed);
}

void GameOptionWidget::getAddresses()
{
	auto address = PatternScan(
		"\xa1\x00\x00\x00\x00\x8b\x00\x8b\x10\xff\x52\x00\x33\xd2",
		"x????xxxxxx?xx",
		1
	);

	if (!address)
	{
		gameOptionWidget = nullptr;
		return;
	}

	gameOptionWidget = ***(TNTGameOptionWidget****)address;
}

void GameOptionWidget::on_fpsComboBoxArrowButton_clicked()
{
	if (GameOptionWidget::getInstance().isResolutionMenuVisible)
	{
		GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	}

	bool isVisible = GameOptionWidget::getInstance().isFpsMenuVisible;
	GameOptionWidget::getInstance().setFpsComboItemsVisible(!isVisible);
}

void GameOptionWidget::on_fps30Button_Clicked()
{
	UI::getInstance().fps.SetFps(30);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fps30Button->getText());
}

void GameOptionWidget::on_fps60Button_Clicked()
{
	UI::getInstance().fps.SetFps(60);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fps60Button->getText());
}

void GameOptionWidget::on_fps120Button_Clicked()
{
	UI::getInstance().fps.SetFps(120);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fps120Button->getText());
}

void GameOptionWidget::on_fps144Button_Clicked()
{
	UI::getInstance().fps.SetFps(144);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fps144Button->getText());
}

void GameOptionWidget::on_fps240Button_Clicked()
{
	UI::getInstance().fps.SetFps(240);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fps240Button->getText());
}

void GameOptionWidget::on_fpsUnlimitedButton_Clicked()
{
	UI::getInstance().fps.SetRefreshRate(0);
	GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	GameOptionWidget::getInstance().fpsComboBox->setText(GameOptionWidget::getInstance().fpsUnlimitedButton->getText());
}

void GameOptionWidget::on_resolutionComboBoxArrowButton_clicked()
{
	if (GameOptionWidget::getInstance().isFpsMenuVisible)
	{
		GameOptionWidget::getInstance().setFpsComboItemsVisible(false);
	}

	bool isVisible = GameOptionWidget::getInstance().isResolutionMenuVisible;
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(!isVisible);
}

void GameOptionWidget::on_resolution1920x1080Button_clicked()
{
	UI::getInstance().resolution.SetResolution(7);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1920x1080Button->getText());
}

void GameOptionWidget::on_resolution1024x768Button_clicked()
{
	UI::getInstance().resolution.SetResolution(1);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1024x768Button->getText());
}

void GameOptionWidget::on_resolution1280x1024Button_clicked()
{
	UI::getInstance().resolution.SetResolution(2);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1280x1024Button->getText());
}

void GameOptionWidget::on_resolution1280x800Button_clicked()
{
	UI::getInstance().resolution.SetResolution(3);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1280x800Button->getText());
}

void GameOptionWidget::on_resolution1440x900Button_clicked()
{
	UI::getInstance().resolution.SetResolution(4);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1440x900Button->getText());
}

void GameOptionWidget::on_resolution1024x700Button_clicked()
{
	UI::getInstance().resolution.SetResolution(5);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1024x700Button->getText());
}

void GameOptionWidget::on_resolution1680x1050Button_clicked()
{
	UI::getInstance().resolution.SetResolution(6);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolution1680x1050Button->getText());
}

void GameOptionWidget::on_resolutionFullScreenWindowed_clicked()
{
	UI::getInstance().resolution.SetResolution(0);
	GameOptionWidget::getInstance().setResolutionComboItemsVisible(false);
	GameOptionWidget::getInstance().resolutionComboBox->setText(GameOptionWidget::getInstance().resolutionFullScreenWindowed->getText());
}

void __fastcall GameOptionWidget::on_keyBindButton_clicked()
{
	KeyBindWidget::show();
}

GameOptionWidget::GameOptionWidget()
{
	isFpsMenuVisible = false;
	isResolutionMenuVisible = false;
	getAddresses();
	makeBeautiful();
}

void GameOptionWidget::setFpsComboItemsVisible(bool state)
{
	GameOptionWidget::getInstance().fps30Button->setVisible(state);
	GameOptionWidget::getInstance().fps60Button->setVisible(state);
	GameOptionWidget::getInstance().fps120Button->setVisible(state);
	GameOptionWidget::getInstance().fps144Button->setVisible(state);
	GameOptionWidget::getInstance().fps240Button->setVisible(state);
	GameOptionWidget::getInstance().fpsUnlimitedButton->setVisible(state);
	GameOptionWidget::getInstance().isFpsMenuVisible = state;
}

void GameOptionWidget::setResolutionComboItemsVisible(bool state)
{
	GameOptionWidget::getInstance().resolution1024x700Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1024x768Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1280x1024Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1280x800Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1440x900Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1680x1050Button->setVisible(state);
	GameOptionWidget::getInstance().resolution1920x1080Button->setVisible(state);
	GameOptionWidget::getInstance().resolutionFullScreenWindowed->setVisible(state);
	GameOptionWidget::getInstance().isResolutionMenuVisible = state;
}
