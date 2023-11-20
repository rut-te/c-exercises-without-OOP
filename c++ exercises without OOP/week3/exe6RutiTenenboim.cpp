//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe6
//Reads a number that expresses a month, 
//and prints how many days there are in this month.

#include<iostream>
using namespace std;
enum MONTH{JAN=1,FEB,MARCH,APRIL,MAY,JUNE,JULY,AUG,SEPT,OCT,NOV,DEC};
int main()
{
	cout << "enter a number:" << endl;
	int num;
	cin >> num;
	if (num > 12 || num < 1)//Input integrity check.
		cout << "error";
	else
	{
		switch (num)//Use of, in order to check how many days there are in each month.
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << "31";//Print the months that have 31 days.
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cout << "30";//Print the months that have 30 days.
			break;
		case 2:
			cout << "28";//Print the months that have 28 days.
			break;
		}
		cout << " days in the month";


	}
	return 0;
}


//exemple:
//enter a number :
//3
//31 days in the month

//enter a number :
//6
//30 days in the month