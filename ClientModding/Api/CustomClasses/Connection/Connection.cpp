#include "Connection.h"

Connection::Connection()
	: servChan()
{}

bool Connection::Initialize()
{
	if (!servChan.Initialize())
		return false;

	return true;
}
