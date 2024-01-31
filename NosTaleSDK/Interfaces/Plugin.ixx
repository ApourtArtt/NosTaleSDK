module;
#include <string>
export module Plugin;

namespace NosTaleSDK::Plugin
{
	export class Plugin
	{
	public:
		Plugin(const std::string& Name)
			: name(Name)
		{}
		virtual ~Plugin() {}

		[[nodiscard]] std::string GetName() { return name; }

		virtual void AfterRuntimeInitialization() {}
		virtual void OnShowNostaleSplash() {}
		virtual void OnFreeNostaleSplash() {}
		virtual void BeforeRuntimeRun() {}
		virtual void OnRuntimeTick() {}
		virtual void OnGameTick() {}
		virtual void AfterRuntimeRun() {}

	private:
		std::string name;
	};
}