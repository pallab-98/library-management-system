#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void clearScreen()
{
    system("cls");
}

void printHeader()
{
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║              LIBRARY MANAGEMENT              ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
}

void printTitle(char title[])
{
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║              %-30s      ║\n", title);
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
}