import TLBSWidgetHandler;
import TObject;
import TBaseList;
import TStrings;

#include <iostream>

int main()
{
	NosTaleSDK::Entwell::Classes::TLBSWidgetHandler a;
	NosTaleSDK::Entwell::Classes::TObject o;
	o.vTable = 12345;
	uint32_t aa;
	std::cout << o.vTable;

	NosTaleSDK::Entwell::Classes::TStrings bb;
	bb.FUpdateCount = 17;
	std::cout << bb.FUpdateCount;
}