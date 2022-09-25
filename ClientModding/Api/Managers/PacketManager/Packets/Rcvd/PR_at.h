#pragma once
#include "../PacketRcvd.h"

class PR_at : public PacketRcvd
{
public:
    [[nodiscard]] explicit PR_at(const std::string& Packet)
        : PacketRcvd(Packet)
    {
        isValid = check();
    }

    [[nodiscard]] int32_t GetMapId() const noexcept { return mapId; }
    [[nodiscard]] int32_t GetCharacterId() const noexcept { return characterId; }

private:
    [[nodiscard]] bool check()
    {
        if (!isValid) [[unlikely]]
            return false;

        if (packs.size() != 10) [[unlikely]]
            return false;

        if (!checkMapId()) [[unlikely]]
            return false;

        if (!checkCharacterId()) [[unlikely]]
            return false;

        return true;
    }

    [[nodiscard]] bool checkCharacterId()
    {
        auto val = ToNumber<int32_t>(packs[1].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        characterId = val.value();
        return true;
    }

    [[nodiscard]] bool checkMapId()
    {
        auto val = ToNumber<int32_t>(packs[2].c_str());
        if (!val.has_value()) [[unlikely]]
            return false;

        mapId = val.value();
        return true;
    }

    int32_t characterId;
    int32_t mapId;
};
