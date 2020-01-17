#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "List.h"

surnameNode* create_node();
char* email_generate(char* surname);
char* email_update(char* surname, char* name, char *email, int no);
int emailCompare(char *email1, char *email2);
bool isTwoNamed(char *name);
char* concatenate(char *name);

#endif // !FUNCTIONS_H

