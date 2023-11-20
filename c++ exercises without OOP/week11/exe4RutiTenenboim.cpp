////Ruti Tenenboim 214360778
////Mavo Lemadaei Hamachshev.
////Week11 Exe4
////Recursion
////The program receives a number from the user and assigns an array in size, 
////and also receives the members of the array. The program switches between
////the members of the array, between the first and the last, between the second
////and the one before the last, and so on. The program then prints the array.
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//void swap(int a[], int, int);//Defining a function that switches between 2 elements in an array
//void reverse(int*, int);//Defining a function that transforms the members of the array it accepts
//int main()
//{
//	int* arr;
//	int num;
//	cout << "Enter a number: ";
//	cin >> num;//Receiving the number of members in the array
//	arr = new int[num];//Allocation of a dynamic array according to the size entered by the user
//	cout << "Enter array values: ";
//	for (int i = 0; i < num; i++)//The reception of the members of the array
//		cin >> arr[i];
//	cout << "Before: \n";//Printing the array before sorting
//	for (int i = 0; i < num; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//	reverse(arr, num);//A call to a function that transforms the members of the array, and sends it an array and its size
//	cout << "After: \n";//Printing the array after sorting
//	for (int i = 0; i < num; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//	delete [] arr;//The release of the dynamic allocation of the array
//	return 0;
//}
//void swap(int a[], int i, int j)//Using the function given in the question which switches between 2 elements in the array
//{
//	int temp = a[i];
//	a[i] = a[j];
//	a[j] = temp;
//}
//void reverse(int*a, int num)//Defining a function that transforms the members of the array it accepts
//{
//	if (num > 1)//Stopping conditions - when the number of elements in the array is less than 1
//	{
//		reverse(a + 1, num - 2);//Recursively calling the function for the smaller problem - swapping the terms between the first and last terms
//		swap(a, 0, num - 1); //Exchange between the first place and the last place in the array
//	}
//}
//
////exemple:
////Enter a number : 6
////Enter array values : 1 2 3 4 5 6
////Before :
////1 2 3 4 5 6
////After :
////6 5 4 3 2 1
//
