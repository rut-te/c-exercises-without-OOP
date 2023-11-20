//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week6 Exe5
//one-dimensional arrays.
//The program defines an array of integers of size 6. and receives the numbers. 
//The program then defines another array that takes integers of size 6 and receives
//the numbers. After that, the program defines a new array named difference which is
//a symmetrical difference between the set of numbers contained in the first array 
//and the set of numbers contained in the second array. The program must print the 
//members of the array difference. 
//If the array difference is empty, the program must print empty.

#include<iostream>
using namespace std;

int main()
{
	int set1[6];//Array definition.
	cout << "enter first 6 numbers:" << endl;
	for (int i = 0; i < 6; i++)//The reception of the members of the array.
	{
		cin >> set1[i];
		if (set1[i] <= 0)//Input integrity check.
		{
			cout << "ERROR" << endl;
			cin >> set1[i];
		}
	}
	int set2[6];//Array definition.
	cout << "enter next 6 numbers:" << endl;
	for (int i = 0; i < 6; i++)//The reception of the members of the array.
	{
		cin >> set2[i];
		if (set2[i] <= 0)//Input integrity check.
		{
			cout << "ERROR" << endl;
			cin >> set2[i];
		}
	}
	int difference[6]={0};//Defining an array, and resetting all its members.
	for (int i = 0,k=0; i < 6; i++,k++)//Go through all the members of the array set1.
	{
		bool flag = true;//Setting a flag variable that marked true.
		for (int j = 0; j < 6; j++)//Go through all the members of the array set2.
		{
			if (set1[i] == set2[j])//Checking whether there is a set1 number that also has the same set2.
				flag = false;//If so, making the sign false.
		}
		if (flag)//If flag equals true, put the number that will change only in set1 in the difference array.
			difference[k] = set1[i];
	}
	cout << "set difference is:" << endl;
	if (difference[0] == 0)//If all members are zero, that is, the array is empty, print empty.
		cout << "empty" << endl;
	else
	{
		for (int i = 0; i < 6; i++)//Print loop.
		{
			if (difference[i] != 0)//Print only if the term is not equal to zero.
				cout << difference[i] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}

//exemple:
//enter first 6 numbers:
//10
//1
//7
//5
//9
//3
//enter next 6 numbers:
//2
//5
//4
//3
//6
//1
//set difference is :
//10 7 9

//enter first 6 numbers:
//10
//9
//7
//5
//3
//1
//enter next 6 numbers:
//9
//3
//5
//1
//7
//10
//set difference is :
//empty

