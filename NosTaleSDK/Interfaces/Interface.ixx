module;
export module Interface;

namespace NosTaleSDK::Interfaces
{
	export class Interface
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
		virtual bool load() = 0;
		virtual bool unload() = 0;

		bool isInit_{ false };
	};
}