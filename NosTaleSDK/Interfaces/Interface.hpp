#pragma once

namespace NosTaleSDK::Interfaces
{
	class Interface
	{
	public:
		virtual ~Interface() {}
		[[nodiscard]] bool Load()
		{
			if (isInit_)
				return false;
			const bool isInit = load();
			return isInit;
		}

		[[nodiscard]] bool Unload()
		{
			if (!isInit_)
				return true;

			return unload();
		}

	private:
		[[nodiscard]] virtual bool load() = 0;
		[[nodiscard]] virtual bool unload() = 0;

		bool isInit_{ false };
	};
}