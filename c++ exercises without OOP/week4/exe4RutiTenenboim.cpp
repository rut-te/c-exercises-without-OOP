//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe4
//A program that reads two numbers-X and N, and calculates the sum of a given
//series based on them.
#include<iostream>
using namespace std;

int main()
{
	float x;
	int n;
	cout << "enter 2 numbers:" << endl;
	cin >> x>>n;
	while (n < 0)//input integrity check
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	int i = 0,j=-1;
	float sum = 0,num=0;
	int numer = -1, denom = 0, power = x;
	while (i <n)//Calculation of the terms in the series and their sum.
	{
		numer *= -1;//Calculate the numerator.
		denom += (j + 2);//Calculate the denominator.
		num = (float) numer / denom * power;//Calculation of the term in the series.
		sum += num;//Calculate the sum.
		i++;//The promotion of the i.
		j++;//The promotion of the j.
		power *= x * x;//The promotion of the power.
	}
	cout <<sum<< endl;//print of the final sum.

	return 0;
}


//exemple:
//enter 2 numbers:
//3
//2
//- 6

//enter 2 numbers:
//3
//- 2
//ERROR
//- 42
//ERROR
//2
//- 6