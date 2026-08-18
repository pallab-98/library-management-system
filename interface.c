#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "interface.h"


// Clear Screen
void clearScreen()
{
    system("cls");
}


// Main Header
void printHeader()
{
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║              LIBRARY MANAGEMENT              ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
}


// Title Box
void printTitle(char title[])
{
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║              %-30s      ║\n", title);
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
}


// Main Menu
int mainMenu()
{
    int selected = 0;
    int key;

    while (1)
    {
        clearScreen();

        printHeader();

        printf("\n");

        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                                              ║\n");
        printf("║                  MAIN MENU                   ║\n");
        printf("║                                              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║                                              ║\n");


        // Registration
        if (selected == 0)
        {
            printf("║              \033[1;30;46m> Registration <\033[0m              ║\n");
        }
        else
        {
            printf("║                Registration                 ║\n");
        }


        // Login
        if (selected == 1)
        {
            printf("║                  \033[1;30;46m> Login <\033[0m                  ║\n");
        }
        else
        {
            printf("║                    Login                    ║\n");
        }


        // Exit
        if (selected == 2)
        {
            printf("║                   \033[1;30;46m> Exit <\033[0m                   ║\n");
        }
        else
        {
            printf("║                     Exit                    ║\n");
        }


        printf("║                                              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║          ↑ ↓ Select     ENTER Confirm        ║\n");
        printf("╚══════════════════════════════════════════════╝\n");


        key = _getch();


        // ENTER
        if (key == 13)
        {
            return selected + 1;
        }


        // Arrow Key
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


// Success Message
void successMessage(char message[])
{
    printf("\n");

    printf("\033[1;32m");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                   SUCCESS                    ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  %-43s ║\n", message);
    printf("╚══════════════════════════════════════════════╝\n");

    printf("\033[0m");

    printf("\nPress any key to continue...");
    _getch();
}


// Error Message
void errorMessage(char message[])
{
    printf("\n");

    printf("\033[1;31m");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                    ERROR                     ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  %-43s ║\n", message);
    printf("╚══════════════════════════════════════════════╝\n");

    printf("\033[0m");

    printf("\nPress any key to continue...");
    _getch();
}


// Warning Message
void warningMessage(char message[])
{
    printf("\n");

    printf("\033[1;33m");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                   WARNING                    ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  %-43s ║\n", message);
    printf("╚══════════════════════════════════════════════╝\n");

    printf("\033[0m");

    printf("\nPress any key to continue...");
    _getch();
}


// Information Message
void infoMessage(char message[])
{
    printf("\n");

    printf("\033[1;36m");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                  INFORMATION                 ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  %-43s ║\n", message);
    printf("╚══════════════════════════════════════════════╝\n");

    printf("\033[0m");

    printf("\nPress any key to continue...");
    _getch();
}