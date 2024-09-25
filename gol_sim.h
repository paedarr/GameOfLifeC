/**
 * @file gol_sim.h
 * @author Paedar Rader
 * @brief This file contains the function defintions for the main game of life simulation
 * functionality.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GOL_SIM_H
#define GOL_SIM_H

#include "gol_io.h"

/** runSimulation
     * Runs the Game of Life simulation.
     * @param board, a char**, representing the game board, containing empty spaces and live spaces
     * @param iterations, an integer representing number of simulation iterations
     * @param args_arr, a char* array containing command line arguments from user
     * @param height, an integer representing the height of the board
     * @param width, an integer representing the width of the board
     * @return Returns nothing. Does update board, and other data members, internally
     */
void runSimulation(char** board, int iterations, char* args_arr[4], int height, int width);
/** game_logic_update
     * Updates the game board for the current pass over the board.
     * @param board, a char**, representing the game board, containing empty spaces and live spaces
     * @param height, an integer representing the height of the board
     * @param width, an integer representing the width of the board
     * @param doesWrap, an integer representing, in binary, if the board will wrap during simulation, or not 
     * @return Returns a char**, representing the updated game board after current simulation over the board
     */
char** game_logic_update(char** board, int height, int width, int doesWrap);
/** neighbor_check
     * Looks at all neighbors of current cell, runs game of life parameters on these neighbors
     * This function also frees the game board after use, allowing for proper memory allocation & de-allocation
     * @param board, a char**, representing the game board, containing empty spaces and live spaces
     * @param row, an integer representing the number of rows on the board
     * @param col, an integer representing the number of cols on the board
     * @param doesWrap, an integer representing, in binary, if the board will wrap during simulation, or not 
     * @param height, an integer representing the height of the board
     * @param width, an integer representing the width of the board
     * @return Returns a char, representing the updated current cell that was passed (via row and col location)
     */
char neighbor_check(char** board, int row, int col, int doesWrap, int height, int width);
/** getFramerate
     * Tells program how many frames per second will be output
     * @param identifier, a char* (string), representing the speed (framerate) of the program
     * @return Returns an int, representing the num of frames per second for specified speed
     */
int getFramerate(char* identifier);

#endif