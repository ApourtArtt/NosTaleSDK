#pragma once
#include "../PacketRcvd.h"
#include "../../../Enums/EntityType.h"

class PR_st : public PacketRcvd
{
public:
	[[nodiscard]] explicit PR_st(const std::string& Packet)
		: PacketRcvd(Packet)
	{
		isValid = check();
	}

    [[nodiscard]] EntityType GetEntityType() const noexcept { return entityType; }
    [[nodiscard]] int32_t GetEntityId() const noexcept { return entityId; }
    [[nodiscard]] int32_t GetLevel() const noexcept { return level; }
    [[nodiscard]] int32_t GetLevelHero() const noexcept { return levelHero; }
    [[nodiscard]] int8_t GetHpPercentage() const noexcept { return hpPercentage; }
    [[nodiscard]] int8_t GetMpPercentage() const noexcept { return mpPercentage; }
    [[nodiscard]] int32_t GetCurrentHp() const noexcept { return currentHp; }
    [[nodiscard]] int32_t GetCurrentMp() const noexcept { return currentMp; }
    [[nodiscard]] const std::vector<int16_t>& GetBuffsId() const noexcept { return buffsId;  }

private:
    [[nodiscard]] bool check()
    {
        if (!isValid) [[unlikely]]
            return false;

        if (packs.size() < 9) [[unlikely]]
            return false;

        if (!checkEntityType()) [[unlikely]]
            return false;

        if (!checkEntityId()) [[unlikely]]
            return false;

        if (!checkHpPercentage()) [[unlikely]]
            return false;

        if (!checkMpPercentage()) [[unlikely]]
            return false;

        if (!checkCurrentHp()) [[unlikely]]
            return false;

        if (!checkCurrentMp()) [[unlikely]]
            return false;

        if (!checkBuffsId()) [[unlikely]]
            return false;

        return true;
    }

    [[nodiscard]] bool checkEntityType()
    {
        auto val = ToNumber<int8_t>(packs[1].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        entityType = static_cast<EntityType>(val.value());
        return true;
    }

    [[nodiscard]] bool checkEntityId()
    {
        auto val = ToNumber<int32_t>(packs[2].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        entityId = val.value();
        return true;
    }

    [[nodiscard]] bool checkLevel()
    {
        auto val = ToNumber<int32_t>(packs[3].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        level = val.value();
        return true;
    }

    [[nodiscard]] bool checkLevelHero()
    {
        auto val = ToNumber<int32_t>(packs[4].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        levelHero = val.value();
        return true;
    }

    [[nodiscard]] bool checkHpPercentage()
    {
        auto val = ToNumber<int8_t>(packs[5].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        hpPercentage = val.value();
        return true;
    }

    [[nodiscard]] bool checkMpPercentage()
    {
        auto val = ToNumber<int8_t>(packs[6].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        mpPercentage = val.value();
        return true;
    }

    [[nodiscard]] bool checkCurrentHp()
    {
        auto val = ToNumber<int32_t>(packs[7].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentHp = val.value();
        return true;
    }

    [[nodiscard]] bool checkCurrentMp()
    {
        auto val = ToNumber<int32_t>(packs[8].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentMp = val.value();
        return true;
    }

    [[nodiscard]] bool checkBuffsId()
    {
        for (auto i = 9; i < packs.size(); i++)
        {
            auto val = ToNumber<int32_t>(packs[i].c_str());
            if (!val.has_value()) [[unlikely]]
                continue;

            buffsId.push_back(val.value());
        }
        return true;
    }

    EntityType entityType;
    int32_t entityId;
    int32_t level;
    int32_t levelHero;
    int8_t hpPercentage;
    int8_t mpPercentage;
    int32_t currentHp;
    int32_t currentMp;
    std::vector<int16_t> buffsId;
};
