#pragma once
#include <stdint.h>

enum class EntityType : int8_t
{
    CHARACTER = 1,
    NOSMATE_NPC = 2,
    MONSTER = 3,
    LOOT = 9
};