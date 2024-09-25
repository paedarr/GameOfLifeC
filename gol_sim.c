/**
 * @file gol_sim.c
 * @author Paedar Rader
 * @brief This file contains the main program functionality of the game of life simulation,
 * and the required helper functions for such. All function descriptions are in the respective
 * '.h' file.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "gol_sim.h"

void runSimulation(char** board, int iterations, char* args_arr[4], int height, int width){
    
    int doesWrap = 0;
    if (strcmp(args_arr[1], "wrap") == 0){
        doesWrap = 1;
    }
    int framerate = getFramerate(args_arr[3]);
    for (int i = 0; i < iterations; i++){
        system("clear");
        board = game_logic_update(board, height, width, doesWrap);
        if (strcmp(args_arr[2], "show") == 0){
            printBoard(board, height, width);
            usleep((1000000 / framerate)); // 1000000 microseconds = 1 second
        }
    }
}

char** game_logic_update(char** board, int height, int width, int doesWrap){
    char** next_board = initializeBoard(height, width);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            char new_space = neighbor_check(board, i, j, doesWrap, height, width);
            next_board[i][j] = new_space;
        }
    }

    for (int i = 0; i < height; i++) {
        free(board[i]); // free each row
    }
    free(board);

    return next_board;
}

char neighbor_check(char** board, int row, int col, int doesWrap, int height, int width) {
    int live_nei_count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // skip middle cell
            }

            int neighbor_row = row + i;
            int neighbor_col = col + j;

            if (doesWrap == 1){
                // wrapping functionality uses modular arthimetic
                neighbor_row = (neighbor_row + height) % height;
                neighbor_col = (neighbor_col + width) % width;
            } 
            else{
                // no wrapping, but is out of bounds
                if (neighbor_row < 0 || neighbor_row >= height || neighbor_col < 0 || neighbor_col >= width) {
                    continue;
                }
            }

            if (board[neighbor_row][neighbor_col] == '@') {
                live_nei_count++;
            }
        }
    }

    // current cell determiner
    if (board[row][col] == '@') {
        if (live_nei_count <= 1 || live_nei_count >= 4) {
            return '-';
        } else {
            return '@';
        }
    } else {
        if (live_nei_count == 3) {
            return '@';
        } else {
            return '-';
        }
    }
}

int getFramerate(char* identifier){
    if (strcmp(identifier, "slow") == 0){ // 3 frames per second
        return 3;
    }
    else if (strcmp(identifier, "med") == 0){ // 10 frames per second
        return 10;
    }
    else if (strcmp(identifier, "fast") == 0){ // 30 frames per second
        return 30;
    }
    else{
        printf("Unknown framrate type!");
        return -1;
    }
}