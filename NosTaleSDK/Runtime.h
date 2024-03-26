#pragma once

namespace NosTaleSDK
{
	class Runtime
	{
	public:
		Runtime();
		~Runtime();

		void OnShowNostaleSplash();
		void OnFreeNostaleSplash();
		[[nodiscard]] bool Initialize();
		void Run();

	private:
	};
}
