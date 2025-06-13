#include "objects/ball.h"

void Ball::update(float dt)
{
    position += velocity * dt;
}
