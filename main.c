#include <stdio.h>
#include "interface.h"
#include "regis.h"
#include "login.h"

int main()
{
    int choice;

    while (1)
    {
        // Main Menu
        choice = mainMenu();

        // Registration
        if (choice == 1)
        {
            registration();
        }

        // Login
        else if (choice == 2)
        {
            login();
        }

        // Exit
        else if (choice == 3)
        {
            clearScreen();
            printHeader();

            successMessage("Thank you for using Library Management System!");

            printf("\n");
            printf("        Exiting application...\n\n");

            break;
        }
    }

    return 0;
}