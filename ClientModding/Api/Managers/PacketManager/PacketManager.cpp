#include "PacketManager.h"
#include "../../Properties/Logical/String.h"
#include "../../../Utils/Split.h"
#include "../../../Utils/Logger.h"
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"

namespace
{
	std::function<void(char**)> onS, onR;

	void detourSendFunc()
	{
		char* packet; // Delphi str btw

		__asm
		{
			pushad;
			pushfd;
			mov packet, edx;
		}

		onS(&packet);

		__asm
		{
			popfd;
			popad;
		}
	}

	void detourRcvdFunc()
	{
		char* packet;

		__asm
		{
			pushad;
			pushfd;
			mov packet, edx;
		}

		onR(&packet);

		__asm
		{
			popfd;
			popad;
		}
	}
}

PacketManager::PacketManager(const PacketManagerConfig& Config) noexcept
	: Manager(Config, "PacketManager")
{}

PacketManager::~PacketManager() noexcept
{
	if (hookSend != nullptr)
	{
		delete hookSend;
		hookSend = nullptr;
	}
	if (hookRecv != nullptr)
	{
		delete hookRecv;
		hookRecv = nullptr;
	}
}

bool PacketManager::initialize() noexcept
{
	lpvSendAddy = PatternScan(
		"\x53\x56\x8B\xF2\x8B\xD8\xEB\x04",
		"xxxxxxxx"
	);
	if (lpvSendAddy == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("lpvSendAddy = %x", lpvSendAddy);

	lpvRecvAddy = PatternScan(
		"\x55\x8B\xEC\x83\xC4\xF0\x53\x56\x57\x33\xC9\x89\x4D\xF4\x89\x4D\xF0\x89\x55\xFC\x8B\xD8\x8B\x45\xFC",
		"xxxxx?xxxxxxx?xx?xx?xxxx?"
	);
	if (lpvRecvAddy == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("lpvRecvAddy = %x", lpvRecvAddy);

	lpvPacketThis = PatternScan(
		"\xA1\x00\x00\x00\x00\x8B\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x8B\x00\x33\xD2\x89\x10",
		"x????xxx????x????xxxxxx", 1
	);
	if (lpvPacketThis == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("lpvPacketThis = %x", lpvPacketThis);

	onS = [this](char** Packet) { onSent(Packet); };
	onR = [this](char** Packet) { onRcvd(Packet); };

	hookSend = new TrampolineHook(lpvSendAddy, detourSendFunc, 6);
	hookRecv = new TrampolineHook(lpvRecvAddy, detourRcvdFunc, 6);

	Logger::Success("Successfully initialized");
	return true;
}

bool PacketManager::unload() noexcept
{
	if (hookSend != nullptr)
	{
		delete hookSend;
		hookSend = nullptr;
	}
	if (hookRecv != nullptr)
	{
		delete hookRecv;
		hookRecv = nullptr;
	}
	return true;
}

void PacketManager::tick() noexcept
{}

void PacketManager::Subscribe(PacketType PacketType, const std::string& PacketHeader, const std::function<void(std::string&)>& Callback)
{
	auto _ = Logger::PushPopModuleName(name);

	rcvd.lock();

	if (PacketType == PacketType::SENT)
	{
		Logger::Log("Subscribing for [SEND] %s", PacketHeader.c_str());
		sentSubscriptions[PacketHeader].push_back(Callback);
	}
	else
	{
		Logger::Log("Subscribing for [RCVD] %s", PacketHeader.c_str());
		rcvdSubscriptions[PacketHeader].push_back(Callback);
	}

	rcvd.unlock();
}

void PacketManager::Unsubscribe(PacketType PacketType, const std::string& PacketHeader)
{
	auto _ = Logger::PushPopModuleName(name);

	rcvd.lock();

	if (PacketType == PacketType::SENT)
	{
		if (sentSubscriptions.find(PacketHeader) != sentSubscriptions.end())
		{
			Logger::Log("Unsubscribing for [SENT] %s", PacketHeader.c_str());
			sentSubscriptions.erase(PacketHeader);
		}
	}
	else
	{
		if (rcvdSubscriptions.find(PacketHeader) != rcvdSubscriptions.end())
		{
			Logger::Log("Unsubscribing for [RCVD] %s", PacketHeader.c_str());
			rcvdSubscriptions.erase(PacketHeader);
		}
	}

	rcvd.unlock();
}

void PacketManager::Send(const std::string& Packet)
{
	String str(Packet.data());
	void* callAddy = lpvSendAddy;
	char* packet = str.get();
	void* packetThis = lpvPacketThis;

	_asm
	{
		MOV EAX, packetThis;
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
	void* packetThis = lpvPacketThis;

	_asm
	{
		MOV EAX, packetThis;
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, DWORD PTR DS : [EAX]
		MOV EAX, [EAX + 0x34]
		MOV EDX, packet
		CALL callAddy;
	}
}

std::string PacketManager::getPacketHeader(const std::string& Packet)
{
	std::string packet = Packet;
	std::string header = packet.substr(0, packet.find(' ', 0));
	// The header could be "#something^like^that" and we only want "#something"
	if (header.find('#') > -1)
		header = packet.substr(0, packet.find('^', 0));
	return header;
}

void PacketManager::onSent(char** Packet)
{
	std::string packet(*Packet);

	std::string encryptedPacket = config.EncryptFn(packet);

	String str(encryptedPacket.c_str());
	
	//Logger::Log("%x %x %x", &Packet, Packet, *Packet);
	__asm {
		NOP
		NOP
		NOP
		NOP
		NOP
	}
	//memcpy((*Packet - 0x4), (str.get() - 0x4), str.size() + 0x4);
	//*Packet = str.get();
	//Logger::Log("EncryptedPacket2: %s", *Packet);

	std::string header = getPacketHeader(packet);

	sent.lock();

	if (sentSubscriptions.find(header) != sentSubscriptions.end())
	{
		for (auto& subscriber : sentSubscriptions[header])
			subscriber(packet);
	}

	sent.unlock();
}

void PacketManager::onRcvd(char** Packet)
{
	std::string packet(*Packet);
	std::string header = getPacketHeader(packet);

	sent.lock();

	if (rcvdSubscriptions.find(header) != rcvdSubscriptions.end())
	{
		for (auto& subscriber : rcvdSubscriptions[header])
			subscriber(packet);
	}

	sent.unlock();
}
