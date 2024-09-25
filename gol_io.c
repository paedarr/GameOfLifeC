/**
 * @file gol_io.c
 * @author Paedar Rader
 * @brief This file contains the functions that controls the i/o functionality for the 
 * game of life program. This includes reading in the user's file from the command line arguments.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "gol_io.h"

char** readFile(char* filename, int* iters, int* height, int* width){
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    int h, w, iterations; // rows = height, cols = width
    fscanf(file, "%d\n %d\n %d\n", &h, &w, &iterations);
    char** board = initializeBoard(h, w);
    // now reading in the grid locations to be initialized to 1 at startup
    int x, y, check;
    check = fscanf(file, "%d %d", &x, &y);
    if (check == 2){
        // sets the location to 'alive'
        board[x][y] = '@'; 
        while(check == 2){
            check = fscanf(file, "%d %d", &x, &y);
            board[x][y] = '@';
        }
    }
    *iters = iterations;
    *height = h;
    *width = w;

    fclose(file);
    return board;
}

char** initializeBoard(int row, int col){ // makes empty board
    char** board = malloc(row * sizeof(char*));
    for (int i = 0; i < row; i++) {
        board[i] = malloc(col * sizeof(char));
    }
    char space = '-';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) { 
            // filling board with '-' characters
            board[i][j] = space; 
        }
    }
    return board;
}

void printBoard(char** board, int height, int width){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", board[i][j]);
        }
    printf("\n");
}
}