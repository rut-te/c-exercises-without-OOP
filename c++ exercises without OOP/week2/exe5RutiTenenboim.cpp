//ruti tenenboim
//214360778
//mavo lemadaei amachshev
//week2 exe5
//read 2 numbers, print them, change between them and print again.

#include<iostream>
using namespace std;
int main()
{
	cout << "enter two numbers:" << endl;//print "enter two numbers:"
	int x, y;//variable definition
	cin >> x >> y;//read the two numbers
	cout << "x=" << x << " ,y=" << y << endl;//print x and y
	int help;//variable definition for help
	help = x;//placement in help
	x = y;//changing of the variable
	y = help;//changing of the variable
	cout << "x=" << x << " ,y=" << y << endl;//print x and y
	
	return 0;
}

//exemple:
//enter two numbers:
//3
//5
//x = 3, y = 5
//x = 5, y = 3



