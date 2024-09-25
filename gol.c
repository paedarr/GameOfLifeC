/**
 * @file gol.c
 * @author Paedar Rader
 * @brief This file contains main, which utilizes the functions of every other .c file, 
 * including the game of life functionality, i/o operations, and extracting information
 * from the command line arguments. 
 * @note For program info, please refer to .h files which include the description of each
 * program function in detail. For other information, refer to README file.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "gol.h"

int main (int argc, char *argv[]) {
    // Ignores warning about argc being unused
    // 'argc' is important to command line args functionality
    (void)argc;

    // creating timer for program execution time
    struct timeval start, end;
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&start, NULL);

    char* cmd_args[4];
    // this places arugments in cmd_args string array
    extractInfo(argv, cmd_args); 
    int iters, height, width;
    char** start_board = readFile(cmd_args[0], &iters, &height, &width);
    runSimulation(start_board, iters, cmd_args, height, width);

    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Total time for %d iterations of %dx%d is %f secs\n", iters, height, width, elapsed);
}