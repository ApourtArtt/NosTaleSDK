#pragma once

struct PacketManagerConfig
{
	std::function<std::string(std::string)> EncryptFn = [](std::string packet) { return packet; };
	std::function<std::string(std::string)> DecryptFn = [](std::string packet) { return packet; };
};
