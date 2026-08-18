#include <stdio.h>
#include "interface.h"

void clearScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

void printHeader()
{
    printf("\033[1;36m");
    
    printf("============================================================\n");
    printf("||                                                        ||\n");
    printf("||          LIBRARY MANAGEMENT SYSTEM                    ||\n");
    printf("||                                                        ||\n");
    printf("============================================================\n");

    printf("\033[0m");
}