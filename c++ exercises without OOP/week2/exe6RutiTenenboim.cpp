//ruti tenenboim
//214360778
//mavo lemadaei amachshev
//week2 exe6
//read two numbers and print the essay, subtraction,multipliction and division between the numbers.

#include<iostream>
using namespace std;
int main()
{
	cout << "enter two numbers:" << endl;//print "enter two numbers:"
	int num1, num2;//variable definition
	cin >> num1 >> num2;//read the two numbers
	cout << num1<<"+"<<num2<<"="<<num1 + num2 << endl;//print the essay between the numbers
	cout << num1<<"-"<<num2<<"="<<num1 - num2 << endl;//print the subtraction between the numbers
	cout << num1<<"*"<<num2<<"="<<num1 * num2 << endl;//print the multiplication between the numbers
	cout << num1<<"/"<<num2<<"="<<(float)num1 / num2;//print the division between the numbers
	
	
	
	
	

	return 0;
}

//exemple:
//enter two numbers :
//7
//2
//7 + 2 = 9
//7 - 2 = 5
//7 * 2 = 14
//7 / 2 = 3.5
