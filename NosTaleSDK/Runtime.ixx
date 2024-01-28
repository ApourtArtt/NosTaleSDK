module;
#include <vector>
#include <set>
#include <memory>
export module Runtime;
import Plugin;
import AddressProvider;
import VTableProvider;

namespace NosTaleSDK
{
	using namespace NosTaleSDK;

	export class Runtime
	{
	public:
		Runtime(
			Interfaces::AddressProvider& AddressProvider,
			Interfaces::VTableProvider& VTableProvider
		)
			: addressProvider(AddressProvider)
			, vTableProvider(VTableProvider)
		{

		}

		~Runtime()
		{

		}

		void RegisterPlugin(std::shared_ptr<Plugin::Plugin> Plugin)
		{
			plugins.push_back(std::reference_wrapper(Plugin));
		}

		void UnregisterPlugin(std::shared_ptr<Plugin::Plugin> Plugin)
		{
			plugins.erase(std::find(plugins.begin(), plugins.end(), Plugin));
		}

		void OnShowNostaleSplash()
		{

		}

		void OnFreeNostaleSplash()
		{

		}

		void Run()
		{

		}

	private:
		Interfaces::AddressProvider& addressProvider;
		Interfaces::VTableProvider& vTableProvider;

		std::vector<std::shared_ptr<Plugin::Plugin>> plugins;
	};
}