//ruti tenenboim
//214360778
//mavo lemadaei amachshev
//week2 exe7
//read a three digit number and print the sum of the digit. 

#include<iostream>
using namespace std;
int main()
{
	cout << "enter a three digit number:" << endl;//print "enter a three digit number:" 
	int num,num1,num2,num3;//variable definition
	cin >> num;//read the two numbers
	num1 = num / 100;//find the first number
	num2 = num % 100 / 10;//find the second number
	num3 = num % 10;//find the third number
	cout << "the sum is: " << num1 + num2 + num3;//print the sum


	return 0;
}

//exemple:
//enter a three digit number :
//715
//the sum is : 13
