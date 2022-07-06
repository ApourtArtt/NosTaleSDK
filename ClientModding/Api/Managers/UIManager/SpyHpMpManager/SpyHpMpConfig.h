#pragma once

enum class SpyType
{
	APPROXIMATION,
	REAL,
};

struct SpyHpMpConfig
{
	bool Activate{ false };
	SpyType SpyType{ SpyType::APPROXIMATION };
};

struct SpyHpMpManagerConfig
{
	SpyHpMpConfig SpyGroup;
};
