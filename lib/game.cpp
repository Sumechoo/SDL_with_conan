#include <iostream>
#include <SDL_ttf.h>

using namespace std;

namespace Game {
    void initGame() {
        printf("Init game here");

        if(TTF_Init() == -1) {
            printf("Error initing TTF");
        }
    }
}
