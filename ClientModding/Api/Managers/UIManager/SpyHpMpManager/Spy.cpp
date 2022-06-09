#include "Spy.h"

std::optional<Spy> Spy::Create(TNTMaskingGaugeWidget* hpGauge, TNTMaskingGaugeWidget* mpGauge)
{
	auto _ = Logger::PushPopModuleName("Spy");
	Logger::Log("hpGauge: %x mpGauge: %x", hpGauge, mpGauge);

	Spy spy;

	TEWLabel* hpLabel = spy.createGaugeElements(hpGauge, &spy.hpString);
	if (hpLabel == nullptr)
		return std::nullopt;
	spy.hpLabel = hpLabel;

	TEWLabel* mpLabel = spy.createGaugeElements(mpGauge, &spy.mpString);
	if (mpLabel == nullptr)
		return std::nullopt;
	spy.mpLabel = mpLabel;

	spy.init = true;

	return spy;
}

TEWLabel* Spy::createGaugeElements(TNTMaskingGaugeWidget* gauge, WString* str)
{
	std::vector<TLBSWidget*> labels = gauge->findClassesWithExpectedSize(TEWLabel::NAME, 1);
	if (labels.size() == 0)
		return nullptr;

	TEWLabel* label = TObject::deepCopy(reinterpret_cast<TEWLabel*>(labels[0]));
	if (label == nullptr)
	{
		Logger::Error("label == nullptr");
		return nullptr;
	}
	Logger::Log("label deep copied from %x to %x", labels[0], label);

	label->setText(str->get());
	label->getTextPosition().setVisible(true);
	gauge->addWidget(label);
	return label;
}