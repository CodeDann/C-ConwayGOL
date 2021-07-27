#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "logic.h"

#define CELL_SIDE_LENGTH 100
int rowcol;
SDL_Renderer *renderer;
SDL_Window *window;
int *arr;
int generations;

int load_game(FILE *file){
	file = fopen("game_store.txt", "r");
    //check that its not empty
    if(!file) {
        printf("There is no game file store!\n");
        return -1;
    }
    //store number of rows/columns to rowcol
	fscanf(file, "%d", &rowcol);

    //dynamically create matrix
	arr = (int *)malloc(rowcol * rowcol * sizeof(int)); 


    //store values from text file into matrix
	int i, j;
	for (i = 0; i < rowcol; i++){
		for (j = 0; j < rowcol; j++){
			fscanf(file, "%d", &*(arr + j*rowcol + i)); 
        }
    }

    //store the number of generations
    fscanf(file, "%d", &generations);
    
    return 1;
}

int save_game(FILE *file){
    file = fopen("save_store.txt", "w");
    fprintf(file, "%d ", rowcol);
    int i, j;
    for( i = 0; i < rowcol; i++){
        for( j = 0; j < rowcol; j++){
            fprintf(file, "%d ", *(arr + j*rowcol + i));
        }
    }
    fprintf(file, "%d", generations);
}


int setup_and_load(){

    //initilise SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL2 not initilised!");
        return -1;
    }


    //Get size of screen from setup file
    FILE *file;
    load_game(file);  

    //create window
    SDL_Window *window = SDL_CreateWindow("Conways Game of Life", 0, 0, rowcol*CELL_SIDE_LENGTH, rowcol*CELL_SIDE_LENGTH, SDL_WINDOW_SHOWN);
    if (window == NULL){
        printf("Error creating SDL window");
        return -1;
    }


    //create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        SDL_DestroyWindow(window);
        printf("Error rendering");
        return -1;
    }

    //draws the grid
    int g;
    for( g = 1; g < rowcol; g++){
        SDL_SetRenderDrawColor(renderer, 47,79,79, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, CELL_SIDE_LENGTH*g, 0, CELL_SIDE_LENGTH*g, rowcol*CELL_SIDE_LENGTH);
        SDL_RenderDrawLine(renderer, 0, CELL_SIDE_LENGTH*g, rowcol*CELL_SIDE_LENGTH, CELL_SIDE_LENGTH*g);
        SDL_RenderPresent(renderer);
    }

    return 1;
}

int render_grid(){
    int i;
    int j;
    int k = 0;
    for( i = 0; i < rowcol; i++)
    {
        for( j = 0; j < rowcol; j++)
        {   
            // draw alive cells in white
            if( *(arr + i*rowcol + j) == 1){
                SDL_Rect tmpRect;
                tmpRect.x = i*CELL_SIDE_LENGTH;
                tmpRect.y = j*CELL_SIDE_LENGTH;
                tmpRect.w = CELL_SIDE_LENGTH;
                tmpRect.h  = CELL_SIDE_LENGTH;
                SDL_SetRenderDrawColor(renderer, 255,255,255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer, &tmpRect);
                SDL_RenderFillRect(renderer, &tmpRect);
            }
            //draw dead cells in black
            else if(*(arr + i*rowcol + j) == 0){
                SDL_Rect tmpRect;
                tmpRect.x = i*CELL_SIDE_LENGTH;
                tmpRect.y = j*CELL_SIDE_LENGTH;
                tmpRect.w = CELL_SIDE_LENGTH;
                tmpRect.h  = CELL_SIDE_LENGTH;
                SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer, &tmpRect);
                SDL_RenderFillRect(renderer, &tmpRect);
            }
        }
    }
    //re-draws the grid
    int g;
    for( g = 1; g < rowcol; g++){
        SDL_SetRenderDrawColor(renderer, 47,79,79, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, CELL_SIDE_LENGTH*g, 0, CELL_SIDE_LENGTH*g, rowcol*CELL_SIDE_LENGTH);
        SDL_RenderDrawLine(renderer, 0, CELL_SIDE_LENGTH*g, rowcol*CELL_SIDE_LENGTH, CELL_SIDE_LENGTH*g);
        SDL_RenderPresent(renderer);
    }
    SDL_RenderPresent(renderer);
}



int exit_and_cleanup(){
    free(arr);
    SDL_DestroyWindow(window);
    SDL_Quit();
}