#pragma once
#include "../PacketRcvd.h"
#include <map>

class StuffData
{
public:
    StuffData() {}
    StuffData(const std::vector<std::string>& Subpacket)
    {
        vnum = ToNumberUnsafe<int32_t>(Subpacket[1].c_str());
    }

    [[nodiscard]] const int32_t GetVnum() const noexcept { return vnum; }

private:
    int32_t vnum{ -1 };
};

class PR_equip : public PacketRcvd
{
public:
    [[nodiscard]] explicit PR_equip(const std::string& Packet)
        : PacketRcvd(Packet)
    {
        isValid = check();
    }

    [[nodiscard]] int8_t GetWeaponRarity() const noexcept { return weaponRarity; }
    [[nodiscard]] int8_t GetArmorRarity() const noexcept { return armorRarity; }
    [[nodiscard]] int16_t GetWeaponUpgrade() const noexcept { return weaponUpgrade; }
    [[nodiscard]] int16_t GetArmorUpgrade() const noexcept { return armorUpgrade; }
    [[nodiscard]] const std::map<int8_t, StuffData>& GetStuff() const noexcept { return stuffs; };

private:
    [[nodiscard]] bool check()
    {
        if (!isValid) [[unlikely]]
            return false;

        if (packs.size() < 3) [[unlikely]]
            return false;

        if (!checkWeaponData()) [[unlikely]]
            return false;

        if (!checkArmorData()) [[unlikely]]
            return false;

        if (!checkStuffData()) [[unlikely]]
            return false;

        return true;
    }

    [[nodiscard]] bool checkWeaponData()
    {
        auto val = ToNumber<int32_t>(packs[1].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;
        if (val < 0)
            return false;
        weaponRarity = val.value() % 10;
        weaponUpgrade = static_cast<int16_t>(val.value() / 10);
        return true;
    }

    [[nodiscard]] bool checkArmorData()
    {
        auto val = ToNumber<int32_t>(packs[2].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;
        if (val < 0)
            return false;
        armorRarity = val.value() % 10;
        armorUpgrade = static_cast<int16_t>(val.value() / 10);
        return true;
    }

    [[nodiscard]] bool checkStuffData()
    {
        for (auto i = 3; i < packs.size(); i++)
        {
            std::vector<std::string> stuffData = Split(packs[i], ".");
            if (stuffData.size() != 6)
                return false;

            stuffs.emplace(ToNumberUnsafe<int8_t>(stuffData[0].c_str()), StuffData(stuffData));
        }
        return true;
    }

    int8_t weaponRarity;
    int8_t armorRarity;
    int16_t weaponUpgrade;
    int16_t armorUpgrade;
    std::map<int8_t, StuffData> stuffs;
};
