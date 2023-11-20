//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week5 Exe2
// Function.
//The program takes a number and prints the integers smaller than that number. 
//as well as the perfect numbers less than five hundred.

#include<iostream>
using namespace std;

bool perfect(int);//Declaration of the function that checks whether the number is perfect.
void printPerfect(int num=500);//Declaring the function that prints all integers less than the given number.
int main()
{
	cout << "enter a number " << endl;
	int num;
	cin >> num;
	while (num < 0)//Input integrity check.
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	printPerfect(num);//Executing the function for the number received from the user.
	cout <<endl;
	printPerfect();//Executing the function for the default number.
	
	return 0;
}
bool perfect(int num)
{
	bool flag = true;//Setting a variable that signifies correctness.
	int i = 1, sum = 0;
	while (i <num)//Calculation to check if the number is perfect.
	{
		if (num % i==0)
			sum += i;
		i++;
	}
		if (sum != num)//Making the sign false in case the number is not perfect.
			flag = false;
		return flag;
}
void printPerfect(int num)
{
	for (int i = 6; i < num; i++)//Print all integers less than the given number.
	{
		if (perfect(i))
			cout << i << " ";
	}
}

//exemple:
//enter a number
//445
//6 28
//6 28 496

//enter a number
//3
//
//6 28 496

//enter a number
//- 50
//ERROR
//- 3
//ERROR
//7
//6
//6 28 496