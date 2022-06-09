#pragma once
#include "WeaponConfig.h"

WeaponGlow defaultNoGlow
{
	.SecondaryGlowColor = Bgra(0, 0, 0, 0),
	.SecondaryGlowSize = 0.,
	.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
	.PrimaryGlowColor = Bgra(0, 0, 0, 0),
	.PrimaryGlowSize = 0.,
	.PrimaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
};

upgradeToGlow defaultSubLegendaryWeaponGlows =
{
	{
		0, defaultNoGlow
	},
	{
		1, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		2, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 80),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		3, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		4, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		5, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		6, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		7, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		8, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		9, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		10, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.2,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
};

upgradeToGlow defaultAboveLegendaryWeaponGlows =
{
	{
		0, defaultNoGlow
	},
	{
		1, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		2, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 80),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		3, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		4, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		5, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		6, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		7, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		8, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.200,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		9, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.200,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		10, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 255),
			.SecondaryGlowSize = 0.7,
			.SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
};

glowsMap defaultWeaponGlows =
{
	{ 0, defaultSubLegendaryWeaponGlows },
	{ 1, defaultSubLegendaryWeaponGlows },
	{ 2, defaultSubLegendaryWeaponGlows },
	{ 3, defaultSubLegendaryWeaponGlows },
	{ 4, defaultSubLegendaryWeaponGlows },
	{ 5, defaultSubLegendaryWeaponGlows },
	{ 6, defaultSubLegendaryWeaponGlows },
	{ 7, defaultAboveLegendaryWeaponGlows },
	{ 8, defaultAboveLegendaryWeaponGlows },
};
