#pragma once
#include <string>
#include <map>
#include <functional>
#include <mutex>
#include "../../MemoryHelper/TrampolineHook.h"

/**
 * @brief Represents type of packet.
 */
enum class PacketType { SENT, RCVD };

/**
 * @brief Class that holds all packet related stuff (Hooking and Custom packets).
 */
class PacketManager
{
public:
	PacketManager();
	~PacketManager();

	bool Subscribe(PacketType PacketType, const std::string& PacketHeader, const std::function<void(std::string&)>& Callback);
	bool Unsubscribe(PacketType PacketType, const std::string& PacketHeader);

	void Send(const std::string& Packet);
	void Receive(const std::string& Packet);

	void onSent(char* Packet);
	void onRcvd(char* Packet);

private:
	static constexpr int HOOK_SIZE = 6;

	std::map<std::string, std::function<void(std::string&)>> sentSubscriptions;
	std::map<std::string, std::function<void(std::string&)>> rcvdSubscriptions;

	std::mutex sent;
	std::mutex rcvd;

	TrampolineHook* hookSend;
	TrampolineHook* hookRecv;

	void* lpvSendAddy = nullptr;
	void* lpvRecvAddy = nullptr;
	void*lpvPacketThis = nullptr;
};
