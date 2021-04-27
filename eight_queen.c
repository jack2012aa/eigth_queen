#include <stdio.h>
#include <stdlib.h>

int count = 1;  //count the # of answers

void print_checkeboard(int *checkerboard, int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            printf("%d ", *((checkerboard + i * length) + j));
        }
        printf("\n");
    }
}

/*
*Check whether the newest queen's position legitimate, if legitimate return 1, illegitimate return 0
*checkerboard: 2D array recording queens' position
*row: newest queen's index of row
*column: newest queen's index of column
*length: the size of the checkerboard
*/
int check(int *checkerboard, int row, int column, int length){
    
    for (int i = row; i >= 0; i--){
        if (*((checkerboard + i * length) + column) == 1)
            return 0;
    }

    for (int i = row, j = column; (i >= 0 && j >= 0 && j < length); i--, j--){
        if (*((checkerboard + i * length) + j) == 1)
            return 0;
    }

    for (int i = row, j = column; (i >= 0 && j >= 0 && j < length); i--, j++){
        if (*((checkerboard + i * length) + j) == 1)
            return 0;
    }

    return 1;
}

/*
*Place a queen on an appropriate row, and then put one on the next row. Print the result after there are length queen on the checkerboard
*checkerboard: 2D array recording queens' position
*row: newest queen's index of row
*length: the size of the checkerboard
*/
void place_queen(int *checkerboard, int row, int length){
    
    if (row < length){
        for (int column = 0; column < length; column++){
            if (check(checkerboard, row, column, length) == 1){
                *((checkerboard + row * length) + column) = 1;  //record new queen's position
                place_queen(checkerboard, row + 1, length);  //place another new queen on next row
                *((checkerboard + row * length) + column) = 0;  //fresh board's state for next placing
            } else {
                continue;
            }
        }
    } else {
        printf("=====%d=====\n", count++);
        print_checkeboard(checkerboard, length);
        printf("\n");
    }
}


int main(){

    int length = 8;  //the size of the checkerboard

    int checkerboard[length][length];
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            checkerboard[i][j] = 0;
        }
    }

    place_queen(checkerboard, 0, length);

    return 0;
}