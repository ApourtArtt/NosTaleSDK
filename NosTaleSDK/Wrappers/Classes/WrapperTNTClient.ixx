module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTNTClient;
import WrapperTObject;
import WrapperTNosRevCmdList;
import TNTClient;
import VTableProvider;
import AddressProvider;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	export class WrapperTNTClient : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTNTClient, WrapperTObject, TNTClient);
	public:
		static WrapperTNTClient& GetNtInstance(std::shared_ptr<Interfaces::AddressProvider> Provider, const bool Refresh = false)
		{
			static WrapperTNTClient* wrapper = nullptr;

			if (Refresh || wrapper == nullptr)
			{
				const uintptr_t ptr = Provider->GetOne("NosTaleSDK::Entwell::Classes::TNTClient::Singleton");
				const auto widgetHandler = ***reinterpret_cast<TNTClient****>(ptr);
				wrapper = new WrapperTNTClient(widgetHandler);
			}

			return *wrapper;
		}

		WrapperTNosRevCmdList GetNosRevCmdList() const
		{
			return WrapperTNosRevCmdList(obj_->revCmdList);
		}

	private:
		void initObject() const
		{

		}
	};
}