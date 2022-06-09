#include "SpyHpMpManager.h"
#include "../../../../Utils/Logger.h"
#include "../../../../Utils/Split.h"
#include "../../../DelphiClasses/TLBSWidgetHandler.h"
#include "../../../DelphiClasses/TNTMaskingGaugeWidget.h"
#include "../../../DelphiClasses/TNTMonsterSummaryInfoWidget.h"
#include "../../../DelphiClasses/TNTPartySummaryInfoWidget.h"

SpyHpMpManager::SpyHpMpManager(const SpyHpMpManagerConfig& Config) noexcept
	: Manager(Config, "SpyHpMpManager")
{}

bool SpyHpMpManager::initialize() noexcept
{

	TLBSWidgetHandler* ntWidgetHandler = TLBSWidgetHandler::getNtInstance();
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
	else
		Logger::Log("SpyTarget not activated");

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
	else
		Logger::Log("SpyGroup not activated");

	Logger::Success("Successfully initialized");
	return true;
}

bool SpyHpMpManager::unload() noexcept
{
	// todo
	return false;
}

void SpyHpMpManager::tick() noexcept
{}

void SpyHpMpManager::On_PR_st(const PR_st& Packet) noexcept
{
	if (!config.SpyTarget.Activate || config.SpyTarget.SpyType != SpyType::APPROXIMATION)
		return;
	if (!targetSpy.init)
		return;

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentHp()) / (double)Packet.GetHpPercentage() * 100)));
	targetSpy.hpString.set(hpStr.c_str());
	targetSpy.hpLabel->setText(targetSpy.hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring((std::max)(0, (int)roundf(((double)Packet.GetCurrentMp()) / (double)Packet.GetMpPercentage() * 100)));
	targetSpy.mpString.set(mpStr.c_str());
	targetSpy.mpLabel->setText(targetSpy.mpString.get());
}

void SpyHpMpManager::On_PR_aa_st(const PR_aa_st& Packet) noexcept
{
	if (!config.SpyTarget.Activate || config.SpyTarget.SpyType != SpyType::REAL)
		return;
	if (!targetSpy.init)
		return;

	std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring(Packet.GetMaxHp());
	targetSpy.hpString.set(hpStr.c_str());
	targetSpy.hpLabel->setText(targetSpy.hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring(Packet.GetMaxMp());
	targetSpy.mpString.set(mpStr.c_str());
	targetSpy.mpLabel->setText(targetSpy.mpString.get());
}

void SpyHpMpManager::On_PR_pst(const PR_pst& Packet) noexcept
{
	if (!config.SpyGroup.Activate || config.SpyGroup.SpyType != SpyType::APPROXIMATION)
		return;

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

void SpyHpMpManager::On_PR_aa_pst(const PR_aa_pst& Packet) noexcept
{
	if (!config.SpyGroup.Activate || config.SpyGroup.SpyType != SpyType::REAL)
		return;

	int8_t id = Packet.GetGroupOrder();
	if (groupSpies.count(id) == 0 || !groupSpies[id].init)
		return;

	//std::wstring hpStr = std::to_wstring(Packet.GetCurrentHp()) + L"/" + std::to_wstring(Packet.GetMaxHp());
	std::wstring hpStr = L"hola";
	groupSpies[id].hpString.set(hpStr.c_str());
	groupSpies[id].hpLabel->setText(groupSpies[id].hpString.get());

	std::wstring mpStr = std::to_wstring(Packet.GetCurrentMp()) + L"/" + std::to_wstring(Packet.GetMaxMp());
	groupSpies[id].mpString.set(mpStr.c_str());
	groupSpies[id].mpLabel->setText(groupSpies[id].mpString.get());
}
