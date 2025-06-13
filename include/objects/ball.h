#pragma once
#include "math/Vec2.h"

struct Ball
{
    Vec2 position;
    Vec2 velocity;
    float radius;

    Ball(const Vec2 &pos, const Vec2 &vel, float r)
        : position(pos), velocity(vel), radius(r) {}
    void update(float dt);
};
