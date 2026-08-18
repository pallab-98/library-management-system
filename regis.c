#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "regis.h"
#include "interface.h"
#include "file.h"


// ==================================================
// USERNAME VALIDATION
// ==================================================

int validUsername(char username[])
{
    int length = strlen(username);

    // Username length
    if (length < 4 || length > 20)
    {
        return 0;
    }

    // Username must start with letter
    if (!isalpha(username[0]))
    {
        return 0;
    }

    // Only letters, numbers and underscore
    for (int i = 0; i < length; i++)
    {
        if (!isalnum(username[i]) && username[i] != '_')
        {
            return 0;
        }
    }

    return 1;
}


// ==================================================
// PASSWORD VALIDATION
// ==================================================

int validPassword(char password[])
{
    int length = strlen(password);

    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    // Password minimum 8 characters
    if (length < 7)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            hasUpper = 1;
        }

        else if (islower(password[i]))
        {
            hasLower = 1;
        }

        else if (isdigit(password[i]))
        {
            hasDigit = 1;
        }

        else
        {
            hasSpecial = 1;
        }
    }

    if (hasUpper && hasLower && hasDigit && hasSpecial)
    {
        return 1;
    }

    return 0;
}


// ==================================================
// REGISTRATION MENU
// ==================================================

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
        printf("║                 REGISTRATION                 ║\n");
        printf("║                                              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║                                              ║\n");


        // Admin Registration
        if (selected == 0)
        {
            printf("║      \033[1;30;46m       > Admin Registration <       \033[0m      ║\n");
        }
        else
        {
            printf("║               Admin Registration             ║\n");
        }


        // User Registration
        if (selected == 1)
        {
            printf("║      \033[1;30;46m        > User Registration <        \033[0m      ║\n");
        }
        else
        {
            printf("║                User Registration             ║\n");
        }


        // Back
        if (selected == 2)
        {
            printf("║      \033[1;30;46m              > Back <              \033[0m      ║\n");
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


        // ARROW KEY
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


// ==================================================
// ADMIN REGISTRATION
// ==================================================

void adminRegistration()
{
    char username[50];
    char password[100];

    clearScreen();

    printHeader();

    printTitle("ADMIN REGISTRATION");


    printf("\n");
    printf("Enter Username : ");
    scanf("%49s", username);


    // Username validation
    if (!validUsername(username))
    {
        errorMessage(
            "Username must be 4-20 chars, letters/numbers/_ only."
        );

        return;
    }


    // Duplicate username
    if (doualCheckUsernameExists(username))
    {
        errorMessage("Username already exists!");

        return;
    }


    printf("Enter Password : ");

    scanf("%99s", password);


    // Password validation
    if (!validPassword(password))
    {
        errorMessage(
            "Password needs 8+ chars, upper, lower, digit & special."
        );

        return;
    }


    saveAdmin(username, password);


    successMessage("Admin registration successful!");
}


// ==================================================
// USER REGISTRATION
// ==================================================

void userRegistration()
{
    char username[50];
    char password[100];

    clearScreen();

    printHeader();

    printTitle("USER REGISTRATION");


    printf("\n");
    printf("Enter Username : ");
    scanf("%49s", username);


    // Username validation
    if (!validUsername(username))
    {
        errorMessage(
            "Username must be 4-20 chars, letters/numbers/_ only."
        );

        return;
    }


    // Duplicate username
    if (doualCheckUsernameExists(username))
    {
        errorMessage("Username already exists!");

        return;
    }


    printf("Enter Password : ");

    scanf("%99s", password);


    // Password validation
    if (!validPassword(password))
    {
        errorMessage(
            "Password needs 8+ chars, upper, lower, digit & special."
        );

        return;
    }


    saveUser(username, password);


    successMessage("User registration successful!");
}