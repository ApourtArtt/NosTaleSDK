#pragma once
#include "../PacketRcvd.h"
#include "../../../../Enums/EntityType.h"

class PR_pst : public PacketRcvd
{
public:
    [[nodiscard]] explicit PR_pst(const std::string& Packet)
        : PacketRcvd(Packet)
    {
        isValid = check();
    }

    [[nodiscard]] EntityType GetEntityType() const noexcept { return entityType; }
    [[nodiscard]] int32_t GetEntityId() const noexcept { return entityId; }
    [[nodiscard]] int8_t GetGroupOrder() const noexcept { return groupOrder; }
    [[nodiscard]] int8_t GetHpPercentage() const noexcept { return hpPercentage; }
    [[nodiscard]] int8_t GetMpPercentage() const noexcept { return mpPercentage; }
    [[nodiscard]] int32_t GetCurrentHp() const noexcept { return currentHp; }
    [[nodiscard]] int32_t GetCurrentMp() const noexcept { return currentMp; }
    [[nodiscard]] int16_t GetRace() const noexcept { return race; }
    [[nodiscard]] int8_t GetGender() const noexcept { return gender; }
    [[nodiscard]] const std::vector<int16_t>& GetBuffsId() const noexcept { return buffsId; }

private:
    [[nodiscard]] bool check()
    {
        if (!isValid) [[unlikely]]
            return false;

        if (packs.size() < 11) [[unlikely]]
            return false;

        if (!checkEntityType()) [[unlikely]]
            return false;

        if (!checkEntityId()) [[unlikely]]
            return false;

        if (!checkGroupOrder()) [[unlikely]]
            return false;

        if (!checkHpPercentage()) [[unlikely]]
            return false;

        if (!checkMpPercentage()) [[unlikely]]
            return false;

        if (!checkCurrentHp()) [[unlikely]]
            return false;

        if (!checkCurrentMp()) [[unlikely]]
            return false;

        if (!checkRace()) [[unlikely]]
            return false;

        if (!checkGender()) [[unlikely]]
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

    [[nodiscard]] bool checkGroupOrder()
    {
        auto val = ToNumber<int8_t>(packs[3].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        groupOrder = val.value();
        return true;
    }

    [[nodiscard]] bool checkHpPercentage()
    {
        auto val = ToNumber<int8_t>(packs[4].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        hpPercentage = val.value();
        return true;
    }

    [[nodiscard]] bool checkMpPercentage()
    {
        auto val = ToNumber<int8_t>(packs[5].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        mpPercentage = val.value();
        return true;
    }
    
    [[nodiscard]] bool checkCurrentHp()
    {
        auto val = ToNumber<int32_t>(packs[6].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentHp = val.value();
        return true;
    }

    [[nodiscard]] bool checkCurrentMp()
    {
        auto val = ToNumber<int32_t>(packs[7].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentMp = val.value();
        return true;
    }

    [[nodiscard]] bool checkRace()
    {
        auto val = ToNumber<int16_t>(packs[8].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        race = val.value();
        return true;
    }

    [[nodiscard]] bool checkGender()
    {
        auto val = ToNumber<int8_t>(packs[9].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        gender = val.value();
        return true;
    }

    [[nodiscard]] bool checkBuffsId()
    {
        for (auto i = 10; i < packs.size(); i++)
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
    int8_t groupOrder;
    int8_t hpPercentage;
    int8_t mpPercentage;
    int32_t currentHp;
    int32_t currentMp;
    int16_t race; // ??
    int8_t gender;
    std::vector<int16_t> buffsId;
};
