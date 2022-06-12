#pragma once
#include "StuffRarityConfig.h"

rarityToTextStyle defaultRarityTextStyle =
{
	{ RarityType::DAMAGED,		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(133, 144, 255, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::LOW_LEVEL,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(204, 168, 255, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::_,			TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(0, 0, 0, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::USEFUL,		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(252, 189, 192, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::GOOD,			TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(133, 255, 114, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::HIGH_QUALITY,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(255, 205, 145, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::EXCELLENT,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(2, 249, 14, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::ANCIENT,		TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(179, 226, 248, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::MYSTERIOUS,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(2, 221, 254, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::LEGENDARY,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(4, 243, 178, 255), Bgra(), TextAlignment::CenteredCentered) },
	{ RarityType::PHENOMENAL,	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(0, 94, 255, 255), Bgra(), TextAlignment::CenteredCentered) },
};
