#include <fstream>
#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

void List::readFromFile()
{
	ifstream fs;
	fs.open("newStudentsList.txt");
	while (!fs.eof())
	{
		surnameNode *temp = new surnameNode;
		temp->student = new studentInfo;
		temp->student->name = new char[50];
		temp->student->surname = new char[50];
		temp->surname = new char[50];
		fs.getline(temp->student->name, 50, '\t');
		cout << temp->student->name << endl;
		fs.getline(temp->surname, 50, '\n');
		cout << temp->surname << endl;
		strcpy(temp->student->surname, temp->surname);
		// cout << temp->student->surname << endl;
		add(temp);
		delete temp->surname;
		delete temp->student->name;
		delete temp->student->surname;
		delete temp->student;
		delete temp;
	}
	fs.close();

}

void List::writeToFile()
{
	ofstream fs;
	fs.open("emailList.txt", ios::trunc);
	surnameNode *traverse, *tail;
	studentInfo *p;
	traverse = head->next;
	tail = head;
	p = tail->student;
	while (p)
	{
		fs << p->email << "\t" << p->name << '\t' << p->surname << endl;
		p = p->next;
	}
	while (traverse != head)
	{
		tail = traverse;
		p = tail->student;
		while (p)
		{
			fs << p->email << "\t" << p->name << '\t' << p->surname << endl;
			p = p->next;
		}
		traverse = traverse->next;
	}
	fs.close();
}

