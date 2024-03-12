module;
#include "MacroWrapperDef.h"
#include <memory>
#include <vector>
export module WrapperTNosRevCmdList;
import WrapperTObject;
import TNosRevCmdList;
import VTableProvider;
import WrapperTNosRevCmd;
import WrapperTList;
import TNosRevCmd;
import TList;

namespace NosTaleSDK::Wrappers::Classes
{
	using namespace NosTaleSDK::Entwell::Classes;
	export class WrapperTNosRevCmdList : public WrapperTObject
	{
		TENTWELL_WRAPPER_DEFINITION(WrapperTNosRevCmdList, WrapperTObject, TNosRevCmdList)
	public:
		std::vector<WrapperTNosRevCmd> GetPackets()
		{
			std::vector<WrapperTNosRevCmd> packets;

			WrapperTList<TNosRevCmd*> wrapperTList = WrapperTList<TNosRevCmd*>(*(obj_->list));

			for(auto i = 0; i < wrapperTList.size(); i++)
			{
				TNosRevCmd* packet = wrapperTList.getItem(i);
				packets.push_back(WrapperTNosRevCmd(packet));
			}

			return packets;
		}

	private:
		void initObject() const
		{

		}
	};
}