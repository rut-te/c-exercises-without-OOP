//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week5 Exe3
//Functions.
//The program receives the first eight digits of an identity number and 
//calculates the ninth digit - the check digit of the identity number.

#include<iostream>
using namespace std;

int sumDigit(int);//Declaration of a function that calculates and returns the sum of the digits of a given number.
int lastDigitID(int);//Declaration of a function that calculates and returns the check digit of an identity number.
int main()
{
	cout << "enter your ID :" << endl;
	int num;
	cin >> num;
	while (num / 10000000 < 0 || num / 10000000 > 10)//Input integrity check.
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	cout << "your full ID is:" << endl;
	cout <<num<< lastDigitID(num)<<endl;
	return 0;
}
int sumDigit(int num)
{
	int sum = 0,help;
	while (num / 10 > 0)//Calculation of the sum of the digits of the number.
	{
		help=num % 10;//Calculating the first digit on the right, and waiting in a help variable.
		sum +=help;//Calculation of the sum of the numbers.
		num/=10;//Move to the next digit.
	}
	sum += num;//Calculate the final amount by adding the last number to the amount received so far.
	return sum;
}
int lastDigitID(int num)
{
	int value = 1,lastSum=0, unity,checkDigit,help,count=0,m;//Setting Variables.
	while (num / 10 > 0)//Separating the eight digits of the identity card, and starting the calculation of the check digit.
	{
		if (value == 1)//Finding the appropriate value for each digit.
			value = 2;
		else
			value = 1;
		help = num%10 * value;//Multiplying the digit by its corresponding value.
		lastSum+=sumDigit(help);//Calculation of the sum of the digits of the result.
		num /= 10;//Move to the next digit.
	}
	if (value == 2)//Adding the last number on the right to the total, as well as adding the number one before the last on the right to the total if the last number on the right is zero.
		lastSum += num;
	else
		lastSum += sumDigit(num * 2);
		
	unity=lastSum % 10;//Separation of the unity number from the sum.
	if (unity == 0)//Finding the check digit.(including paying attention to the possibility that the unity number is zero)
		checkDigit = 0;
	else
		checkDigit = 10 - unity;
	return checkDigit;
}

//exemple
//enter your ID :
//12345678
//your full ID is :
//123456782

