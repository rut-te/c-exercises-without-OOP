//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe5
//A program that reads a single-digit, positive number, and prints a right-angled
//triangle so that N digits are printed in the first line, N-1 in the second line,
//and so on...

#include<iostream>
using namespace std;

int main()
{
	cout << "enter a one digit number:" << endl;
	int n;
	cin >> n;
	while (n < 1 || n>9)//input integrity check
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	int i = 0,j=0,help=n;
	for (; i < n; i++)//A loop that calculates the rows.
	{
		for (j=0; j < 2 * i; j++)//A loop that calculates the spaces at the beginning of each row.
			cout << " ";
		for (j=help;  j>1; j--)//A loop that calculates the numbers and commas to be printed on each line.
		{
			cout << j << ",";
		}
		help--;//Subtraction from the help variable, in order to start the next holocaust with a number lower than one.
		cout <<"1"<< endl;//Printing the number one at the end of each line.
	}


	return 0;
}


//exemple:
//enter a one digit number :
//4
//4, 3, 2, 1
//   3, 2, 1
//      2, 1
//         1

//enter a one digit number :
//2
//2, 1
//   1

