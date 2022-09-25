#include "KeyBindWidget.h"
#include "../Wrappers/Widgets/NewCharacterStandardInfoWidget.h"

namespace
{
	constexpr int WIDTH = 400;
	constexpr int HEIGHT = 500;
}

KeyBindWidget& KeyBindWidget::getInstance()
{
	static KeyBindWidget instance;
	return instance;
}

void KeyBindWidget::show()
{
	KeyBindWidget::getInstance().setVisible(true);
}

void KeyBindWidget::close()
{
	KeyBindWidget::getInstance().setVisible(false);
}

KeyBindWidget::KeyBindWidget()
	: TEWCustomFormWidget(
		(TLBSWidget*)NewCharacterStandardInfoWidget::getInstance().getGameRootWidget(),
		Border(300, 50, WIDTH, HEIGHT),
		ImageData(
			1593835577,
			512,
			512,
			new PictureDisplayer({
				PictureView(59, 59, 40, 15),
				PictureView(1, 1, 58, 58),
				PictureView(59, 1, 40, 58),
				PictureView(99, 1, 14, 58),
				PictureView(99, 59, 14, 15),
				PictureView(99, 74, 14, 48),
				PictureView(59, 74, 40, 48),
				PictureView(1, 74, 58, 48),
				PictureView(1, 59, 58, 15),
				})
			),
		ImagePadding(
			58,
			WIDTH - 58 - 14,
			14,
			58,
			HEIGHT - 58 - 48,
			48
		))
{
	printf("Key Bind Widget = %p\n", this);

	// Main widget
	parent->addWidget(this);
	setVisible(true);
	setMovable(true);
	setLockPositionToScreen(true);
	setLockMargin(1);

	makeTabBar();
	makeTitle();
	makeCloseButton();
	makeCenterPanel();
	makeScrollBar();
}

void KeyBindWidget::makeTabBar()
{
	// Create tab buttons
	const int tabButtonWidgetStartX = 8;
	const int tabButtonHeight = 38;
	const int tabButtonWidgetStartY = HEIGHT - tabButtonHeight - 10;
	const int tabButtonWidth = (WIDTH - tabButtonWidgetStartX * 3) / 4;

	ImageData tabImageData(
		1593835585,
		512,
		512,
		new PictureDisplayer({
			PictureView(131, 249, 129, 36),
			PictureView(1, 249, 129, 36)
			})
	);


	// General tab button
	generalTabButton = new TEWGraphicButtonWidget(
		this,
		Border(tabButtonWidgetStartX, tabButtonWidgetStartY, tabButtonWidth, tabButtonHeight),
		Bgra(255, 255, 255, 255),
		tabImageData,
		ImagePadding(),
		Callback(on_generalTabButton_clicked, 0),
		0,
		2
	);

	TEWLabel* generalTabLabel = new TEWLabel(
		generalTabButton,
		Border(0, 0, tabButtonWidth, tabButtonHeight),
		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(196, 199, 197, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(5, 11, 81, 16, new WString(L"General"), true)
	);

	generalTabLabel->setVisible(true);
	generalTabButton->addWidget(generalTabLabel);
	generalTabButton->setVisible(true);
	addWidget(generalTabButton);

	// Quicklist tab button
	quicklistTabButton = new TEWGraphicButtonWidget(
		this,
		Border(tabButtonWidgetStartX + tabButtonWidth, tabButtonWidgetStartY, tabButtonWidth, tabButtonHeight),
		Bgra(255, 255, 255, 255),
		tabImageData,
		ImagePadding(),
		Callback(on_generalTabButton_clicked, 0),
		0,
		2
	);

	TEWLabel* quicklistTabLabel = new TEWLabel(
		quicklistTabButton,
		Border(0, 0, tabButtonWidth, tabButtonHeight),
		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(196, 199, 197, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(5, 11, 81, 16, new WString(L"Quicklist"), true)
	);

	quicklistTabLabel->setVisible(true);
	quicklistTabButton->addWidget(quicklistTabLabel);
	quicklistTabButton->setVisible(true);
	addWidget(quicklistTabButton);

	// Mates tab button
	matesTabButton = new TEWGraphicButtonWidget(
		this,
		Border(tabButtonWidgetStartX + tabButtonWidth * 2, tabButtonWidgetStartY, tabButtonWidth, tabButtonHeight),
		Bgra(255, 255, 255, 255),
		tabImageData,
		ImagePadding(),
		Callback(on_generalTabButton_clicked, 0),
		0,
		2
	);

	TEWLabel* matesTabLabel = new TEWLabel(
		matesTabButton,
		Border(0, 0, tabButtonWidth, tabButtonHeight),
		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(196, 199, 197, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(5, 11, 81, 16, new WString(L"Mates"), true)
	);

	matesTabLabel->setVisible(true);
	matesTabButton->addWidget(matesTabLabel);
	matesTabButton->setVisible(true);
	addWidget(matesTabButton);

	// Emotes tab button
	emotesTabButton = new TEWGraphicButtonWidget(
		this,
		Border(tabButtonWidgetStartX + tabButtonWidth * 3, tabButtonWidgetStartY, tabButtonWidth, tabButtonHeight),
		Bgra(255, 255, 255, 255),
		tabImageData,
		ImagePadding(),
		Callback(on_generalTabButton_clicked, 0),
		0,
		2
	);

	TEWLabel* emotesTabLabel = new TEWLabel(
		emotesTabButton,
		Border(0, 0, tabButtonWidth, tabButtonHeight),
		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(196, 199, 197, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(5, 11, 81, 16, new WString(L"Emotes"), true)
	);

	emotesTabLabel->setVisible(true);
	emotesTabButton->addWidget(emotesTabLabel);
	emotesTabButton->setVisible(true);
	addWidget(emotesTabButton);
}

void KeyBindWidget::makeTitle()
{
	titleLabel = new TEWLabel(
		this,
		Border(0, 0, WIDTH, 30),
		TextStyle(3, TextShadowOrientation::ShadowRight, Bgra(255, 255, 255, 255), Bgra(63, 63, 63, 255), TextAlignment::CenteredLeft),
		TextPosition(10, 16, WIDTH, 0, new WString(L"Keybinds"), true)
	);

	titleLabel->setVisible(true);
	addWidget(titleLabel);
}

void KeyBindWidget::makeCloseButton()
{
	int closeButtonWidth = 20;
	int closeButtonHeight = 21;

	closeButton = new TEWGraphicButtonWidget(
		this,
		Border(WIDTH - closeButtonWidth - 7, 7, closeButtonWidth, closeButtonHeight),
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer({
			PictureView(244, 2, 20, 20),
			PictureView(264, 2, 20, 20),
			PictureView(244, 22, 20, 20)
			})),
		ImagePadding(),
		Callback(on_closeButton_clicked, 0),
		0,
		3
	);

	closeButton->setVisible(true);
	addWidget(closeButton);
}

void KeyBindWidget::makeScrollBar()
{
	TEWScrollBarThumb* scrollThumb = new TEWScrollBarThumb(
		nullptr,
		Border(0, 0, 17, 198),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(476, 361, 17, 7),
			PictureView(476, 356, 17, 5),
			PictureView(476, 368, 17, 6)
			})),
		ImagePadding(0, 17, 0, 5, 187, 6)
	);
	scrollThumb->setVisible(true);
	scrollThumb->setHandlingClick(true);

	TEWScrollBarTrack* scroller = new TEWScrollBarTrack(
		nullptr,
		Border(0, 18, 17, 400),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(507, 401, 3, 1),
			PictureView(506, 400, 1, 1),
			PictureView(507, 400, 3, 1),
			PictureView(510, 400, 1, 1),
			PictureView(510, 401, 1, 1),
			PictureView(510, 402, 1, 1),
			PictureView(507, 402, 3, 1),
			PictureView(506, 402, 1 ,1),
			PictureView(506, 401, 1, 1)
			})),
		ImagePadding(1, 15, 1, 1, 398, 1),
		Callback(0, 0),
		scrollThumb
	);
	scroller->setVisible(true);
	scroller->setHandlingClick(true);

	TEWGraphicButtonWidget* topButton = new TEWGraphicButtonWidget(
		nullptr,
		Border(0, 0, 17, 18),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({ PictureView(476, 332, 17, 18) })),
		ImagePadding(),
		Callback(0, 0),
		0,
		1
	);
	topButton->setVisible(true);
	topButton->setHandlingClick(true);

	TEWGraphicButtonWidget* botButton = new TEWGraphicButtonWidget(
		nullptr,
		Border(0, 388, 17, 18),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer({ PictureView(476, 381, 17, 18) })),
		ImagePadding(),
		Callback(0, 0),
		0,
		1
	);

	botButton->setVisible(true);
	botButton->setHandlingClick(true);

	scrollBar = new TEWScrollBar(
		this,
		Border(centerPanel->getWidth() - 20, 1, 17, centerPanel->getHeight() - 1),
		Callback(0, 0),
		scroller,
		topButton,
		botButton
	);
	printf("Scroll bar : %p\n", scrollBar);

	scrollBar->setVisible(true);
	scrollBar->setHandlingClick(true);
	centerPanel->addWidget(scrollBar);
	//addWidget(scrollBar);
}

void KeyBindWidget::makeCenterPanel()
{
	centerPanel = new TEWCustomPanelWidget(
		this,
		Border(13, 43, 373, 407),
		ImageData(1593835577, 512, 512, new PictureDisplayer({
			PictureView(270, 252, 8, 8),
			PictureView(260, 242, 10, 10),
			PictureView(270, 242, 8, 10),
			PictureView(278, 242, 10, 10),
			PictureView(278, 252, 10, 8),
			PictureView(278, 260, 10, 10),
			PictureView(270, 260, 8, 10),
			PictureView(260, 260, 10, 10),
			PictureView(260, 252, 10, 8)
			})),
		ImagePadding(10, 353, 10, 10, 387, 10)
	);
	centerPanel->setVisible(true);
	centerPanel->setHandlingClick(true);
	addWidget(centerPanel);
}

void __fastcall KeyBindWidget::on_generalTabButton_clicked()
{
	printf("Clicked\n");
}

void __fastcall KeyBindWidget::on_closeButton_clicked()
{
	close();
}
