module;
#include <stdint.h>
export module TNTClient;
import TObject;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTClient : public TObject
	{
		char unknown[40];											// 0x004
		struct TNosTaleGame* nostaleGame;							// 0x02C
		bool isConnectedToChannel;									// 0x030
		bool isLogged;												// 0x031
		char unknown2[2];											// 0x032
		struct TNosRevCmdList* revCmdList;							// 0x034
		struct TNosSndCmdList* sndCmdList;							// 0x038
		void* tNosDelayRunCmdList;									// 0x03C
		void* tgServerList;											// 0x040
		char unknown3[8];											// 0x044
		Properties::Logical::DelphiArray<char>* username;			// 0x04C
		Properties::Logical::DelphiArray<char>* connectionToken;	// 0x050
		char unknown4[12];											// 0x054
		char unknown5;												// 0x060
		char unknown6[7];											// 0x061
		Properties::Logical::DelphiArray<char>* packetToken;		// 0x068
		Properties::Logical::DelphiArray<char>* version;			// 0x06C
		char unknown7[8];											// 0x070
		Properties::Logical::DelphiArray<char>* unknown8;			// 0x078
		char unknown9[4];											// 0x07C
		Properties::Logical::DelphiArray<char>* unknown10;			// 0x080
		char unknown11[288];										// 0x084
	};
	static_assert(sizeof(TNTClient) == 0x1A4, "TNTClient size isn't 0x1A4.");
	static_assert(sizeof(TNTClient) <= 0x1A4, "TNTClient size is upper than 0x1A4.");
	static_assert(sizeof(TNTClient) >= 0x1A4, "TNTClient size is lower than 0x1A4.");
#pragma pack(pop)
}