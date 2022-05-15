#pragma once
#include "KeyBindManager.h"
#include "../../DelphiClasses/TEWCustomFormWidget.h"
#include "../../DelphiClasses/TEWGraphicButtonWidget.h"
#include "../../DelphiClasses/TEWLabel.h"
#include "../../DelphiClasses/TEWScrollBar.h"

/**
 * @brief Custom key bind widget.
 */
class KeyBindWidget : public TEWCustomFormWidget
{
public:
	KeyBindWidget(KeyBindWidget& other) = delete;
	void operator=(const KeyBindWidget& other) = delete;
	static KeyBindWidget& getInstance();

	static void __fastcall show();
	static void __fastcall close();

private:
	KeyBindWidget();

	void makeTabBar();
	void makeTitle();
	void makeCloseButton();
	void makeScrollBar();
	void makeCenterPanel();

	static void __fastcall on_generalTabButton_clicked();
	static void __fastcall on_closeButton_clicked();

private:
	// Tab bar
	TEWGraphicButtonWidget* generalTabButton;
	TEWGraphicButtonWidget* quicklistTabButton;
	TEWGraphicButtonWidget* matesTabButton;
	TEWGraphicButtonWidget* emotesTabButton;

	// Close window button
	TEWGraphicButtonWidget* closeButton;

	// Title
	TEWLabel* titleLabel;

	// Scrollbar
	TEWScrollBar* scrollBar;

	// Center panel
	TEWCustomPanelWidget* centerPanel;
};
