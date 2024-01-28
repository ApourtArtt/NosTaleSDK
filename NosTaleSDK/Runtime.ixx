module;
#include <vector>
#include <set>
#include <memory>
export module Runtime;
import Plugin;
import AddressProvider;

namespace NosTaleSDK
{
	using namespace NosTaleSDK;

	export class Runtime
	{
	public:
		Runtime(Providers::AddressProvider& AddressProvider)
			: addressProvider(AddressProvider)
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
		Providers::AddressProvider& addressProvider;

		std::vector<std::shared_ptr<Plugin::Plugin>> plugins;
	};
}