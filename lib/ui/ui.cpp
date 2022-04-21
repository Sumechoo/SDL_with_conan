#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

using namespace std;

namespace ui {
    void createTextSurface(SDL_Renderer* renderer) {
        TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
        printf(TTF_GetError());

        SDL_Color White = {255, 255, 255};

        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);

        SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect Message_rect;
        Message_rect.x = 0;
        Message_rect.y = 0;
        Message_rect.w = 100;
        Message_rect.h = 100;

        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);
    }
}