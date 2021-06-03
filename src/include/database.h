#ifndef DATABASE_H
#define DATABASE_H

void newUser(char * userLogin, char * userPassword);
void checkUser(char* login, char* password, int attempts);
void passAgain (char* userLogin, int attempts);

#endif