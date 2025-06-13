#pragma once
#include "Ball.h"
#include <memory>

class BallFactory
{
public:
    static std::unique_ptr<Ball> createBall(const Vec2 &pos, const Vec2 &vel, float radius)
    {
        return std::make_unique<Ball>(pos, vel, radius);
    }
};
