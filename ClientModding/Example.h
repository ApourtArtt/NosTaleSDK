#pragma once
#include "ClientModding.h"
#include "ExampleRatufuWidget.h"

class Example : public ClientModding // We need to inherit from ClientModding
{
public:
	[[nodiscard]] explicit Example(const ClientModdingConfig& Config) noexcept;

private:
	[[nodiscard]] bool beforeRun() noexcept override;
	void tick() noexcept override;

	ExampleRatufuWidget ratufuWidget;
};
