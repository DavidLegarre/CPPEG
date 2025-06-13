#include "objects/Ball.h"

void Ball::update(float dt)
{
    position += velocity * dt;
}
