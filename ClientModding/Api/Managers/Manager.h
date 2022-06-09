#pragma once
#include <string>
#include "../../Utils/Logger.h"

template<typename Config>
class Manager
{
public:
	[[nodiscard]] explicit Manager(const Config& Config, const std::string& Name) noexcept
		: config(Config)
		, name(Name)
	{}

	virtual ~Manager() {}

	[[nodiscard]] bool Initialize() noexcept
	{
		auto _ = Logger::PushPopModuleName(name);
		return initialize();
	}

	[[nodiscard]] bool Unload() noexcept
	{
		auto _ = Logger::PushPopModuleName(name);
		return unload();
	}

	void Tick() noexcept
	{
		tick();
	}

protected:
	[[nodiscard]] virtual bool initialize() noexcept = 0;
	[[nodiscard]] virtual bool unload() noexcept = 0;
	void virtual tick() noexcept = 0;

	Config config;
	std::string name;
};
