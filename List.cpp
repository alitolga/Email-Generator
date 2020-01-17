#include "List.h"
#include "Functions.h"
#include <iostream>
#include <cstring>

using namespace std;

////// Beginning of Add Function //////////

void List::add(surnameNode* record)
{
	// Surname Node'umu yarat�yorum.
	surnameNode* value = new surnameNode;
	value->student = new studentInfo;
	value->student->name = new char[strlen(record->student->name) + 1];
	value->student->surname = new char[strlen(record->student->surname) + 1];
	value->surname = new char[strlen(record->surname) + 1];
	strcpy(value->student->name, record->student->name);
	strcpy(value->student->surname, record->student->surname);
	strcpy(value->surname, record->surname);
	value->student->next = NULL;
	value->student->previous = NULL;
	value->next = NULL;

	// �lk elemansa.
	if (head == NULL)
	{
		head = value;
		value->next = head;
		value->student->email = email_generate(value->surname);
		return;
	}

	surnameNode *traverse, *tail;
	traverse = head;
	tail = traverse;

	// Ba�a eklenecekse.
	if (strcmp(value->surname, traverse->surname) < 0)
	{
		traverse = traverse->next;
		while (traverse->next != head) // Son elemana git.
		{
			traverse = traverse->next;
		}
		value->next = head;
		head = value;
		traverse->next = head;
		value->student->email = email_generate(value->surname);
		return;
	}

	//// Head ile ayn� soyadsa. ////
	if (strcmp(value->surname, traverse->surname) == 0)
	{
		studentInfo *current, *prev;
		current = traverse->student;
		prev = current;
		value->student->email = email_generate(value->surname);

		// Kay�t ba�a eklenecekse.
		if (emailCompare(value->student->email, current->email) < 0)
		{ 
			current->previous = value->student;
			value->student->next = current;
			traverse->student = value->student;
			return;
		}

		// Ayn� mail de�ilken t�m mailleri dola�.
		while (current && emailCompare(value->student->email, current->email) > 0)
		{
			prev = current;
			current = current->next;
		}

		// Maillerin sonuna geldiysek.
		if (current == NULL)
		{
			prev->next = value->student;
			value->student->previous = prev;
			value->student->next = NULL;
			return;
		}

		if (emailCompare(value->student->email, current->email) == 0)
		{
			int check = 0, no = 0;

			// Ayn� mail'den olup olmad���n� kontrol ediyorum.
			// Var ise yeni mail veriyorum.
			while (check != 1)  
			{  
				char *tempname = new char[strlen(value->student->name) + 1];
				strcpy(tempname, value->student->name);
				if (isTwoNamed(tempname))
				{
					char *t = tempname;
					tempname = concatenate(tempname);
					delete t;
				}
				value->student->email = email_update(value->student->surname, tempname, value->student->email, no);
				check = 1;
				studentInfo *p = traverse->student;
				
				// Atad���m mail o node'da var m� yok mu diye t�m node'u kontrol ediyorum.
				while (p)
				{
					// Varsa while'� bir daha d�nd�r�yorum.
					if (emailCompare(p->email, value->student->email) == 0)
					{
						check = 0;
						if (no != 0)
						{
							no++;
						}
						if (strlen(value->student->email) - 11 == strlen(tempname) + strlen(value->student->surname))
						{
							no = 2;
						}
						break;
					}
					p = p->next;
				}
				delete[] tempname;
			}
			// Mailim olu�tu.

			// Mailimi do�ru yere ekliyorum.
			while (current && emailCompare(value->student->email, current->email) > 0)
			{
				prev = current;
				current = current->next;
			}

			value->student->next = current;
			value->student->previous = prev;
			prev->next = value->student;
			if (current)
			{
				current->previous = value->student;
			}
			return;
		}

		// E�itlik yoksa do�rudan yeni mail'imi ekliyorum.
		value->student->next = current;
		value->student->previous = prev;
		prev->next = value->student;
		if (current)
		{
			current->previous = value->student;
		}

		return;
	}
	//// Head ile ayn� soyad de�ilse. ////

	// �lk soyad de�ilse.
	traverse = traverse->next;

	// Eklenece�i yere kadar git.
	while (traverse != head && strcmp(value->surname, traverse->surname) > 0)
	{
		tail = traverse;
		traverse = traverse->next;
	}

	// Ayn� soyaddan varsa.
	if (traverse != head && strcmp(value->surname, traverse->surname) == 0)
	{
		studentInfo *current, *prev;
		current = traverse->student;
		prev = current;
		value->student->email = email_generate(value->surname);
		
		// Kay�t ba�a eklenecekse.
		if (emailCompare(value->student->email, current->email) < 0)
		{ 
			current->previous = value->student;
			value->student->next = current;
			traverse->student = value->student;
			return;
		}

		// Ayn� mail de�ilken, t�m mailleri dola�.
		while (current && emailCompare(value->student->email, current->email) > 0)
		{
			prev = current;
			current = current->next;
		}

		// Maillerin sonuna geldiysek.
		if (current == NULL)
		{
			prev->next = value->student;
			value->student->previous = prev;
			value->student->next = NULL;
			return;
		}

		if (emailCompare(value->student->email, current->email) == 0)
		{
			int check = 0, no = 0;

			// Ayn� mail'den olup olmad���n� kontrol ediyorum.
			// Var ise yeni mail veriyorum.
			while (check != 1)  
			{  
				char *tempname = new char[strlen(value->student->name) + 1];
				strcpy(tempname, value->student->name);
				if (isTwoNamed(tempname))
				{
					char *t = tempname;
					tempname = concatenate(tempname);
					delete t;
				}
				value->student->email = email_update(value->student->surname, tempname, value->student->email, no);
				check = 1;
				studentInfo *p = traverse->student;

				// Atad���m mail o node'da var m� yok mu diye t�m node'u kontrol ediyorum.
				while (p)
				{
					// Varsa while'� bir daha d�nd�r�yorum.
					if (emailCompare(p->email, value->student->email) == 0)
					{
						check = 0;
						if (no != 0)
						{
							no++;
						}
						if (strlen(value->student->email) - 11 == strlen(tempname) + strlen(value->student->surname))
						{
							no = 2;
						}
						break;
					}
					p = p->next;
				}
				delete[] tempname;
			}

			// Maili ekleyece�im yere gidiyorum.
			while (current && emailCompare(value->student->email, current->email) > 0)
			{
				prev = current;
				current = current->next;
			}

			value->student->next = current;
			value->student->previous = prev;
			prev->next = value->student;
			if (current)
			{
				current->previous = value->student;
			}
			return;
		}

		// Ayn� mail yoksa, do�rudan ekliyorum.
		value->student->next = prev->next;
		value->student->previous = prev;
		prev->next = value->student;
		if (current)
		{
			current->previous = value->student;
		}
		
		return;
	}

	// Node yoksa
	else
	{
		value->student->email = email_generate(value->surname);
		value->next = traverse;
		tail->next = value;
	}
}

////// End of Add Function //////////


/////// Beginning of Print Function /////////

void List::printList()
{
	surnameNode* traverse;
	traverse = head;
	if (traverse == NULL)
	{
		cout << "There are no elements on the list." << endl;
		return;
	}

	int i = 1;
	cout << i << ". " << traverse->surname; 
	cout << "'s first element is  " << traverse->student->name;
	cout << " " << traverse->student->surname << "  " << endl;
	traverse = traverse->next;
	i++;
	while (traverse != head)
	{
		cout << i << ".  " << traverse->surname;
		cout << "'s first element is  " << traverse->student->name;
		cout << " " << traverse->student->surname << "  " << endl;
		traverse = traverse->next;
		i++;
	}
}

////// End of Print Function //////////


////// Beginning of Node Print Function //////////

void List::printSurnameNode(char *surname)
{
	if (head == NULL)
	{
		cout << "Unfortunately the list is empty :(" << endl;
		return;
	}

	surnameNode *traverse;
	traverse = head;
	if (strcmp(traverse->surname, surname) == 0) // �lk elemansa
	{
		cout << "The node '" << traverse->surname << "' contains:" << endl << endl;
		studentInfo *current;
		current = traverse->student;
		while (current)
		{
			cout << current->surname << "  " << current->name << "  " << current->email << endl;
			current = current->next;
		}
		return;
	}
	
	traverse = traverse->next;
	while (traverse != head && strcmp(traverse->surname, surname) != 0)
	{
		traverse = traverse->next;
	}

	if (traverse == head)
	{
		cout << "No such surname exists in the list." << endl;
		return;
	}

	cout << "The node '" << traverse->surname << "' contains:" << endl << endl;
	studentInfo *current;
	current = traverse->student;
	while (current)
	{
		cout << current->surname << "  " << current->name << "  " << current->email << endl;
		current = current->next;
	}
}

////// Beginning of Node Print Function //////////


/// Beginning of Create Function ///

void List::create()
{
	head = NULL;
	// create_check = 1;
}

/// End of Create Function ///

/// Beginning of Close Function ///

void List::close()
{
	makeEmpty();
}

/// End of Close Function ///


/// Beginning of Make Empty (Empty List) Function ///

void List::makeEmpty()
{
	if (head == NULL)
	{
		cout << "List is already empty." << endl;
		return;
	}

	surnameNode *traverse, *tail;
	traverse = head->next;
	tail = traverse;
	studentInfo *p, *q;

	while (traverse != head)
	{
		traverse = traverse->next;
		p = tail->student;
		q = p;
		while (p)
		{
			p = p->next;
			delete q;
			q = p;
		}
		delete tail;
		tail = traverse;
	}
	if (traverse)
	{
		delete traverse;
	}
	head = NULL;

}

/// End of Make Empty (Empty List) Function ///


/// Beginning of Delete Surname Node Function ///

void List::deleteSurnameNode(char* surname)
{
	surnameNode *traverse, *tail;
	traverse = head;
	tail = traverse;

	if (traverse == NULL)
	{
		cout << "The list is empty right now." << endl;
		return;
	}

	// �lk soyadsa.
	if (strcmp(traverse->surname, surname) == 0)
	{
		studentInfo *current = traverse->student;
		studentInfo *prev;
		prev = current;
		while (current)
		{
			current = current->next;
			delete prev;
			prev = current;
		}

		// Son elemana git.
		traverse = traverse->next; 
		while (traverse->next != head) 
		{
			traverse = traverse->next;
		}

		traverse->next = tail->next;
		if (tail->next == tail)
		{
			head = NULL;
			delete tail;
			return;
		}
		head = tail->next;
		delete tail;
		return;
	}

	// �lk soyad de�ilse.
	traverse = traverse->next;
	while (traverse != head && strcmp(traverse->surname, surname) != 0)
	{
		tail = traverse;
		traverse = traverse->next;
	}

	// Soyad yoksa
	if (traverse == head)
	{
		cout << "No such surname node exists." << endl;
		return;
	}

	// Bir soyad node'u bulunduysa
	studentInfo *current = traverse->student;
	studentInfo *prev;
	prev = current;
	while (current != NULL)
	{
		current = current->next;
		delete prev;
		prev = current;
	}
	tail->next = traverse->next;
	delete traverse;
}

/// End of Delete Surname Node Function ///


/// Beginning of Delete Student Function ///

void List::deleteStudent(char* name, char* surname, char* email)
{

	surnameNode *traverse, *tail;
	traverse = head;
	tail = traverse;
	
	if (traverse == NULL)
	{
		cout << "The list is empty right now." << endl;
		return;
	}

	// �lk soyadsa
	if (strcmp(traverse->surname, surname) == 0)
	{
		studentInfo *current;
		current = traverse->student;

		// Soyaddaki ilk kay�tsa
		if (strcmp(current->name, name) == 0 && strcmp(current->email, email) == 0)
		{
			if (current->previous == NULL && current->next == NULL)
			{ // �lk ve tek kay�tsa. (Soyad node'u da silinecekse)
				delete current;
				
				// Listenin tek eleman�ysa.
				if (traverse->next == traverse) 
				{
					head = NULL;
					delete traverse;
					return;
				}

				// Listede ba�ka elemanlar varsa tail listenin son eleman�na gider.
				while (tail->next != head)
				{
					tail = tail->next;
				}
				tail->next = traverse->next;
				head = traverse->next;
				delete traverse;
				return;
			}
			else
			{ // �lk kay�t ama tek kay�t de�ilse. (Soyad node'u silinmeyecekse)
				current->next->previous = NULL;
				traverse->student = current->next;
				delete current;
				return;
			}
		}

		// Adam� bulana kadar node'un i�inde ilerle.
		while (current)
		{
			if (strcmp(current->name, name) == 0)
			{
				if (strcmp(current->email, email) == 0)
				{
					break;
				}
			}
			current = current->next;
		}

		// �yle bir kay�t yoksa.
		if (current == NULL)
		{
			cout << "No record with such name and/or email exists." << endl;
			return;
		}

		// Kay�t bulunduysa.
		current->previous->next = current->next;
		if (current->next != NULL)
		{
			current->next->previous = current->previous;
		}

		delete current;
		return;
	}

	// Soyad� bulana kadar circular list'te gez
	traverse = traverse->next;

	while (traverse != head && strcmp(traverse->surname, surname) != 0)
	{
		tail = traverse;
		traverse = traverse->next;
	}

	// Soyad� bulamay�p ba�a d�nd�yse.
	if (traverse == head)
	{
		cout << "No such surname exists." << endl;
		return;
	}

	//// �lk kay�t d���nda bir kay�tta soyad node'unu bulduysak ////

	studentInfo *current;
	current = traverse->student;

	// Soyaddaki ilk adamsa
	if (strcmp(current->name, name) == 0 && strcmp(current->email, email) == 0)
	{
		if (current->previous == NULL && current->next == NULL)
		{ // �lk ve tek kay�tsa. (Soyad node'u da silinecekse)
			delete current;
			tail->next = traverse->next;
			delete traverse;
			return;
		}
		else
		{ // �lk kay�t ama tek kay�t de�ilse. (Soyad node'u da silinmeyecekse)
			current->next->previous = NULL;
			traverse->student = current->next;
			delete current;
			return;
		}
	}

	// Adam� bulana kadar node'un i�inde ilerle.
	while (current)
	{
		if (strcmp(current->name, name) == 0)
		{
			if (strcmp(current->email, email) == 0)
			{
				break;
			}
		}
		current = current->next;
	}

	// �yle bir kay�t yoksa.
	if (current == NULL)
	{
		cout << "No record with such name and/or exists." << endl;
		return;
	}

	// Kay�t bulunduysa.
	current->previous->next = current->next;
	if (current->next != NULL)
	{
		current->next->previous = current->previous;
	}

	delete current;
}

/// End of Delete Student Function ///


/// Beginning of Update Function ///

void List::update()
{
	if (head == NULL)
	{
		cout << "There aren't any values to be updated." << endl;
		return;
	}

	// Deleting the old record.
	char* name = new char[50];
	char* surname = new char[50];
	char* email = new char[50];
	cout << "Please enter the name of the student to be updated." << endl;
	cin.getline(name, 50, '\n');
	cout << "Please enter the surname of the student to be updated." << endl;
	cin.getline(surname, 50, '\n');
	cout << "Please enter the email of the student to be updated." << endl;
	cin.getline(email, 50, '\n');
	deleteStudent(name, surname, email);
	cout << "Old student has been deleted." << endl;
	delete name;
	delete surname;
	delete email;

	// Adding the new record.
	cout << "Please enter the new name and surname of the record. ";
	cout << "(Leave a tab after the name.)" << endl;
	surnameNode *t = new surnameNode;
	t = create_node();
	add(t);
	delete t->student->name;
	delete t->student->surname;
	delete t->student;
	delete t->surname;
	delete t;
}

/// End of Update Function ///

