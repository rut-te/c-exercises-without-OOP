//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe2
//A program that accepts two integers and positives. And then you pick up a list
//of numbers, until one of the given conditions is met - *The sum of the numbers
//is greater than the first number. *The amount of numbers is equal to the second
//number. The program then prints the sum of the numbers.

#include<iostream>
using namespace std;

int main()
{
	cout << "enter 2 positive numbers:" << endl;
	int num1, num2;
	cin >> num1;
	while (num1 < 0)//input integrity check
	{
		cout << "ERROR"<<endl;
		cin >> num1;
	}
	cin >> num2;
	while (num2 < 0)//input integrity check
	{
		cout << "ERROR"<<endl;
		cin >> num2;
	}
	cout << "enter a list of numbers:" << endl;
	int num,sum=0,count=1;
	cin >> num;
	sum += num;//calculate of the sum.
	while (sum <= num1 && count != num2)//A loop that continues as long as the given conditions are met.
	{
		
		cin >> num;
		count++;//The promotion of the counter.
		sum+= num;//The promotion of the sum.

	}
	cout<<sum<< endl;

	return 0;
}


//exemple:
// 
//enter 2 positive numbers :
//25
//2
//enter a list of numbers :
//9
//8
//17

//enter 2 positive numbers :
//25
//12
//enter a list of numbers :
//9
//8
//7
//6
//30



//enter 2 positive numbers :
//-25
//ERROR
//- 10
//ERROR
//25
//- 2
//ERROR
//2
//enter a list of numbers :
//9
//8
//17