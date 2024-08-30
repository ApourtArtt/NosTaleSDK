#include "BoundsRect.hpp"

namespace NosTaleSDK::Entwell::Structs
{
    BoundsRect::BoundsRect(int16_t TopLeftX, int16_t TopLeftY, int16_t BotRightX, int16_t BotRightY)
        : topLeftX(TopLeftX)
        , topLeftY(TopLeftY)
        , botRightX(BotRightX)
        , botRightY(BotRightY)
    {}

    void BoundsRect::SetTop(int16_t TopLeftX, int16_t TopLeftY)
    {
        topLeftX = TopLeftX;
        topLeftY = TopLeftY;
    }

    void BoundsRect::SetBot(int16_t BotRightX, int16_t BotRightY)
    {
        botRightX = BotRightX;
        botRightY = BotRightY;
    }

    void BoundsRect::SetWidth(int16_t Width)
    {
        botRightX = topLeftX + Width;
    }

    void BoundsRect::SetHeight(int16_t Height)
    {
        botRightY = topLeftY + Height;
    }

    int16_t BoundsRect::GetTopLeftX() const
    {
        return topLeftX;
    }

    int16_t BoundsRect::GetTopLeftY() const
    {
        return topLeftY;
    }

    int16_t BoundsRect::GetBotRightX() const
    {
        return botRightX;
    }

    int16_t BoundsRect::GetBotRightY() const
    {
        return botRightY;
    }

    int16_t BoundsRect::GetWidth() const
    {
        return botRightX - topLeftX;
    }

    int16_t BoundsRect::GetHeight() const
    {
        return botRightY - topLeftY;
    }
}
