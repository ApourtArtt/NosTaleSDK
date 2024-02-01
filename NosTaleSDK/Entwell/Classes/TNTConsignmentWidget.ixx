module;
#include <stdint.h>
export module TNTConsignmentWidget;
import TEWCustomFormWidget;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTConsignmentWidget : public TEWCustomFormWidget
	{
		char unknown38[4];								// 0x0BC
		struct TEWControlWidgetMouseEvent* firstPage;	// 0x0C0
		TEWControlWidgetMouseEvent* secondPage;			// 0x0C4
		TEWControlWidgetMouseEvent* thirdPage;			// 0x0C8
		uint8_t unknown39;								// 0x0CC
		char unknown40[3];								// 0x0CD
		uint32_t unknown41;								// 0x0D0
		char unknown42[20];								// 0x0D4
		uint8_t unknown43;								// 0x0E8
		char unknown44[3];								// 0x0E9
		uint32_t unknown45;								// 0x0EC
		char unknown46[4];								// 0x0F0
		struct TEWLabel* unknown47;						// 0x0F4
		TEWLabel* unknown48;							// 0x0F8
		uint16_t unknown49;								// 0x0FC
		uint16_t unknown50;								// 0x0FE
		uint16_t unknown51;								// 0x100
		uint16_t unknown52;								// 0x102
		uint16_t unknown53;								// 0x104
		uint16_t unknown54;								// 0x106
		uint16_t unknown58;								// 0x108
		uint16_t unknown59;								// 0x10A
		uint16_t unknown60;								// 0x10C
		uint16_t unknown61;								// 0x10E
		char unknown62[408];							// 0x110
		struct TEWGraphicButtonWidget* unknown63;		// 0x2A8
		TEWGraphicButtonWidget* unknown64;				// 0x2AC
		char unknown65[92];								// 0x2B0
		TEWGraphicButtonWidget* unknown66;				// 0x30C
		char unknown67[20];								// 0x310
		TEWGraphicButtonWidget* unknown68;				// 0x324
		struct TEWEditWidget* unknown69;				// 0x328
		TEWCustomPanelWidget* unknown70;				// 0x32C
		char unknown71[8];								// 0x330
		TEWGraphicButtonWidget* unknown72;				// 0x338
		TEWLabel* unknown73;							// 0x33C
		struct TEWNumberEditWidget* unknown74;			// 0x340
		TEWCustomPanelWidget* unknown75;				// 0x344
		TEWGraphicButtonWidget* unknown76;				// 0x348
		uint8_t unknown77;								// 0x34C
		char unknown78[3];								// 0x34D
		uint32_t unknown79;								// 0x350
		uint32_t unknown80;								// 0x354
		uint8_t unknown81;								// 0x358
		uint8_t unknown82;								// 0x359
		char unknown83[2];								// 0x35A
		TEWLabel* unknown84;							// 0x35C
		uint32_t unknown85;								// 0x360
		uint8_t unknown86;								// 0x364
		char unknown87[3];								// 0x365
		TEWLabel* unknown88;							// 0x368
		char unknown89[80];								// 0x36C
		struct TEWNormalButtonWidget* unknown90;		// 0x3BC
		TEWNormalButtonWidget* unknown91;				// 0x3C0
		char unknown92[40];								// 0x36C
		struct TNTItemList* unknown93;					// 0x3EC
		char unknown94[40];								// 0x3F0
		TList<void*>* unknown95;						// 0x418
		TList<void*>* unknown96;						// 0x41C
		char unknown97[40];								// 0x420
		TEWLabel* unknown98;							// 0x448
		TEWLabel* unknown99;							// 0x44C
		TEWLabel* unknown100;							// 0x450
		TEWLabel* unknown101;							// 0x454
		TEWLabel* unknown102;							// 0x458
		struct TEWListView* unknown103;					// 0x45C
		TEWListView* unknown104;						// 0x460
		TEWListView* unknown105;						// 0x464
		TEWListView* unknown106;						// 0x468
		TEWListView* unknown107;						// 0x46C
		char unknown108[4];								// 0x470
		TEWGraphicButtonWidget* unknown109;				// 0x474
		TEWGraphicButtonWidget* unknown110;				// 0x478
		uint32_t unknown111;							// 0x47C
		TEWGraphicButtonWidget* unknown112;				// 0x480
		TEWGraphicButtonWidget* unknown113;				// 0x484
		uint32_t unknown114;							// 0x488
		char unknown115[8];								// 0x48C
		uint32_t unknown116;							// 0x494
		char unknown117[4];								// 0x498
		uint32_t unknown118;							// 0x49C
		struct TNTIconWidget* unknown119;				// 0x4A0
		char unknown120[4];								// 0x4A4
		uint32_t unknown121;							// 0x4A8
		char unknown122[60];							// 0x4AC
		TEWLabel* unknown123;							// 0x4E8
		TEWNumberEditWidget* unknown124;				// 0x4EC
		TEWLabel* unknown125;							// 0x4F0
		TEWLabel* unknown126;							// 0x4F4
		char unknown127[8];								// 0x4F8
		uint32_t unknown128;							// 0x500
		char unknown129[28];							// 0x504
		struct TEWLabels* unknown130;					// 0x520
		TEWLabels* unknown131;							// 0x524
		TEWLabels* unknown132;							// 0x528
		TNTIconWidget* unknown133;						// 0x52C
		uint32_t unknown134;							// 0x530
		char unknown135[60];							// 0x534
		TEWLabel* unknown136;							// 0x570
		TEWLabel* unknown137;							// 0x574
		uint32_t unknown138;							// 0x578
		uint8_t unknown139;								// 0x57C
		char unknown140[23];							// 0x57D
		TEWLabel* unknown141;							// 0x594
		uint16_t unknown142;							// 0x598
		char unknown143[2];								// 0x59A
		TEWGraphicButtonWidget* unknown144;				// 0x59C
		char unknown145[20];							// 0x5A0
		uint8_t unknown146;								// 0x5B4
		char unknown147[3];								// 0x5B5
		uint32_t unknown148;							// 0x5B8
		uint32_t unknown149;							// 0x5BC
		uint8_t unknown150;								// 0x5C0
		uint8_t unknown151;								// 0x5C1
		char unknown152[2];								// 0x5C2
		TEWLabel* unknown153;							// 0x5C4
		uint32_t unknown154;							// 0x5C8
		uint8_t unknown155;								// 0x5CC
		char unknown156[3];								// 0x5CD
		TEWLabel* unknown157;							// 0x5D0
		uint32_t unknown158;							// 0x5D4
		uint8_t unknown159;								// 0x5D8
		char unknown160[7];								// 0x5D9
		TEWLabel* unknown161;							// 0x5E0
		char unknown162[4];								// 0x5E4
		TEWGraphicButtonWidget* unknown163;				// 0x5E8
		TEWLabel* unknown164;							// 0x5EC
		char unknown165[168];							// 0x5F0
		TEWGraphicButtonWidget* unknown166;				// 0x698
		TEWGraphicButtonWidget* unknown167;				// 0x69C
		uint32_t unknown168;							// 0x6A0
		TEWGraphicButtonWidget* unknown169;				// 0x6A4
		TEWGraphicButtonWidget* unknown170;				// 0x6A8
		char unknown171[8];								// 0x6AC
		uint32_t unknown172;							// 0x6B4
		uint32_t unknown173;							// 0x6B8
		char unknown174[4];								// 0x6BC
		uint32_t unknown175;							// 0x6C0
		char unknown176[80];							// 0x6C4
		TEWLabel* unknown177;							// 0x714
		TEWLabel* unknown178;							// 0x718
		TEWLabel* unknown179;							// 0x71C
		TEWLabel* unknown180;							// 0x720
		TEWLabel* unknown181;							// 0x724
		TEWListView* unknown182;						// 0x728
		TEWListView* unknown183;						// 0x72C
		TEWListView* unknown184;						// 0x730
		TEWListView* unknown185;						// 0x734
		TEWListView* unknown186;						// 0x738
		char unknown187[40];							// 0x73C
		TNTItemList* unknown188;						// 0x764
		char unknown189[40];							// 0x768
		TList<void*>* unknown190;						// 0x790
	};
	static_assert(sizeof(TNTConsignmentWidget) == 0x794, "TEWControlWidgetEvent size isn't 0x794.");
	static_assert(sizeof(TNTConsignmentWidget) <= 0x794, "TEWControlWidgetEvent size is upper than 0x794.");
	static_assert(sizeof(TNTConsignmentWidget) >= 0x794, "TEWControlWidgetEvent size is lower than 0x794.");
#pragma pack(pop)
}