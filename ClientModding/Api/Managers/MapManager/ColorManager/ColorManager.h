#pragma once
#include "../../Manager.h"
#include "ColorConfig.h"

class ColorManager : public Manager<ColorManagerConfig>
{
public:
	[[nodiscard]] explicit ColorManager(const ColorManagerConfig& Config) noexcept;

	void SetFirstFogIntensity(float Value) noexcept;
	void SetSecondFogIntensity(float Value) noexcept;
	void SetFogBlue(uint8_t Blue) noexcept;
	void SetFogGreen(uint8_t Green) noexcept;
	void SetFogRed(uint8_t Red) noexcept;

	void SetObjectRed(float Red) noexcept;
	void SetObjectGreen(float Green) noexcept;
	void SetObjectBlue(float Blue) noexcept;
	void SetObjectRedDelta(float Red) noexcept;
	void SetObjectGreenDelta(float Green) noexcept;
	void SetObjectBlueDelta(float Blue) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	[[nodiscard]] bool initializeFog() noexcept;
	[[nodiscard]] bool initializeObject() noexcept;

	uintptr_t fogAddress;
	uintptr_t objectAddress;
};
