#pragma once
#include "../../../DelphiClasses/TEWLabel.h"
#include "../../../DelphiClasses/TNTMaskingGaugeWidget.h"

class Spy
{
public:
	[[nodiscard]] static std::optional<Spy> Create(TNTMaskingGaugeWidget* hpGauge, TNTMaskingGaugeWidget* mpGauge);
	bool init{ false };
	TEWLabel* hpLabel{ nullptr };
	TEWLabel* mpLabel{ nullptr };
	WString hpString{ L"100/100" };
	WString mpString{ L"100/100" };

private:
	[[nodiscard]] TEWLabel* createGaugeElements(TNTMaskingGaugeWidget* gauge, WString* str);
};