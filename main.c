#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "logic.h"
#include "graphics.h"

int generations;

int main(){

    setup_and_load();

    int i;
    for(i = 0; i < generations; i++ ){
        render_grid();
        SDL_Delay(1000);
        next_generation();
    }

    save_game();
    exit_and_cleanup();

}