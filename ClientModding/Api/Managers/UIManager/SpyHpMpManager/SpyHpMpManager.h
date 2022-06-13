#pragma once
#include "../../Manager.h"
#include "SpyHpMpConfig.h"
#include "Spy.h"
#include "../../../Managers/PacketManager/Packets/Rcvd/PR_st.h"
#include "../../../Managers/PacketManager/Packets/Rcvd/PR_aa_st.h"
#include "../../../Managers/PacketManager/Packets/Rcvd/PR_pst.h"
#include "../../../Managers/PacketManager/Packets/Rcvd/PR_aa_pst.h"

class SpyHpMpManager : public Manager<SpyHpMpManagerConfig>
{
public:
	[[nodiscard]] explicit SpyHpMpManager(const SpyHpMpManagerConfig& Config) noexcept;

	void On_PR_st(const PR_st& Packet) noexcept;
	void On_PR_aa_st(const PR_aa_st& Packet) noexcept;
	void On_PR_pst(const PR_pst&  Packet) noexcept;
	void On_PR_aa_pst(const PR_aa_pst& Packet) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	Spy targetSpy;
	std::vector<Spy> groupSpies;
};
