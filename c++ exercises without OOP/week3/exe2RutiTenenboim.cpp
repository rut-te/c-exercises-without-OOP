//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe2
//Reads 3 numbers. First, last and number. If the number is between the first 
//and the last, print between. If the number is smaller than the first 
//prints smaller. If the number is bigger than the last one prints bigger one.

#include<iostream>
using namespace std;

int main()
{
	cout << "enter 3 numbers:" << endl;
	float first,last,number;
	cin >> first>>last>>number;
	if ((number >= first) && (number <= last))//Checking whether a number is between the first and the last.
		cout << "between";
	if (number < first)//Checking whether a number is smaller than the first one.
		cout << "smaller";
	if (number > last)//Checking whether a number is greater than the last one.
		cout << "bigger";
	return 0;
}


//exemple:
//enter 3 numbers:
//3
//9
//7
//between

//enter 3 numbers:
//3
//9
//1
//smaller

//enter 3 numbers:
//3
//9
//11
//bigger