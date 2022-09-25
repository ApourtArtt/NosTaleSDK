#pragma once
#include "../TEWButtonWidget.h"

class ComboBox
{
public:
	typedef int32_t IndexType;
	struct CommonButtonProperties
	{
		Border border;
		Bgra widgetBgra{ 255, 255, 255, 255 };
		ImageData imageData{ 1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
		}) };
		ImagePadding imagePadding;
		char unknown15{ 4 };
		int8_t nbUsablePictureViews{ 3 };
	};

	[[nodiscard]] explicit ComboBox(
		TEWButtonWidget* MainButton,
		CommonButtonProperties CommonButtonProperties,
		std::vector<WString*> Options,
		TEWGraphicButtonWidget* ArrowButton = nullptr
	) noexcept;

	typedef std::function<void(IndexType)> OnIndexChangeCallback;
	void setOnIndexChange(OnIndexChangeCallback callback) { cbOnIndexChange = callback; }

	IndexType getCurrentIndex() { return currentIndex; }

	void setVisible(bool value);

private:
	void hideSubButtons();

	WString* mainButtonDefaultText{ nullptr };
	TEWButtonWidget* mainButton;
	CommonButtonProperties commonButtonProperties;
	std::vector<WString*> options;
	std::vector<TEWButtonWidget*> menuSubButton;
	TEWGraphicButtonWidget* arrowButton;
	OnIndexChangeCallback cbOnIndexChange{ [](IndexType) {} };

	IndexType currentIndex{ -1 };
};
