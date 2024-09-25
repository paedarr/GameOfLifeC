/**
 * @file gol_cmd.h
 * @author Paedar Rader
 * @brief This file contains the function definitions for the extraction functionality from
 * the command line arguments.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GOL_CMD_H
#define GOL_CMD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> // for timeofday
#include <unistd.h> // for usleep

/** extractInfo
     * Extracts all important input information from user's command line argument
     * @param argumentsStr, a char* array, representing the command line string from main
     * @param args_arr, a char* array, representing space to hold the specific pieces of the command line argument
     * @return Returns nothing, changes contents of args_arr internally
     */
void extractInfo(char* argumentsStr[], char* args_arr[4]);


#endif