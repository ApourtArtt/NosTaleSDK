#pragma once
#include "../../../../Utils/Split.h"
#include "../../../../Utils/ToNumber.h"

class PacketRcvd
{
public:
	PacketRcvd() noexcept {}
	[[nodiscard]] explicit PacketRcvd(const std::string& Packet) noexcept
		: packs(Split(Packet, " "))
		, packet(Packet)
		, isValid(basicCheck())
	{}
	virtual ~PacketRcvd() noexcept {}

	[[nodiscard]] bool IsValid() const noexcept { return isValid; }
	[[nodiscard]] const std::string& GetPacket() const noexcept { return packet; }

protected:
	[[nodiscard]] bool basicCheck() noexcept
	{
		return true;
	}

	std::vector<std::string> packs;
	std::string packet;
	bool isValid{ false };
};