//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week11 Exe3
//Recursion
//The program receives a number from the user and assigns an array in size, 
//and also receives the members of the array. The program prints the array, 
//then sorts it in non-descending order by selection sort and prints again.

#include <iostream>
#include <cstring>
using namespace std;
void swap(int arr[], int, int);//Defining a function that switches between 2 elements in an array
int smallest(int*, int);//Defining a function that returns the index of the smallest number in the array
void sort(int*, int);//Defining a function that sorts the array in non-descending order according to the choice sort principle.
int main()
{
	int* arr;
	int num;
	do {
		cout << "Enter a number:" << endl;
		cin >> num;//Receiving the number of members in the array
		if (num <= 0)
			cout << "ERROR" << endl;//Input integrity check
	} while (num <= 0);
	arr = new int[num];//Allocation of a dynamic array according to the size entered by the user
	cout << "Enter array values: ";
	for (int i = 0; i < num; i++)//The reception of the members of the array
		cin >> arr[i];
	cout << "Before: \n";
	for (int i = 0; i < num; i++)//Printing the array before sorting
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);//Calling the numbering function and sending it the array and its size
	cout << "After: \n";//Printing the array after sorting
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete [] arr;//The release of the dynamic allocation of the array
	return 0;
}
void swap(int arr[], int i, int j)//Using the function given in the question which switches between 2 elements in the array
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int smallest(int* arr, int num)//Using the function I wrote in question 2 - which returns the index of the smallest number in the array
{
	if (num == 0 || num == 1)
		return 0;

	int ans = smallest(arr, (num - 1));
	if (arr[num - 1] < arr[ans])
		return num - 1;
	return ans;

}
void sort(int*arr, int num)//function that sorts the array in non-descending order according to the choice sort principle.
{
	if (num > 1)//Stopping conditions - when the number of elements in the array is less than 1
	{
		swap(arr, 0, smallest(arr, num));//Finding the smallest element and replacing it with the first element in the array
		sort(arr+1, num-1);//Recursive call to the current function to sort the rest of the array members
	}
}

//exemple:
//Enter a number :
//4
//Enter array values : 3 2 5 1
//Before :
//3 2 5 1
//After :
//1 2 3 5

//Enter a number :
//6
//Enter array values : 2 5 7 5 3 1
//Before :
//2 5 7 5 3 1
//After :
//1 2 3 5 5 7

