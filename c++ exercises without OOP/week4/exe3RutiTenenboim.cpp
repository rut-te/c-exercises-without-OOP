//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe3
//A program that takes a non-negative integer-N and prints the Fibonacci sequence
//up to the term in the Nth place.
#include<iostream>
using namespace std;

int main()
{
	cout << "enter a number:" << endl;
	int n;
	cin >> n;
	while (n < 0)//input integrity check
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	int sum, num1 = 0, num2 = 1;
	cout << num1 << " " << num2 << " ";//Printing the first two numbers which are 0 and 1.
	int i = 0;
	while (i < n-1)//A loop that calculates the next numbers in the series.
	{
		sum = num1 + num2;//Calculation of the sum.
		cout << sum<<" ";
		num1 = num2;//Placement in a variable num1.
		num2 = sum;//Placement in a variable num2.
		i++;//The promotion of the i.
		
	}

	return 0;
}


//exemple:
//enter a number :
//9
//0 1 1 2 3 5 8 13 21 34

//enter a number :
//-10
//ERROR
//1
//0 1