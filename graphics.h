#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <SDL2/SDL.h>

//loads the inital state of the game from an external file
//returns 1 on correct load
//returns negative for error condition
int load_game(FILE *file);

//once game is finished this saves the state of the game into another external file
int save_game(FILE *file);

//renders the alive and dead cells onto the grid
void render_grid();

//initilises SDL and the window
int setup_and_load();

//global variables
extern int *arr;
extern int rowcol;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern int generations;


#endif