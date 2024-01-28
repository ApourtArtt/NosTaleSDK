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

	private:
		std::string name;
	};
}