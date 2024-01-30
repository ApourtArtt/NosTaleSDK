module;
#include <stdint.h>
#include <iostream>
export module WrapperTLBSWidget;
import TLBSWidget;
import WrapperTObject;

namespace NosTaleSDK::Wrappers::Classes
{
	export class WrapperTLBSWidget : public WrapperTObject
	{
	public:
		WrapperTLBSWidget()
		{

		}

		WrapperTLBSWidget(NosTaleSDK::Entwell::Classes::TLBSWidget* TType)
			: tType(TType)
		{

		}

		void even() { std::cout << tType->unknown; }

	protected:
		NosTaleSDK::Entwell::Classes::TLBSWidget* tType{ new NosTaleSDK::Entwell::Classes::TLBSWidget() };
	};
}