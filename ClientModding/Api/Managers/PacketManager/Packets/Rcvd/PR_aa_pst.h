#pragma once
#include "../PacketRcvd.h"
#include "../../../Enums/EntityType.h"

class PR_aa_pst : public PacketRcvd
{
public:
    [[nodiscard]] explicit PR_aa_pst(const std::string& Packet)
        : PacketRcvd(Packet)
    {
        Logger::Log("%s", Packet.c_str());
        isValid = check();
    }

    [[nodiscard]] int8_t GetGroupOrder() const noexcept { return groupOrder; }
    [[nodiscard]] int32_t GetCurrentHp() const noexcept { return currentHp; }
    [[nodiscard]] int32_t GetCurrentMp() const noexcept { return currentMp; }
    [[nodiscard]] int32_t GetMaxHp() const noexcept { return maxHp; }
    [[nodiscard]] int32_t GetMaxMp() const noexcept { return maxMp; }

private:
    [[nodiscard]] bool check()
    {
        if (!isValid) [[unlikely]]
            return false;

        if (packs.size() != 6) [[unlikely]]
            return false;

        if (!checkGroupOrder()) [[unlikely]]
            return false;

        if (!checkCurrentHp()) [[unlikely]]
            return false;

        if (!checkCurrentMp()) [[unlikely]]
            return false;

        if (!checkMaxHp()) [[unlikely]]
            return false;

        if (!checkMaxMp()) [[unlikely]]
            return false;

        return true;
    }

    [[nodiscard]] bool checkGroupOrder()
    {
        auto val = ToNumber<int8_t>(packs[2].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        groupOrder = val.value();
        return true;
    }

    [[nodiscard]] bool checkCurrentHp()
    {
        auto val = ToNumber<int32_t>(packs[3].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentHp = val.value();
        return true;
    }

    [[nodiscard]] bool checkCurrentMp()
    {
        auto val = ToNumber<int32_t>(packs[5].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        currentMp = val.value();
        return true;
    }

    [[nodiscard]] bool checkMaxHp()
    {
        auto val = ToNumber<int32_t>(packs[4].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        maxHp = val.value();
        return true;
    }

    [[nodiscard]] bool checkMaxMp()
    {
        auto val = ToNumber<int32_t>(packs[6].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        maxMp = val.value();
        return true;
    }

    int8_t groupOrder;
    int32_t currentHp;
    int32_t currentMp;
    int32_t maxHp;
    int32_t maxMp;
};
