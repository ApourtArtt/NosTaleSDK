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
			if (isInit)
				return false;
			bool isInit = load();
			return isInit;
		}

		[[nodiscard]] bool Unload()
		{
			if (!isInit)
				return true;

			return unload();
		}

	private:
		virtual bool load() = 0;
		virtual bool unload() = 0;

		bool isInit{ false };
	};
}