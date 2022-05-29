#pragma once
#include "ClientModding.h"
#include "ExampleRatufuWidget.h"

class Example : public ClientModding // We need to inherit from ClientModding
{
public:
	explicit Example();

private:
	bool beforeRun() override;
	void tick() override;

	ExampleRatufuWidget ratufuWidget;
};
