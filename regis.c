#include <stdio.h>
#include "regis.h"
#include "interface.h"

void registration()
{
    clearScreen();
    printHeader();

    printf("\n");
    printf("        ========================================\n");
    printf("                 REGISTRATION\n");
    printf("        ========================================\n");

    printf("\n        Registration page opened successfully!\n");

    successMessage("Registration option selected!");

    printf("\n        Press any key to return...");
    getchar();
    getchar();
}