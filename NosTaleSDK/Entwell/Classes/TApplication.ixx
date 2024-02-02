module;
#include <stdint.h>
#include <Windows.h>
export module TApplication;
import TComponent;
import String;
import TList;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	// https://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Forms.TApplication_Properties
	export struct TApplication : public TComponent
	{
		HWND* handle;											// 0x030
		uint32_t bidirectionalMode;								// 0x034
		Properties::Logical::String* bidirectionalKeyboard;		// 0x038
		Properties::Logical::String* nonBidirectionalKeyboard;	// 0x03C
		void* comObject;										// 0x040
		struct TNosTaleMainF* mainForm;							// 0x044
		struct TControl* mouseControl;							// 0x048
		void* helpSystem;										// 0x04C
		Properties::Logical::String* helpFile;					// 0x050
		Properties::Logical::String* hint;						// 0x054
		bool isHintActive;										// 0x058
		bool isUpdateFormatSettings;							// 0x059
		bool isUpdateMetricsSettings;							// 0x05A
		bool isMainFormShow;									// 0x05B
		uint32_t hintColor;										// 0x05C
		TControl* hintControl;									// 0x060
		void* hintCursorRect;									// 0x064
		char padding[12];										// 0x068
		int16_t hintHidePause;									// 0x074
		int16_t hintPause;										// 0x078
		char padding99[4];										// 0x076
		bool isHintShortCut;									// 0x07C
		char padding2[3];										// 0x07D
		int16_t hintShortPause;									// 0x080
		char padding3[2];										// 0x082
		void* hintWindow;										// 0x084
		bool isHintShown;										// 0x088
		uint8_t timeMode;										// 0x089
		uint16_t timeHandle;									// 0x08A
		Properties::Logical::String* title;						// 0x08C
		TList<void*>* topMostList;								// 0x090
		int16_t topMostLevel;									// 0x094
		char padding4[2];										// 0x096
		void* icon;												// 0x098
		bool isTerminated;										// 0x09C
		bool isActive;											// 0x09D
		bool isAllowTesting;									// 0x09E
		char padding6;											// 0x09F
		HWND* testHandle;										// 0x0A0
		bool isHandleCreated;									// 0x0A4
		bool isRunning;											// 0x0A5
		char padding7[2];										// 0x0A6
		TList<void*>* windowHooksList;							// 0x0A8
		TList<void*>* windowsList;								// 0x0AC
		HWND* dialogHandle;										// 0x0B0
		bool isAutoDragDocking;									// 0x0B4
		char padding8[11];										// 0x0B5
		Properties::Logical::Callback callback;					// 0x0C0 arg = TMultiCaster
		Properties::Logical::Callback callback2;				// 0x0C8 arg = TMultiCaster
		Properties::Logical::Callback callback3;				// 0x0D0 arg = TMultiCaster
		Properties::Logical::Callback onActionExecute;			// 0x0D8 arg = TMultiCaster
		Properties::Logical::Callback onActionUpdate;			// 0x0E0 arg = TMultiCaster
		Properties::Logical::Callback onException;				// 0x0E8 arg = TMultiCaster
		Properties::Logical::Callback onGetActiveFormHandle;	// 0x0F0 arg = TMultiCaster
		Properties::Logical::Callback onGetMainFormHandle;		// 0x0F8 arg = TMultiCaster
		Properties::Logical::Callback onMessage;				// 0x100
		Properties::Logical::Callback onModalBegin;				// 0x108 arg = TLBSWidgetHandler
		Properties::Logical::Callback onModalEnd;				// 0x110 arg = TLBSWidgetHandler
		Properties::Logical::Callback onHelp;					// 0x118 arg = TMultiCaster
		Properties::Logical::Callback onHint;					// 0x120 arg = TMultiCaster
		Properties::Logical::Callback onIdle;					// 0x128 arg = TMultiCaster
		Properties::Logical::Callback onDeactivate;				// 0x130 arg = TMultiCaster
		Properties::Logical::Callback onActivate;				// 0x138 arg = TMultiCaster
	};
	static_assert(sizeof(TApplication) == 0x140, "TApplication size isn't 0x140.");
	static_assert(sizeof(TApplication) <= 0x140, "TApplication size is upper than 0x140.");
	static_assert(sizeof(TApplication) >= 0x140, "TApplication size is lower than 0x140.");
#pragma pack(pop)
}