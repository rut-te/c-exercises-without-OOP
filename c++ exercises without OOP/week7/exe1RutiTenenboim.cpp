//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week7 Exe1
//Two-dimensional arrays and algorithms: search, sorting and merging
//The program defines a function that receives from the main function a one-dimensional array of numbers sorted in ascending order,
//as well as a positive integer. The function looks for the received number in the array, and returns the index value of the number
//in the array. If the number does not exist, the function returns -1. The main function prints -not found, 
//in case the number does not exist. If the number exists, it prints the number and the index where it is in the array.

#include<iostream>
using namespace std;
const int SIZE = 10;//Defining a constant variable that expresses the size of the array
int binarySearch(int arr[], int size, int num);//Declaration of the determining function.
int main()
{
	int arr[SIZE];//Array definition
	cout << "enter 10 numbers:" << endl;
	cin >> arr[0];//Receiving the first number in the array
	bool flag = true;
	int i;
	while (flag)//Receiving the numbers in the array, including checking input integrity.
	{
		for (i = 1; i < SIZE; i++)
		{
			cin >> arr[i];
			if (arr[i] < arr[i - 1])
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			cout << "ERROR" << endl;
			cin >> arr[0];
			i = 1;
			flag = true;
		}
		else
			flag = false;
	}
	int num;
	cout << "enter 1 number:" << endl;
	cin >> num;//Receiving the number you are looking for in the array
	int help;
	help=binarySearch(arr, SIZE, num);//Calling the numbering function and saving what it returns in a help variable.
	if (help == -1)//Print the answer whether the number is found or not.
		cout << "no found" << endl;
	else
		cout << "the number " << num << " was found at index "<< help<<endl;
	return 0;
}
int binarySearch(int arr[], int size, int num)//A function that sorts the array according to binary sorting
{
	int start = 0,end = size - 1;
	while(start<=end)
	{
		int mid = (start + end) / 2;
		int n = arr[mid];
		if (num==n)
			return mid;
		if (num<n)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

//exemple:
//enter 10 numbers:
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10
//enter 1 number:
//3
//the number 3 was found at index 2

//enter 10 numbers:
//1
//2
//3
//5
//4
//ERROR
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10
//enter 1 number:
//5
//the number 5 was found at index 4

