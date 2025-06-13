#include <SDL2/SDL.h>
#include "math/Vec2.h"
#include <glad/glad.h>
#include <chrono>
#include <vector>
#include <memory>
#include "objects/Ball.h"
#include "objects/BallFactory.h"

bool running = true;
std::vector<std::unique_ptr<Ball>> balls;

void healthcheck()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("CPPEG", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(window);
    gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            running = false;
    }
}

void update(float dt)
{
    // update physics or ball position here
    for (auto &ball : balls)
    {
        ball->update(dt);
    }
}

void renderFrame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // draw ball here
    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow()); // quick hack for now
}

int main()
{
    healthcheck();

    using clock = std::chrono::high_resolution_clock;
    auto prev = clock::now();
    const float dt = 1.0f / 60.0f;
    float accumulator = 0.0f;
    balls.push_back(BallFactory::createBall({400, 300}, {200, 150}, 20.0f));

    while (running)
    {
        processInput();

        auto now = clock::now();
        accumulator += std::chrono::duration<float>(now - prev).count();
        prev = now;

        while (accumulator >= dt)
        {
            update(dt);
            accumulator -= dt;
        }

        renderFrame();
    }

    SDL_Quit();
    return 0;
}
