//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe1
//Reads a two-digit number. If the two digits are even print even digits only,
// and prints the multiplication of the digits. If the two digits are odd,
// prints odd digits only, and the sum of the digits. 
//If mixed prints print mixed number, if the input is incorrect prints error.

#include<iostream>
using namespace std;

int main()
{
	cout << "enter a number:" << endl;
	int num;
	cin >> num;
	if (num <=0 || num>=100)//Input integrity check.
		cout << "Error";
	else
	{
		if (num / 10 % 2 && num % 10 % 2)//Checking whether the two numbers are odd.

		{
			cout << "odd digits only" << endl;
			cout << num / 10 + num % 10;//Print the result of adding the numbers.
		}

		else
		{
			if (!(num / 10 % 2) && !(num % 10 % 2))//Checking whether the two numbers are even.
			{
				cout << "even digits only" << endl;
				cout << (num / 10) * (num % 10);//Print the result of the multiplication between the two numbers
			}


			else
			cout << "mixed number";//Print that one number is even and the other is odd
		}

	}
	return 0;
}


//exemple:
//enter a number :
//19
//odd digits only
//10

//enter a number :
//28
//even digits only
//16

//enter a number :
//16
//mixed number