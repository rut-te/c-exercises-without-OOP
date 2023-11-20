//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe3
//Reads 2 numbers. and reads char:+,-,*,/ , prints the calculation of the two
//numbers based on the char.

#include<iostream>
using namespace std;
enum CALCULATE { PLUS = 43, MINUS = 45,MULT=42,DIV=47};

int main()
{
	cout << "enter 2 number:"<<endl;
	int x,y;
	cin >> x >> y;
	cout << "enter an operator:"<<endl;
	char op;
	cin >> op;
	switch (op)//Use of switch, in order to check what is the character according to which the calculation will be printed.
	{
		case'+' : cout << x << "+" << y << "=" << x + y;//Printing with plus.
			break;
		case'-' : cout << x << "-" << y << "=" << x - y;//Printing with minus.
			break;
		case'*' : cout << x << "*" << y << "=" << x * y;//Printing with mult.
			break;
		case'/' : if(y) cout << x << "/" << y << "=" << (float)x / y;//Printing with div. 
			break;
		default : cout << "ERROR";
	}
	return 0;
}


//exemple:
//enter 2 number:
//10
//2
//enter an operator :
//	-
//	10 - 2 = 8

//enter 2 number:
//10
//2
//enter an operator :
//	+
//	10 + 2 = 12

//enter 2 number:
//10
//2
//enter an operator :
//	*
//	10 * 2 = 20

//enter 2 number:
//10
//4
//enter an operator :
//	/
//	10 / 4 = 2.5