//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week6 Exe3
//one-dimensional arrays.
//The program defines an array of integers of size 100. The program takes the
//members of the array until the value 0 is obtained. The program updates the array 
//so that each number appears in it only once. The number that will remain in the
//array will be the first occurrence of this value in the array 
//(out of all occurrences). The deletion of the repeating numbers will be performed
//by calling a VOID type function. The program then prints the updated array, 
//and the number of members in it.

#include<iostream>
using namespace std;

void func (int* arr, int size);//Declaring a function of type VOID.
int main()
{
	int arr[100]={0};//Defining an array with 100 members, and resetting all members to 0.
	cout << "enter up to 100 values, to stop enter 0:" << endl;
	for (int i = 0; i < 100; i++)//Receiving the members of the array, and stopping the reception when the number is zero.
	{
		cin >> arr[i];
		if (arr[i] == 0)
			break;
	}
	int counter = 0;//Defining a variable that counts the number of members in the updated array.
	func(arr, 100);//call to function func.
	cout << "the new vector is: " << endl;
	for (int i = 0; i < 100; i++)//Going over the members of the new formation.
	{
		if (arr[i] != 0)//In case a member is not equal to zero, printing it and adding 1 to the counter variable.
		{
			cout << arr[i] << " ";
			counter++;
		}
	}
	cout << endl;
	cout << "number of elements: " << counter;
	cout << endl;

	return 0;
}
void func(int* arr, int size)//A function that deletes the elements that are repeated in the array.
{
	for (int i = 0; i < 100; i++)//Over all the members of the array.
	{
		for (int j = 0; j < 100; j++)//Checking whether there are repeating numbers.
		{
			if (arr[i] == arr[j])//Checking whether the repeating number is not in the same position in the array, meaning that it is not the same element.
			{
				if (i != j)//If this is not the same term, and the number repeats itself, turning the term that appears second to 0.
					arr[j] = 0;
			}
		}
	}
}

//exemple:
//enter up to 100 values, to stop enter 0:
//1
//5
//8
//9
//5
//4
//1
//2
//3
//5
//1
//4
//8
//9
//6
//5
//0
//the new vector is :
//1 5 8 9 4 2 3 6
//number of elements : 8