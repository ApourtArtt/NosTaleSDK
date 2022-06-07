#pragma once
#include "SpyHpMpConfig.h"
#include <string>
#include "../../../DelphiClasses/TNTMonsterSummaryInfoWidget.h"
#include "../../../DelphiClasses/TNTPartySummaryInfoWidget.h"
#include "../../../DelphiClasses/TEWLabel.h"
#include "../../../PacketManager/Packets/Rcvd/PR_st.h"
#include "../../../PacketManager/Packets/Rcvd/PR_aa_st.h"
#include "../../../PacketManager/Packets/Rcvd/PR_pst.h"
#include "../../../PacketManager/Packets/Rcvd/PR_aa_pst.h"

class SpyHpMpManager
{
public:
	explicit SpyHpMpManager(const SpyHpMpManagerConfig& Config);
	[[nodiscard]] bool Initialize();

	void On_PR_st(const PR_st& Packet);
	void On_PR_aa_st(const PR_aa_st& Packet);
	void On_PR_pst(const PR_pst&  Packet);
	void On_PR_aa_pst(const PR_aa_pst& Packet);

private:
	SpyHpMpManagerConfig config;

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

	Spy targetSpy;
	std::map<int8_t, Spy> groupSpies;
};
