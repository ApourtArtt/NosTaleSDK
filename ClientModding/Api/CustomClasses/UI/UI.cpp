#include "UI.h"

UI& UI::getInstance()
{
	static UI instance;
	return instance;
}
