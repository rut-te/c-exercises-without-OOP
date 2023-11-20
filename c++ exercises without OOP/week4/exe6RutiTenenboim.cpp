//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe6
//The program takes in a positive whole number and checks whether each digit in
// the number is less than one of the digits to the left.
//If yes it is printed yes, if not it is printed no.

#include<iostream>
using namespace std;

int main()
{
	cout << "enter a number:" << endl;
	int num;
	bool flag = true;
	cin >> num;
	while (num < 1)//input integrity check
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	int n1, n2;
	while (num / 10)//A loop that continues as long as the number is not single digit
	{
		n1 = num % 10;//Finding the first number on the right
		n2 = (num / 10 )% 10;//Finding the second number on the right
		if (!(n1 == n2 - 1))//Checking whether the first number on the right is not one less than the second number
			flag = false;
		num = num / 10;//Divide the number by ten to get to the next digit.
	}
	if (flag)
		cout << "YES" << endl;//print YES if flag is true
	else
		cout << "NO" << endl;//print NO if flag is false

	return 0;
}


//exemple:
//enter a number :
//1234
//NO

//enter a number :
//5432
//YES

//enter a number :
//5
//YES

//enter a number :
//8743
//NO