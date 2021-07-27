#ifndef GRAPHICS_H
#define GRAPHICS_H

//updates the global arr according to Conways GOL to be filled with the next generation of data
int next_generation();

//returns the number of alive neighbours a given cell has
int get_neighbours(int rowNo, int colNo);

//global variables
extern int *arr;
extern int rowcol;


#endif