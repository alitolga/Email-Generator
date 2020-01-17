#include "Functions.h"
#include "List.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <istream>

using namespace std;

surnameNode* create_node()
{
	char *temp1, *temp2;
	temp1 = new char[50];
	temp2 = new char[50];
	cin.getline(temp1, 50, '\t');
	cin.getline(temp2, 50, '\n');
	// cout << endl << temp1 << endl << temp2 << endl;
	surnameNode* node = new surnameNode;
	node->student = new studentInfo;
	node->student->name = new char[strlen(temp1) + 1];
	node->student->surname = new char[strlen(temp2) + 1];
	node->surname = new char[strlen(temp2) + 1];
	strcpy(node->student->name, temp1);
	strcpy(node->student->surname, temp2);
	strcpy(node->surname, temp2);
	node->student->next = NULL;
	node->student->previous = NULL;
	node->next = NULL;
	delete[] temp1;
	delete[] temp2;
	return node;
}

// Kullan�c�ya ilk emaili olu�turuyor.
char* email_generate(char* surname)
{ 
	char *email = new char[strlen(surname) + 12];
	int i = 0;
	while (i < strlen(surname))
	{
		email[i] = tolower(surname[i]);
		i++;
	}
	email[strlen(surname)] = '\0';
	email = strcat(email, "@itu.edu.tr");
	cout << "Email generated: " << email << endl;
	return email;
}

// Yeni bir email olu�turup, o emaili olu�turdu�u yerin pointer'�n� d�necek.
char* email_update(char* surname, char* name, char *email, int no)
{
	char* temp;
	temp = strtok(email, "@");
    //cout << "temp: " << temp << endl;
	int letternumber = strlen(temp) - strlen(surname);
    //cout << "letter difference: " << letternumber << endl;
	
	// Kullan�c�n�n ismindeki t�m harfler bittiyse ve kullan�c�ya say� ekliyor.
	if (no != 0)
	{ 
		char* str = new char[2];
		char c = no + '0';
		str[0] = c;
		str[1] = '\0';
		temp[strlen(name) + strlen(surname)] = '\0';
		temp = strcat(temp, str);
		temp = strcat(temp, "@itu.edu.tr");
		cout << "Email updated: " << email << endl;
		return temp;
	}

	// Kullan�c�n�n isminden bir harf ekliyor.
	char c = tolower(name[letternumber]);
	char* str = new char[2];
	str[0] = c;
	str[1] = '\0';
	temp = strcat(temp, str);
	temp = strcat(temp, "@itu.edu.tr");
	cout << "Email updated: " << email << endl;
	return temp;
}

// Emaillar� @itu.edu.tr k�sm� olmadan kar��la�t�r�yor.

int emailCompare(char *email1, char *email2)
{
	char *temp1, *temp2;
	temp1 = new char[strlen(email1) + 1];
	temp2 = new char[strlen(email2) + 1];
	strcpy(temp1, email1);
	strcpy(temp2, email2);
	temp1 = strtok(temp1, "@");
	temp2 = strtok(temp2, "@");
	return strcmp(temp1, temp2);
}

// �sim, iki veya daha fazla isimliyse true; de�ilse false d�nd�r�yor.

bool isTwoNamed(char *name)
{
	char *temp1, *temp2;
	temp1 = new char[strlen(name) + 1];
	temp2 = new char[strlen(name) + 1];
	strcpy(temp1, name);
	strcpy(temp2, temp1);
	strtok(temp1, " ");
	if (strlen(temp1) == strlen(temp2))
	{
		delete temp1;
		delete temp2;
		return false;
	}
	delete temp1;
	delete temp2;
	return true;
}

// Birden �ok ismi olan kullan�c�lar�n isimlerini birle�tiriyor.
// Daha sonra ki�iye mail atarken harfleri bu t�m isimlerinin oldu�u char arrayinden atayaca��m.

char *concatenate(char *name)
{
	char *temp1, *temp2;
	temp1 = new char[strlen(name) + 1];
	temp2 = new char[strlen(name) + 1];
	strcpy(temp2, name);
	int i = 0, j = 0, spacecount = 0;
	while (i < strlen(temp2))
	{
		if (temp2[i] == ' ')
		{
			i++;
			spacecount++; // Number of spaces in the name. (Maybe the person has 3 or more names.)
			continue;
		}
		temp1[j] = temp2[i];
		j++;
		i++;
	}
	temp1[strlen(temp2) - spacecount] = '\0';
	delete temp2;
	return temp1;
}
