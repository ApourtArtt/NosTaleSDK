#pragma once
#include <string>
#include <map>
#include <functional>
#include <mutex>
#include "../../../MemoryHelper/TrampolineHook.h"
#include "PacketConfig.h"
#include "../Manager.h"

enum class PacketType { SENT, RCVD };

class PacketManager : public Manager<PacketManagerConfig>
{
public:
	[[nodiscard]] explicit PacketManager(const PacketManagerConfig& Config) noexcept;
	~PacketManager() noexcept;

	void Subscribe(PacketType PacketType, const std::string& PacketHeader, const std::function<void(std::string&)>& Callback);
	void Unsubscribe(PacketType PacketType, const std::string& PacketHeader);

	void Send(const std::string& Packet);
	void Receive(const std::string& Packet);

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	std::string getPacketHeader(const std::string& Packet);

	void onSent(char** Packet);
	void onRcvd(char** Packet);

	std::map<std::string, std::vector<std::function<void(std::string&)>>> sentSubscriptions;
	std::map<std::string, std::vector<std::function<void(std::string&)>>> rcvdSubscriptions;

	std::mutex sent;
	std::mutex rcvd;

	TrampolineHook* hookSend{ nullptr };
	TrampolineHook* hookRecv{ nullptr };

	void* lpvSendAddy{ nullptr };
	void* lpvRecvAddy{ nullptr };
	void* lpvPacketThis{ nullptr };
};
