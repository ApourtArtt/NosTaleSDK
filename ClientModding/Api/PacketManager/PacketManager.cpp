#include "PacketManager.h"
#include "../Properties/Logical/String.h"
#include "../../Utils/Split.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../../MemoryHelper/Patch.h"

void detourSendFunc();
void detourRcvdFunc();
std::function<void(char*)> onS, onR;

PacketManager::PacketManager()
{
	lpvSendAddy = PatternScan(
		"\x53\x56\x8B\xF2\x8B\xD8\xEB\x04",
		"xxxxxxxx"
	);
	lpvRecvAddy = PatternScan(
		"\x55\x8B\xEC\x83\xC4\xF0\x53\x56\x57\x33\xC9\x89\x4D\xF4\x89\x4D\xF0\x89\x55\xFC\x8B\xD8\x8B\x45\xFC",
		"xxxxx?xxxxxxx?xx?xx?xxxx?"
	);
	lpvPacketThis = PatternScan(
		"\xA1\x00\x00\x00\x00\x8B\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x8B\x00\x33\xD2\x89\x10",
		"x????xxx????x????xxxxxx",
		1
	);

	onS = [&](char* Packet) { onSent(Packet); };
	onR = [&](char* Packet) { onRcvd(Packet); };

	hookSend = new TrampolineHook(lpvSendAddy, detourSendFunc, HOOK_SIZE);
	hookRecv = new TrampolineHook(lpvRecvAddy, detourRcvdFunc, HOOK_SIZE);
}

PacketManager::~PacketManager()
{
	delete hookSend;
	delete hookRecv;
}

bool PacketManager::Subscribe(PacketType PacketType, const std::string& PacketHeader, const std::function<void(std::string&)>& Callback)
{
	if (PacketType == PacketType::SENT)
	{
		sent.lock();
		if (sentSubscriptions.find(PacketHeader) == sentSubscriptions.end())
			sentSubscriptions.emplace(PacketHeader, Callback);
		sent.unlock();
	}
	else
	{
		rcvd.lock();
		if (rcvdSubscriptions.find(PacketHeader) == rcvdSubscriptions.end())
			rcvdSubscriptions.emplace(PacketHeader, Callback);
		rcvd.unlock();
	}

	return true;
}

bool PacketManager::Unsubscribe(PacketType PacketType, const std::string& PacketHeader)
{
	if (PacketType == PacketType::SENT)
	{
		sent.lock();
		if (sentSubscriptions.find(PacketHeader) != sentSubscriptions.end())
			sentSubscriptions.erase(PacketHeader);
		sent.unlock();
	}
	else
	{
		rcvd.lock();
		if (rcvdSubscriptions.find(PacketHeader) != rcvdSubscriptions.end())
			rcvdSubscriptions.erase(PacketHeader);
		rcvd.unlock();
	}

	return true;
}

void PacketManager::Send(const std::string& Packet)
{
	String str(Packet.data());
	void* callAddy = lpvSendAddy;
	char* packet = str.get();

	_asm
	{
		MOV EAX, DWORD PTR DS : [lpvPacketThis]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EDX, packet
		CALL callAddy;
	}
}

void PacketManager::Receive(const std::string& Packet)
{
	String str(Packet.data());
	char* packet = str.get();
	void* callAddy = lpvRecvAddy;

	_asm
	{
		MOV EAX, DWORD PTR DS : [lpvPacketThis]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, [EAX + 0x34]
		MOV EDX, packet
		CALL callAddy;
	}
}

void PacketManager::onSent(char* Packet)
{
	sent.lock();

	std::string packet = Packet;
	auto header = packet.substr(0, packet.find(' ', 0));


	auto&& subscriber = sentSubscriptions.find(header);
	if (subscriber != sentSubscriptions.end())
		subscriber->second(packet);

	sent.unlock();
}

void PacketManager::onRcvd(char* Packet)
{
	rcvd.lock();

	std::string packet = Packet;
	auto header = packet.substr(0, packet.find(' ', 0));


	auto&& subscriber = rcvdSubscriptions.find(header);
	if (subscriber != rcvdSubscriptions.end())
		subscriber->second(packet);

	rcvd.unlock();
}

void detourSendFunc()
{
	char* packet;

	__asm
	{
		mov packet, edx;
	}

	onS(packet);
}

void detourRcvdFunc()
{
	char* packet;

	__asm
	{
		mov packet, edx;
	}

	onR(packet);
}
