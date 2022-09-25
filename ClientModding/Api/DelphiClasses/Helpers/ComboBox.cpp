#include "ComboBox.h"

namespace
{
	typedef std::function<void()> SubButtonCallback;
	typedef TList<TEWButtonWidget*>* SubButtonList;

	void onMenuClick(void* _, TEWGraphicButtonWidget* button)
	{
		SubButtonList subButtons = reinterpret_cast<SubButtonList>(button->getCallback().getArg());

		for (auto i = 0; i < subButtons->size(); i++)
		{
			auto currButton = subButtons->getItem(i);
			currButton->setVisible(!currButton->isVisible());
		}
	}

	void onSubButtonClick(void* _, TEWButtonWidget* subButton)
	{
		SubButtonCallback cb = *reinterpret_cast<SubButtonCallback*>(subButton->getCallback().getArg());
		cb();
	}
}

ComboBox::ComboBox(TEWButtonWidget* MainButton, CommonButtonProperties CommonButtonProperties, std::vector<WString*> Options, TEWGraphicButtonWidget* ArrowButton) noexcept
	: mainButton(MainButton)
	, commonButtonProperties(CommonButtonProperties)
	, options(Options)
	, arrowButton(ArrowButton)
{
	if (MainButton == nullptr)
	{
		Logger::Error("MainButton should not be nullptr");
		return;
	}

	mainButtonDefaultText = new WString(mainButton->getText());

	Border subButtonBorderBasis;
	if (commonButtonProperties.border.getHeight() == 0 || commonButtonProperties.border.getWidth() == 0)
		subButtonBorderBasis = mainButton->getBorder();
	else
		subButtonBorderBasis = commonButtonProperties.border;
	int16_t yIncrement = subButtonBorderBasis.getHeight();

	ImagePadding imgPadding;
	if (commonButtonProperties.imagePadding.getWidthMiddle() == 0 || commonButtonProperties.imagePadding.getPosRight() == 0)
		imgPadding = mainButton->getImagePadding();
	else
		imgPadding = commonButtonProperties.imagePadding;

	SubButtonList subButtons = new TList<TEWButtonWidget*>(options.size());
	for (auto i = 0; i < options.size(); i++)
	{
		TextPosition tp = mainButton->getTextPosition();
		tp.setText(options[i]->get());
		
		SubButtonCallback* cb = new SubButtonCallback([this, i]
		{
			hideSubButtons();
			mainButton->getTextPosition().setText(options[i]->get());
			currentIndex = i;
			cbOnIndexChange(i);
		});

		TEWButtonWidget* button = new TEWButtonWidget(
			mainButton->getParent(),
			Border(
				subButtonBorderBasis.topLeftX,
				subButtonBorderBasis.topLeftY + (yIncrement*(i+1)),
				subButtonBorderBasis.getWidth(),
				subButtonBorderBasis.getHeight()
			),
			commonButtonProperties.widgetBgra,
			commonButtonProperties.imageData,
			imgPadding,
			Callback(onSubButtonClick, cb),
			commonButtonProperties.unknown15,
			commonButtonProperties.nbUsablePictureViews,
			mainButton->getTextStyle(),
			tp
		);
		button->setVisible(false);
		Logger::Log("Button n%d: %x", i, button);

		menuSubButton.push_back(button);
		subButtons->push_back(button);
		mainButton->getParent()->addWidget(button);
	}

	if (arrowButton == nullptr)
	{
		arrowButton = new TEWGraphicButtonWidget(
			MainButton->getParent(),
			Border(
				MainButton->getBorder().botRightX + 1,
				MainButton->getBorder().topLeftY,
				17,
				18
			),
			Bgra(255, 255, 255, 255),
			ImageData(1593835568, 512, 512, new PictureDisplayer({
				PictureView(476, 381, 17, 18),
				PictureView(494, 381, 17, 18)
			})),
			ImagePadding(),
			Callback(),
			0,
			2
		);
		MainButton->getParent()->addWidget(arrowButton);
	}

	MainButton->getParent()->addWidget(MainButton);
	arrowButton->setVisible(MainButton->isVisible());

	mainButton->setCallback(Callback(onMenuClick, subButtons));
	arrowButton->setCallback(Callback(onMenuClick, subButtons));
}

void ComboBox::setVisible(bool value)
{
	mainButton->setVisible(value);
	arrowButton->setVisible(value);
}

void ComboBox::hideSubButtons()
{
	for (auto& subB : menuSubButton)
		subB->setVisible(false);
}
