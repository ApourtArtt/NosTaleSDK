//import TLBSWidgetHandler;
//import TObject;
//import TBaseList;
//import TStrings;

import WrapperTLBSWidget;
import AddressProvider;

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

	NosTaleSDK::Wrappers::Classes::WrapperTLBSWidget rezr;
	rezr.disp();
	rezr.even();
	std::cout << "ok";

	NosTaleSDK::Providers::DefaultAddressProvider a("xxx?x?xx", 123);
	std::cout << a.Get();
}