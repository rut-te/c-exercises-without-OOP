//ruti tenenboim
//214360778
//mavo lemadaei amachshev
//week2 exe4
//read 2 numbers and print the result of an exercise with this numbers

#include<iostream>
using namespace std;
int main()
{
	cout << "enter two numbers:"<<endl;//print "enter two numbers:"
		float num1 , num2;//variable definition
		cin >> num1 >> num2;//read the two numbers
		float exe;//variable definition
		exe = (5 * num1 + 3) / (6 * num2 + 2);//calculate the given exercise
		cout << "c=" << exe;//print the result
	return 0;
}

//exemple:
// 
//enter two numbers :
//2
//0
//c = 6.5