//import TLBSWidgetHandler;
//import TObject;
//import TBaseList;
//import TStrings;

import WrapperTLBSWidget;
import PatternAddressProvider;

#include <iostream>

int main()
{
	//NosTaleSDK::Entwell::Classes::TLBSWidgetHandler a;
	//NosTaleSDK::Entwell::Classes::TObject o;
	//o.vTable = 12345;
	//uint32_t aa;
	//std::cout << o.vTable;

	//NosTaleSDK::Entwell::Classes::TStrings bb;
	//bb.FUpdateCount = 17;
	//std::cout << bb.FUpdateCount;

	//NosTaleSDK::Wrappers::Classes::WrapperTLBSWidget rezr;
	//rezr.disp();
	//rezr.even();
	//std::cout << "ok";

	PatternAddressProvider a;
	a.RegisterPattern("TestMain", PatternAddressProvider::PatternDef{
		.pattern = "\x90",
		.mask = "x",
		.offset = 0,
		.startFrom = 0,
	});
	std::cout << a.GetOne("TestMain");
}