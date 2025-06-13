#ifndef VEC2_H
#define VEC2_H

struct Vec2
{
    float x, y;

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2 &other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 &operator+=(const Vec2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
};

#endif // VEC2_H
