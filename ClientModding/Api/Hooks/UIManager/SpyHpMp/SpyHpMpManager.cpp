#include "SpyHpMpManager.h"
#include "../../../../Utils/Logger.h"
#include "../../../../Utils/Split.h"
#include "../../../DelphiClasses/TLBSWidgetHandler.h"
#include "../../../DelphiClasses/TNTMaskingGaugeWidget.h"

SpyHpMpManager::SpyHpMpManager(const SpyHpMpManagerConfig& Config)
	: config(Config)
{
}

bool SpyHpMpManager::Initialize()
{
	auto _ = Logger::PushPopModuleName("SpyHpMpManager");

	TLBSWidgetHandler* ntWidgetHandler = TLBSWidgetHandler::getNosTaleUniqueInstance();
	if (ntWidgetHandler == nullptr)
		return false;

	TGameRootWidget* gameRootWidget = ntWidgetHandler->getGameRootWidget();
	if (gameRootWidget == nullptr)
		return false;

	if (config.SpyTarget.Activate)
	{
		std::vector<TLBSWidget*> widgets = gameRootWidget->findClassesWithExpectedSize(TNTMonsterSummaryInfoWidget::NAME, 1);
		if (widgets.size() == 0)
			return false;

		TNTMonsterSummaryInfoWidget* widget = reinterpret_cast<TNTMonsterSummaryInfoWidget*>(widgets[0]);
		Logger::Log("TNTMonsterSummaryInfoWidget: %x", widget);

		TNTMaskingGaugeWidget* hpGauge = widget->getHpGauge();
		TNTMaskingGaugeWidget* mpGauge = widget->getMpGauge();

		auto spy = Spy::Create(hpGauge, mpGauge);
		if (!spy.has_value())
			return false;

		targetSpy = spy.value();
	}
	
	if (config.SpyGroup.Activate)
	{
		std::vector<TLBSWidget*> widgets = gameRootWidget->findClassesWithExpectedSize(TNTPartySummaryInfoWidget::NAME, 4);
		if (widgets.size() == 0)
			return false;

		for (auto i = 0; i < widgets.size(); i++)
		{
			Logger::Log("TNTPartySummaryInfoWidget: %x", widgets[i]);

			std::vector<TLBSWidget*> gauges = widgets[i]->findClassesWithExpectedSize(TNTMaskingGaugeWidget::NAME, 2);
			if (gauges.size() == 0)
				return false;

			TNTMaskingGaugeWidget* hpGauge = reinterpret_cast<TNTMaskingGaugeWidget*>(gauges[0]);
			TNTMaskingGaugeWidget* mpGauge = reinterpret_cast<TNTMaskingGaugeWidget*>(gauges[1]);

			auto spy = Spy::Create(hpGauge, mpGauge);
			if (!spy.has_value())
				return false;

			groupSpies.insert({ static_cast<int8_t>(groupSpies.size()), spy.value() });
		}
	}

	Logger::Success("Successfully initialized");
	return true;
}

std::optional<SpyHpMpManager::Spy> SpyHpMpManager::Spy::Create(TNTMaskingGaugeWidget* hpGauge, TNTMaskingGaugeWidget* mpGauge)
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

TEWLabel* SpyHpMpManager::Spy::createGaugeElements(TNTMaskingGaugeWidget* gauge, WString* str)
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

void SpyHpMpManager::On_PR_st(const PR_st& Packet)
{
	if (!config.SpyTarget.Activate || config.SpyTarget.SpyType != SpyType::APPROXIMATION)
		return;
	if (!targetSpy.init)
		return;
	if (!Packet.IsValid())
	{
		Logger::Error("Packet not valid:\n%s", Packet.GetPacket().c_str());
		return;
	}

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentHp()) / (double)Packet.GetHpPercentage() * 100)));
	targetSpy.hpString.set(hpStr.c_str());
	targetSpy.hpLabel->setText(targetSpy.hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentMp()) / (double)Packet.GetMpPercentage() * 100)));
	targetSpy.mpString.set(mpStr.c_str());
	targetSpy.mpLabel->setText(targetSpy.mpString.get());
}

void SpyHpMpManager::On_PR_aa_st(const PR_aa_st& Packet)
{
	if (!config.SpyTarget.Activate || config.SpyTarget.SpyType != SpyType::REAL)
		return;
	if (!targetSpy.init)
		return;
	if (!Packet.IsValid())
	{
		Logger::Error("Packet not valid:\n%s", Packet.GetPacket().c_str());
		return;
	}

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring(Packet.GetMaxHp());
	targetSpy.hpString.set(hpStr.c_str());
	targetSpy.hpLabel->setText(targetSpy.hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring(Packet.GetMaxMp());
	targetSpy.mpString.set(mpStr.c_str());
	targetSpy.mpLabel->setText(targetSpy.mpString.get());
}

void SpyHpMpManager::On_PR_pst(const PR_pst& Packet)
{
	if (!config.SpyGroup.Activate || config.SpyGroup.SpyType != SpyType::APPROXIMATION)
		return;
	if (!Packet.IsValid())
	{
		Logger::Error("Packet not valid:\n%s", Packet.GetPacket().c_str());
		return;
	}

	int8_t id = Packet.GetGroupOrder();
	if (groupSpies.count(id) == 0 || !groupSpies[id].init)
		return;

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentHp() / (double)Packet.GetHpPercentage() * 100))));
	groupSpies[id].hpString.set(hpStr.c_str());
	groupSpies[id].hpLabel->setText(groupSpies[id].hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentMp() / (double)Packet.GetMpPercentage() * 100))));
	groupSpies[id].mpString.set(mpStr.c_str());
	groupSpies[id].mpLabel->setText(groupSpies[id].mpString.get());
}

void SpyHpMpManager::On_PR_aa_pst(const PR_aa_pst& Packet)
{
	if (!config.SpyGroup.Activate || config.SpyGroup.SpyType != SpyType::APPROXIMATION)
		return;
	if (!Packet.IsValid())
	{
		Logger::Error("Packet not valid:\n%s", Packet.GetPacket().c_str());
		return;
	}

	int8_t id = Packet.GetGroupOrder();
	if (groupSpies.count(id) == 0 || !groupSpies[id].init)
		return;

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring(Packet.GetMaxHp());
	groupSpies[id].hpString.set(hpStr.c_str());
	groupSpies[id].hpLabel->setText(groupSpies[id].hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring(Packet.GetMaxMp());
	groupSpies[id].mpString.set(mpStr.c_str());
	groupSpies[id].mpLabel->setText(groupSpies[id].mpString.get());
}
