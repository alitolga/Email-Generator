/* dincer15
 * Student Name: Ali Tolga Dinçer
 * Student ID : 150150730
 * Date: 24.10.2017
 */

/*

This is my humble e-mail assigner program.
It takes the inputs from the file named "newStudentsList.txt" and writes the output to the file "emailList.txt".
Enjoy!

P.S. I used strcmp so the search and list functions are case sensitive.

Also the list is not created when you first start to program. So if you try to run any function without
first creating the list, head will not be equal to NULL and you'll probably get an access violation error.

*/

#include "List.h"
#include "Functions.h"
#include <iostream>
#include <cstring>

using namespace std;

void printMenu();
void perform_operation(char &mode, List &surnameMap);

int main()
{
	List surnameMap;
	char mode = '0';
	while (mode != 'T' && mode != 't')
	{
		printMenu();
		cin >> mode;
		perform_operation(mode, surnameMap);		
	}
	
	//system("PAUSE");

	return 0;
}

void printMenu()
{
	cout << "Please choose an option" << endl << endl;
	cout << "C: Create list" << endl;
	cout << "I: Insert all from file" << endl;
	cout << "W: Write all to file" << endl;
	cout << "A: Add record" << endl;
	cout << "R: Remove surname" << endl;
	cout << "D: Delete student" << endl;
	cout << "P: Print list" << endl;
	cout << "S: Show surname node" << endl;
	cout << "U: Update student" << endl;
	cout << "E: Empty list" << endl;
	cout << "T: Terminate program" << endl;
}

void perform_operation(char &mode, List &surnameMap)
{
	surnameNode* temp;
	char *name, *surname, *email;
	char choice;

	switch (mode)
	{
		case 'c': case 'C':
			surnameMap.create();
			break;

		case 'I': case 'i':
			surnameMap.readFromFile();
			break;

		case 'W': case 'w':
			surnameMap.writeToFile();
			break;

		case 'a': case 'A':
			cin.ignore(1000, '\n');
			cout << "Please enter the name and surname of the record. ";
			cout << "(Leave a tab after the name.)" << endl;
			temp = create_node();
			surnameMap.add(temp);
			delete temp->surname;
			delete temp->student->name;
			delete temp->student->surname;
			delete temp->student;
			delete temp;
			break;

		case 'r': case 'R':
			cin.ignore(1000, '\n');
			surname = new char[50];
			cout << "Please enter the surname you want to remove entirely." << endl;
			cin >> surname;
			surnameMap.deleteSurnameNode(surname);
			// cout << "Surname has been deleted." << endl;
			delete surname;
			break;

		case 'd': case 'D':
			name = new char[50];
			surname = new char[50];
			email = new char[50];
			cin.ignore(1000, '\n');
			cout << "Please enter the name of the student." << endl;
			cin.getline(name, 50, '\n');
			cout << "Please enter the surname of the student." << endl;
			cin.getline(surname, 50, '\n');
			cout << "Please enter the email of the student." << endl;
			cin.getline(email, 50, '\n');
			surnameMap.deleteStudent(name, surname, email);
			// cout << "Student has been deleted." << endl;
			delete name;
			delete surname;
			delete email;
			break;

		case 'p': case 'P':
			surnameMap.printList();
			break;

		case 's': case 'S':
			surname = new char[50];
			cin.ignore(1000, '\n');
			cout << "Please enter the surname you want to list." << endl;
			cin >> surname;
			surnameMap.printSurnameNode(surname);
			delete surname;
			break;

		case 'u': case 'U':
			cin.ignore(1000, '\n');
			surnameMap.update();
			break;

		case 'e': case 'E':
			surnameMap.makeEmpty();
			break;

		case 't': case 'T':
			cout << "All unsaved data will be lost." << endl;
			cout << "Are you sure you want to terminate the program? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				cout << "Clearing list." << endl;
				surnameMap.makeEmpty();
				break;
			}
			mode = '0';
			break;
	}

}
