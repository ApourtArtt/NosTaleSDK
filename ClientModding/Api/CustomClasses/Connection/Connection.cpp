#include "Connection.h"
#include "../../../Utils/Logger.h"

Connection::Connection()
	: servChan()
{}

bool Connection::Initialize()
{
	auto _ = Logger::PushPopModuleName("Connection");

	if (!servChan.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}
