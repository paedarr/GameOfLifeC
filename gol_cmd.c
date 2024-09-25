/**
 * @file gol_cmd.c
 * @author Paedar Rader
 * @brief This file contains the function used to extract useful information from the user's
 * command line argument(s). Here, the function changes information in an array passed by pointer,
 * affecting an array in gol.c.
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "gol_cmd.h"

void extractInfo(char* argumentsStr[], char* args_arr[4]){
    char* framerate;
    char* filename = argumentsStr[1]; 
    char* wrapType = argumentsStr[2];
    char* showType = argumentsStr[3];
    if (strcmp(argumentsStr[4], "slow") == 0 || strcmp(argumentsStr[4], "med") == 0 || strcmp(argumentsStr[4], "fast") == 0){ // sets framerate anyways, because if it is hide, it won't matter
        framerate = argumentsStr[4];
    }
    else{
        // if the user selects hide, still gets assigned a framerate even though
        // it's not used
        framerate = "med";
    }
    args_arr[0] = filename;
    args_arr[1] = wrapType;
    args_arr[2] = showType;
    args_arr[3] = framerate;
}