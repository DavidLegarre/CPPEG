#pragma once
#include "Ball.h"
#include <memory>
#include <vector>
#include <cmath>
#include <glad/glad.h> // or <GL/gl.h> depending on your setup

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class BallFactory
{
public:
    static std::unique_ptr<Ball> createBall(const Vec2 &pos, const Vec2 &vel, float radius)
    {
        return std::make_unique<Ball>(pos, vel, radius);
    }
};

inline void drawCircle(const Vec2 &center, float radius, int segments = 32)
{
    std::vector<float> verts;
    verts.push_back(center.x);
    verts.push_back(center.y);

    for (int i = 0; i <= segments; i++)
    {
        float theta = float(i) / segments * (2.0f * float(M_PI));
        verts.push_back(center.x + radius * cos(theta));
        verts.push_back(center.y + radius * sin(theta));
    }

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), verts.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, (GLsizei)(verts.size() / 2));
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}