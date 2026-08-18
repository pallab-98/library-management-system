#include <stdio.h>
#include <string.h>

#include "file.h"


// ==================================================
// SAVE ADMIN
// ==================================================

void saveAdmin(char username[], char password[])
{
    FILE *fpt = fopen("admin.txt", "a");

    if (fpt == NULL)
    {
        return;
    }

    fprintf(fpt, "%s %s\n", username, password);

    fclose(fpt);
}


// ==================================================
// SAVE USER
// ==================================================

void saveUser(char username[], char password[])
{
    FILE *fpt = fopen("user.txt", "a");

    if (fpt == NULL)
    {
        return;
    }

    fprintf(fpt, "%s %s\n", username, password);

    fclose(fpt);
}


// ==================================================
// CHECK ADMIN USERNAME
// ==================================================

int adminExists(char username[])
{
    FILE *fpt = fopen("admin.txt", "r");

    char fileName[50];
    char filePassword[100];

    if (fpt == NULL)
    {
        return 0;
    }

    while (fscanf(fpt, "%49s %99s", fileName, filePassword) == 2)
    {
        if (strcmp(username, fileName) == 0)
        {
            fclose(fpt);
            return 1;
        }
    }

    fclose(fpt);

    return 0;
}


// ==================================================
// CHECK USER USERNAME
// ==================================================

int userExists(char username[])
{
    FILE *fpt = fopen("user.txt", "r");

    char fileName[50];
    char filePassword[100];

    if (fpt == NULL)
    {
        return 0;
    }

    while (fscanf(fpt, "%49s %99s", fileName, filePassword) == 2)
    {
        if (strcmp(username, fileName) == 0)
        {
            fclose(fpt);
            return 1;
        }
    }

    fclose(fpt);

    return 0;
}


// ==================================================
// CHECK USERNAME IN BOTH FILES
// ==================================================

int doualCheckUsernameExists(char username[])
{
    if (adminExists(username))
    {
        return 1;
    }

    if (userExists(username))
    {
        return 1;
    }

    return 0;
}