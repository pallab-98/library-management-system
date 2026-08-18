#ifndef FILE_H
#define FILE_H

void saveAdmin(char username[], char password[]);

void saveUser(char username[], char password[]);

int adminExists(char username[]);

int userExists(char username[]);

int doualCheckUsernameExists(char username[]);

#endif