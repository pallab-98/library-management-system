#include <stdio.h>
#include <conio.h>
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
    printf("||             LIBRARY MANAGEMENT SYSTEM                 ||\n");
    printf("||                                                        ||\n");
    printf("============================================================\n");

    printf("\033[0m");
}

int mainMenu()
{
    int selected = 0;
    int key;

    while (1)
    {
        clearScreen();
        printHeader();

        printf("\n");

        // Registration
        if (selected == 0)
        {
            printf("\033[1;30;46m");
            printf("                  > Registration <                       ");
            printf("\033[0m\n");
        }
        else
        {
            printf("                    Registration                          \n");
        }

        // Login
        if (selected == 1)
        {
            printf("\033[1;30;46m");
            printf("                  > Login <                              ");
            printf("\033[0m\n");
        }
        else
        {
            printf("                    Login                                 \n");
        }

        // Exit
        if (selected == 2)
        {
            printf("\033[1;30;46m");
            printf("                  > Exit <                               ");
            printf("\033[0m\n");
        }
        else
        {
            printf("                    Exit                                  \n");
        }

        printf("\n");
        printf("\033[1;33m");
        printf("              UP / DOWN : Select   ENTER : Confirm");
        printf("\033[0m\n");

        key = _getch();

        // ENTER
        if (key == 13)
        {
            return selected + 1;
        }

        // Arrow key
        if (key == 224)
        {
            key = _getch();

            // UP
            if (key == 72)
            {
                selected--;

                if (selected < 0)
                {
                    selected = 2;
                }
            }

            // DOWN
            else if (key == 80)
            {
                selected++;

                if (selected > 2)
                {
                    selected = 0;
                }
            }
        }
    }
}

void successMessage(char message[])
{
    printf("\n");
    printf("\033[1;32m");
    printf("        +------------------------------------------+\n");
    printf("        |              SUCCESS                     |\n");
    printf("        +------------------------------------------+\n");
    printf("        |  %s\n", message);
    printf("        +------------------------------------------+\n");
    printf("\033[0m");
}

void errorMessage(char message[])
{
    printf("\n");
    printf("\033[1;31m");
    printf("        +------------------------------------------+\n");
    printf("        |                ERROR                     |\n");
    printf("        +------------------------------------------+\n");
    printf("        |  %s\n", message);
    printf("        +------------------------------------------+\n");
    printf("\033[0m");
}