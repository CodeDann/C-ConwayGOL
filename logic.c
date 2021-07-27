#include <stdio.h>
#include <stdlib.h>

#include "graphics.h" 

int get_neighbours(rowNo, colNo){
    int count = 0;
    //for all the central cells
    if( (rowNo > 0 && rowNo < rowcol-1) && (colNo > 0 && colNo < rowcol-1) ){
        //top left
        if( *(arr + (colNo-1)*rowcol + (rowNo-1)) == 1){count++;}
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //top right
        if( *(arr + (colNo+1)*rowcol + (rowNo-1)) == 1){count++;}
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
        // bottom right
        if( *(arr + (colNo+1)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom left
        if( *(arr + (colNo-1)*rowcol + (rowNo+1)) == 1){count++;}
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
    }
    //top left corner
    else if( rowNo == 0 && colNo == 0 ){
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
        // bottom right
        if( *(arr + (colNo+1)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
    }
    //top middle
    else if( rowNo == 0 && (0 < colNo && colNo < rowcol-1)){
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
        // bottom left
        if( *(arr + (colNo-1)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom right
        if( *(arr + (colNo+1)*rowcol + (rowNo+1)) == 1){count++;}
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
    }
    //top right corner
    else if( rowNo == 0 && colNo == (rowcol-1) ){
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
        // bottom left
        if( *(arr + (colNo-1)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
    }
    //right middle 
    else if( (0 < rowNo && rowNo < rowcol-1) && (colNo == rowcol-1) ){
        //top left
        if( *(arr + (colNo-1)*rowcol + (rowNo-1)) == 1){count++;}
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
        // bottom left
        if( *(arr + (colNo-1)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
    }
    //bottom right
    else if( rowNo == rowcol-1 && colNo == rowcol-1){
        //top left
        if( *(arr + (colNo-1)*rowcol + (rowNo-1)) == 1){count++;}
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
    }
    //bottom middle
    else if( rowNo == rowcol-1 && ( 0 < colNo && colNo < rowcol-1) ){
        //top left
        if( *(arr + (colNo-1)*rowcol + (rowNo-1)) == 1){count++;}
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //left
        if( *(arr + (colNo-1)*rowcol + (rowNo)) == 1){count++;}
        //top right
        if( *(arr + (colNo+1)*rowcol + (rowNo-1)) == 1){count++;}
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
    }
    //bottom left corner
    else if( rowNo == rowcol-1 && colNo == 0){
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //top right
        if( *(arr + (colNo+1)*rowcol + (rowNo-1)) == 1){count++;}
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
    }
    //right middle
    else if( (0 < rowNo && rowNo < rowcol-1) && (colNo == 0) ){
        //top
        if( *(arr + (colNo)*rowcol + (rowNo-1)) == 1){count++;}
        //top right
        if( *(arr + (colNo+1)*rowcol + (rowNo-1)) == 1){count++;}
        // right
        if( *(arr + (colNo+1)*rowcol + (rowNo)) == 1){count++;}
        // bottom
        if( *(arr + (colNo)*rowcol + (rowNo+1)) == 1){count++;}
        // bottom right
        if( *(arr + (colNo+1)*rowcol + (rowNo+1)) == 1){count++;}
    }

    return count;
}


int next_generation(){

    int i;
    int j;
    int k = 0;
    int neighbourArr[rowcol * rowcol];
    for( i = 0; i < rowcol; i++)
    {
        for( j = 0; j < rowcol; j++)
        {    
            //for each cell find the numb neighbours and add to array
            neighbourArr[k] = get_neighbours(i, j);
            k++;
        }
    }
    //then calculate if it lives or dies in the next generation
    // if 0 --> ( 3 neighbours ) --> 1
    // if 1 --> ( <2 neighbours || >3 nieghbours ) --> 0 
    k = 0;
    for( i = 0; i < rowcol; i++ ){
        for( j = 0; j < rowcol; j ++){
            if( *(arr + j*rowcol + i) == 1 ){
                if( neighbourArr[k] < 2 || neighbourArr[k] > 3){
                    *(arr + j*rowcol + i) = 0;
                }
            }
            else if( *(arr + j*rowcol + i) == 0 ){
                if( neighbourArr[k] == 3){
                    *(arr + j*rowcol + i) = 1;
                }
            }
            k++;
        }
    }
    
}

