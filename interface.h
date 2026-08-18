#ifndef INTERFACE_H
#define INTERFACE_H

void clearScreen();

void printHeader();

void printTitle(char title[]);

int mainMenu();

void successMessage(char message[]);

void errorMessage(char message[]);

void warningMessage(char message[]);

void infoMessage(char message[]);

#endif
