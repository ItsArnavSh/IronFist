#include "RenderCore.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "deltaTime.h"



void renderDisplay() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("IronFist", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN);
    if (window == nullptr) {
        std::cerr << "Window Could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Game loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // Time tracking variables
    float objectSpeed = 200.0f; // Pixels per second
    float objectOffset = 0.0f;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Calculate delta time
        findDeltaTime();

        // Update logic using delta
        objectOffset += objectSpeed * delta; // Move based on speed and delta
        if (objectOffset > 800) {
            objectOffset -= 800; // Wrap around if off-screen
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Render objects
        SDL_Rect rect = { static_cast<int>(200 + objectOffset), 150, 100, 100 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &rect);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
