module;
#include <stdint.h>
#include <iostream>
export module WrapperTObject;
import TObject;

namespace NosTaleSDK::Wrappers::Classes
{
	export class WrapperTObject
	{
	public:
		WrapperTObject()
		{
			std::cout << "Ok";
			tType = new NosTaleSDK::Entwell::Classes::TObject();
			tType->vTable = 12345;
			std::cout << tType->vTable;
		}

		void disp() { std::cout << tType->vTable; }
	protected:
		NosTaleSDK::Entwell::Classes::TObject* tType;
	};
}