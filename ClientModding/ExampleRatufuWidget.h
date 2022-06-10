#pragma once
#include "Api/DelphiClasses/TLBSWidget.h"

class ExampleRatufuWidget
{
public:
	[[nodiscard]] bool Initialize(TLBSWidget* Parent, std::function<void()> OnClick);

private:
};
