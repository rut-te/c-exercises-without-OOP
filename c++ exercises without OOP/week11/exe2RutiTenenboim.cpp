//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week11 Exe2
//Recursion
//The program receives a number from the user and assigns an array the size of
//the number and also receives the members of the array. The program then prints
//the smallest number in the array.

#include <iostream>
#include <cstring>
using namespace std;
int smallest(int* arr, int);//Defining a function that returns the index of the smallest number in the array.
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
	cout << "The smallest is: " << arr[smallest(arr, num)] <<
		endl;//Calling the function that returns the index of the smallest number in the array, and printing the number found in the aforementioned index.
	delete[] arr;//The release of the dynamic allocation of the array
	return 0;
}
int smallest(int*arr, int num) //function that returns the index of the smallest number in the array.
{
	if (num == 0 || num == 1)//Stopping condition, when the size of the array is 1 or 0
		return 0;
	
	int ans= smallest(arr, (num - 1));//Recursively calling the function for the smaller problem and saving the returned value in the ans variable
	if (arr[num-1] < arr[ans])//Completing the condition for the original problem - checking the last place in the array
		return num-1;//If the last place is the smallest - returning its index
	return ans;//Otherwise - returning the index found to be the smallest by the recursive reading
	
}

//exemple:
//Enter a number :
//6
//Enter array values : 2 4 5 1 5 6
//The smallest is : 1
