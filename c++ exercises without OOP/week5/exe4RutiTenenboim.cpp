//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week5 Exe4
//Functions
//The program receives a number from the user. If the number is positive, the program
//  will calculate and print the size of the hash table as the initial number
//The closest(equal to or greater) to the entered number.
//If the number is negative or zero, the program will hash a number between 
//10 and 100 and print the hash table as the prime number closest to the drawn number.

#include<iostream>
#include<ctime>
using namespace std;

bool isPrime(int);//Declaration of the function that checks whether the number is prime.
int findPrime(int);//Declaration of the function that calculates the size of the hash table.
int main()
{
	cout << "enter number of values: " << endl;
	float num;
	cin >> num;
	cout << "table size: ";
	if (num > 0)//Print if the entered number is positive.
		cout << findPrime(num) << endl;
	else//Print in case the entered number is negative or zero.
	{
		srand((unsigned)time(NULL));
		num = rand() % (100 - 10 + 1) + 10;
		cout << findPrime(num) << endl;
	}
	return 0;
}
bool isPrime(int num)
{
	bool flag = true;//Setting a variable that signifies correctness.
	for (int i = 2; i < num; i++)//Checking whether the number is prime.
	{
		if (num % i == 0)//Changing the flag variable to false in case the number is not prime.
			flag = false;
	}
	return flag;
}
int findPrime(int num)
{
	if (isPrime(num))//Placement in case the entered number is prime.
		num= num;
	else//Placement in case the entered number is not prime.
	{
		while (!isPrime(num))
			num++;
	}

	return num ;
}

//exemple:
//enter number of values :
//11
//table size : 11

//enter number of values :
//25
//table size : 29

//enter number of values :
//-1
//table size : 43

