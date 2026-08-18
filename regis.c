#include <stdio.h>
#include <conio.h>
#include "regis.h"
#include "interface.h"

void registration()
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
        printf("║                  REGISTRATION                ║\n");
        printf("║                                              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║                                              ║\n");

        // Admin Registration
        if (selected == 0)
        {
            printf("║              \033[1;30;46m> Admin Registration <\033[0m          ║\n");
        }
        else
        {
            printf("║                Admin Registration           ║\n");
        }

        // User Registration
        if (selected == 1)
        {
            printf("║              \033[1;30;46m> User Registration <\033[0m           ║\n");
        }
        else
        {
            printf("║                User Registration            ║\n");
        }

        // Back
        if (selected == 2)
        {
            printf("║                      \033[1;30;46m> Back <\033[0m              ║\n");
        }
        else
        {
            printf("║                      Back                    ║\n");
        }

        printf("║                                              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║          ↑ ↓ Select     ENTER Confirm        ║\n");
        printf("╚══════════════════════════════════════════════╝\n");

        key = _getch();

        // ENTER
        if (key == 13)
        {
            if (selected == 0)
            {
                adminRegistration();
            }
            else if (selected == 1)
            {
                userRegistration();
            }
            else if (selected == 2)
            {
                return;
            }
        }

        // Arrow keys
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