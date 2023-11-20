//ruti tenenboim
//214360778
//mavo lemadaei amachshev
//week2 exe8
//read the flight takeoff and flight duration and print the flight arrival. 

#include<iostream>
using namespace std;
int main()
{
	cout << "enter the flight takeoff:" << endl;
	int hour1=0, hour2=0, hour3=0, min1=0, min2=0, min3=0, sec1=0, sec2=0, sec3=0;//variable definition
	cin >> hour1 >> min1 >> sec1;
	cout << "enter flight duration:" << endl;
	cin >> hour2 >> min2 >> sec2;
	sec3 = (sec1 + sec2) % 60;//calculation the seconds
	min3 = (sec1 + sec2) / 60 + (min1 + min2) % 60;//calculation the minutes
	hour3 = (min1 + min2) / 60 + (hour1 + hour2) % 24;//calculation the hours
	cout << "flight arrival is:" << endl << hour3 << ":" << min3 << ":" << sec3;

	return 0;
}

//exemple:
//enter the flight takeoff :
//21
//45
//33
//enter flight duration :
//0
//55
//10
//flight arrival is :
//22 : 40 : 43

