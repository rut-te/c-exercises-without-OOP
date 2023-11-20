//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week8 Exe2
//pointers
//The plan defines an array of classrooms with a projector. Click 0 to add a class
//1 click to remove a class. Click 2 to search if a certain class exists in the 
//array. By clicking 3, print according to floor code. Pressing 4 prints all the 
//classes in the array. Press 5 to exit the program.

#include<iostream>
#include <algorithm>
using namespace std;
enum CHOISE{ADD,DEL,SEARCH,PRINT_SPE,PRINT_ALL,EXIT};
void newClass(int *database, int& size, int newCode);//Class add function declaration
void delClass(int *database, int& size, int delCode);//Declaring a class delete function
void printAll(int *database, int size);//Declare the print all classes function
int searchClass(int *database, int size, int speClass);//Declaration of a particular class search function
void printCode(int *database, int size, int code);//Declaration of print function by floor code

int main()
{
	int database[50] = {};//Defining the array of classrooms with a projector
	cout << "Enter 0 to add a new classroom." << endl;
	cout << "Enter 1 to delete a classroom." << endl;
	cout << "Enter 2 to search for a specific classroom." << endl;
	cout << "Enter 3 to print all the classrooms for a specific floor." << endl;
	cout << "Enter 4 to print all the classrooms." << endl;
	cout << "Enter 5 to exit." << endl;
	cout << "Enter your choice :";
	int choise = 0;
	int sizeData = 0;
	int code = 0, help;
	while (choise != 5)
	{
		cin >> choise;
		while (choise < 0 || choise>5)//Input integrity check
		{
			cout << "ERROR" << endl;
			cin >> choise;
		}
		switch (choise)
		{
		case ADD:
			int newCode;
			cout << "Enter the code of the classroom to add:" << endl;
			cin >> newCode;
			help = (newCode / 1000);
			while(newCode >= 100000 || newCode <= 10000||(help % 10) != (help / 10))//Input integrity check
			{
				cout << "ERROR" << endl;
				cin >> newCode;
				help = (newCode / 1000);
			}
			newClass(database, sizeData, newCode);
			printAll(database, sizeData);
			break;
		case DEL:
			cout << "Enter the code of the classroom to delete:" << endl;
			cin >> code;
			help = (code / 1000);
			while (code >= 100000 || code <= 10000 || (help % 10) != (help / 10))//Input integrity check
			{
				cout << "ERROR" << endl;
				cin >> code;
				help = (code / 1000);
			}
			delClass(database, sizeData, code);
			printAll(database, sizeData);
			break;
		case SEARCH:
			cout << "Enter the code of the classroom to search for:" << endl;
			cin >> code;
			help = (code / 1000);
			while (code >= 100000 || code <= 10000 )//Input integrity check
			{
				cout << "ERROR" << endl;
				cin >> code;
				help = (code / 1000);
			}
			help=searchClass(database, sizeData, code);
			if (help == NULL)
				cout << "Not found" << endl;
			else
				cout << "found" << endl;
			break;
		case PRINT_SPE:
			cout << "Enter the code of the floor:" << endl;
			cin >> code;
			while (code >= 100 || code < 10 || (code / 10) != (code % 10))//Input integrity check
			{
				cout << "ERROR" << endl;
				cin >> code;
			}
			printCode(database, sizeData, code);
			break;
		case PRINT_ALL:
			printAll(database, sizeData);
			break;
		case EXIT:
			break;
		}
		if (choise != 5)
			cout << "Enter your next choice:";
	}
	
	return 0;
}
void newClass(int *database, int& size, int newCode)//A function was added to the class
{
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (*(database+i) == newCode)
			flag = false;
	}
		if (flag)
		{
			*(database+size) = newCode;
			size++;
			sort(database, database + size);//Array sorting
		}
	
}
void delClass(int *database, int& size, int delCode)//Class delete function
{
	int i = 0;
	for (; i < size; i++)
	{
		if (*(database+i) == delCode)
				*(database+i) = 0;
	}
	while (i < (size-1))
	{
		*(database+i) = *(database+(i + 1));
	}
}
void printAll(int *database, int size)//All classes print function
{
	for (int i = 0; i < size; i++)
	{
		if(*(database+i) != 0)
			cout << *(database+i) << endl;
	}
}
int searchClass(int *database, int size, int speClass)//A particular class search function
{
	for (int i = 0; i < size; i++)
	{
		if (*(database+i) == speClass)
			return 1;
	}
	return NULL;
}
void printCode(int *database, int size, int code)//Print function by floor code
{
	for (int i = 0; i < size; i++)
	{
		if ((*(database+i) / 1000) == code)
		{
			cout << *(database+i) << " ";
			}
	}
	cout << endl;
}

//exemple:
//Enter 0 to add a new classroom.
//Enter 1 to delete a classroom.
//Enter 2 to search for a specific classroom.
//Enter 3 to print all the classrooms for a specific floor.
//Enter 4 to print all the classrooms.
//Enter 5 to exit.
//Enter your choice :
//0
//Enter the code of the classroom to add :
//11111
//11111
//Enter your next choice :
//0
//Enter the code of the classroom to add :
//44444
//11111
//44444
//Enter your next choice :
//0
//Enter the code of the classroom to add :
//33333
//11111
//33333
//44444
//Enter your next choice :
//0
//Enter the code of the classroom to add :
//33555
//11111
//33333
//33555
//44444
//Enter your next choice :
//3
//Enter the code of the floor :
//33
//33333 33555 
// Enter your next choice :
//4
//11111
//33333
//33555
//44444
//Enter your next choice :
//2
//Enter the code of the classroom to search for :
//	65656
//	Not found
//	Enter your next choice :
//2
//Enter the code of the classroom to search for :
//	11111
//	found
//	Enter your next choice :
//1
//Enter the code of the classroom to delete :
//	33555
//	11111
//	33333
//	44444
//	Enter your next choice :
//0
//Enter the code of the classroom to add :
//22222
//11111
//22222
//33333
//44444
//Enter your next choice :
//3
//Enter the code of the floor :
//5555
//ERROR
//55
//Enter your next choice :
//1
//Enter the code of the classroom to delete :
//	33333
//	11111
//	22222
//	44444
//	Enter your next choice :
//1
//Enter the code of the classroom to delete :
//	33333
//	11111
//	22222
//	44444
//	Enter your next choice :
//4
//11111
//22222
//44444
//Enter your next choice :
//5

