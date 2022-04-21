#include <iostream>
#include <SDL2/SDL.h>

#include "lib/game.cpp"
#include "lib/ui/ui.cpp"

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::printf("error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window* win = SDL_CreateWindow("Hello world", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 620, 387, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (win == NULL) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0x0);
    SDL_bool done = SDL_FALSE;

    Game::initGame();

    while (!done) {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 0, 0, 400, 400);

        ui::createTextSurface(renderer);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
    }

    SDL_Quit();

    return 0;
}