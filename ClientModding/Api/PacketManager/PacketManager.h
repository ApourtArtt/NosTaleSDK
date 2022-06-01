#pragma once
#include <string>
#include <map>
#include <functional>
#include <mutex>
#include "../../MemoryHelper/TrampolineHook.h"

// Represents type of packet
enum class PacketType { SENT, RCVD };

// @brief Class that holds all packet related stuff (Hooking and Custom packets)
class PacketManager
{
public:
	~PacketManager();

	bool Initialize();

	void Subscribe(PacketType PacketType, const std::string& PacketHeader, const std::function<void(std::string&)>& Callback);
	void Unsubscribe(PacketType PacketType, const std::string& PacketHeader);

	void Send(const std::string& Packet);
	void Receive(const std::string& Packet);

private:
	std::string getPacketHeader(const std::string& Packet);

	void onSent(char* Packet);
	void onRcvd(char* Packet);

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
