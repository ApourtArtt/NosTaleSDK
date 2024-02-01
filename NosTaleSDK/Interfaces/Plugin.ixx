module;
#include <string>
export module Plugin;

namespace NosTaleSDK::Plugin
{
	// ReSharper disable once CppClassCanBeFinal
	export class Plugin
	{
	public:
		explicit Plugin(const std::string& Name)
			: name_(Name)
		{}
		virtual ~Plugin() {}

		[[nodiscard]] std::string GetName() { return name_; }

		virtual void AfterRuntimeInitialization() {}
		virtual void OnShowNostaleSplash() {}
		virtual void OnFreeNostaleSplash() {}
		virtual void BeforeRuntimeRun() {}
		virtual void OnRuntimeTick() {}
		virtual void OnGameTick() {}
		virtual void AfterRuntimeRun() {}

	private:
		std::string name_;
	};
}