#include <iostream>
#include <vector>
#include <SDL.h>
#include "particle.h"
#include "constraint.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Partikelsimulation", 
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          640, 480, SDL_WINDOW_SHOWN);
                                          SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!window) {
        std::cerr << "SDL CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    std::vector<Particle> particles;
    particles.emplace_back(200.0f, 100.0f);
    particles.emplace_back(300.0f, 100.0f);


    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        float dt = 0.016f;

        for (auto& p : particles) {
             p.applyForce(0.0f, 500.0f); // gravity
             p.update(dt);
        }


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (const auto& p : particles) {
            SDL_Rect r;
            r.x = (int)p.getX() - 2;
            r.y = (int)p.getY() - 2;
            r.w = 10;
            r.h = 10;
            SDL_RenderFillRect(renderer, &r);
        }


        SDL_RenderPresent(renderer);

        // you could also add SDL_RenderClear and SDL_RenderPresent here if needed

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
