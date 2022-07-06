#pragma once
#include <string>

class PacketSent
{
public:
	PacketSent(const std::string& Header)
		: packet(Header)
	{}

	[[nodiscard]] const std::string& GetPacket() noexcept { return packet; }

protected:
	std::string packet;
};
