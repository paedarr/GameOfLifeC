/**
 * @file gol_io.h
 * @author Paedar Rader
 * @brief This file contains the function defintions for the input/output aspects of the
 * game of life functionality, using the user's terminal as the i/o interface.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GOL_IO_H
#define GOL_IO_H

#include "gol_cmd.h"

/** readFile
     * Reads in the input file specified by the user in the command line
     * @param filename, a char*, representing the filename from the user
     * @param iters, an integer*, representing number of simulation iterations
     * @param height, an integer*, representing the height of the board
     * @param width, an integer*, representing the width of the board
     * @return Returns a char**, representing the initial game board
     */
char** readFile(char* filename, int* iters, int* height, int* width);
/** initializeBoard
     * Initializes the first game board, based on the user's input file
     * @param row, an integer, representing the rows of the board
     * @param col, an integer, representing the cols of the board
     * @return Returns a char**, representing the first initial game board
     */
char** initializeBoard(int row, int col);
/** printBoard
     * Prints out the entire game board to the terminal output, if user specified show.
     * Contains sleeping functionality, and clearing functionality.
     * @param board, a char**, representing the game board
     * @param height, an integer, representing the height of the board
     * @param width, an integer, representing the width of the board
     * @return Returns nothing
     */
void printBoard(char** board, int height, int width);

#endif