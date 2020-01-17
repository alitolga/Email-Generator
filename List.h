#ifndef LIST_H
#define LIST_H

struct studentInfo
{
	char* name;
	char* surname;
	char* email;
	studentInfo* next;
	studentInfo* previous;
};

struct surnameNode
{
	char* surname;
	studentInfo* student;
	surnameNode* next;	
};

struct List 
{
	surnameNode* head;
	// int create_check = 0;
	void create();
	void close();
	void readFromFile(); // Adds all the students from the "newStudentsList.txt" file.
	void writeToFile(); // Writes all the students with their emails to the	"emailList.txt" file.
	void printList();
	void makeEmpty();
	void printSurnameNode(char* surname);
	void add(surnameNode* value);
	void deleteStudent(char* name, char* surname, char* email);
	void deleteSurnameNode(char* surname);
	void update();
};


#endif
