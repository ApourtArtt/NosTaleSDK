#include "Example.h"

Example::Example(const ClientModdingConfig& Config)
	: ClientModding(Config)
{
	// If you want to do something before ClientModding::Initialize runs.
	// You must use beforeRun is priority - this should only be used when
	// your instruction would not work in beforeRun.
	// The reason is that nearly nothing (actually, only Discord is ready)
	// when this function is called, while beforeRun is called *after*
	// everything is initialized.
	// Exception for packet handling, you can already subscribe here.
}

bool Example::beforeRun()
{
	// This method is called after calling Example::Run().
	// You can expect every widgets and modules provided by this API to work
	// once this is called, everything is ready.
	// You should add here, everything that must be initialized, done once.
	// Example: if you want to create a widget, you should create it here.

	if (!ratufuWidget.Initialize(ntWidgetHandler->getGameRootWidget()))
	{
		Logger::Log("[RatufuWidget] Failed initialization");
		return false;
	}
	Logger::Log("[RatufuWidget] Successfully initialized");

	return true;
}

void Example::tick()
{
	// This method is called every tick once you call Example::Run() and after
	// beforeRun returns true.
	// You should add here, everything that must be done periodically.
	// Example: refreshing the clock if you have one, etc.
}
