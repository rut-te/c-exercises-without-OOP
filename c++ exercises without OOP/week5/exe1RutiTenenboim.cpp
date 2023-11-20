//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week5 Exe1
//Function.
//A program that takes the length and width of a rectangle and prints the area
//of the rectangle. and receives the radius of a circle and prints the area
//of the circle.

#include<iostream>
using namespace std;
const float PI = 3.14159;

int area(int, int);//Declaration of a function that calculates the area of a rectangle.
float area(int r);//Declaration of a function that calculates the area of a circle.
int main()
{
	cout << "enter length and width of the rectangle :" << endl;
	int length, width;
	cin >> length >> width;
	while (length <= 0 || width <= 0)//Input integrity check.
	{
		cout << "ERROR" << endl;
		cin >> length >> width;
	}
	cout<<area(length, width)<<endl;
	cout << "enter radius of the circle:" << endl;
	int r;
	cin >> r;
	while (r <= 0)//Input integrity check.
	{
		cout << "ERROR" << endl;
		cin >> r;
	}
	cout << area(r) << endl;


	return 0;
}
int area(int length, int width)
{
	return length * width;//Calculation of the area of the rectangle.
}
float area(int r)
{
	return r * r * PI;//Calculation of the area of the circle.
}

//exemple:
//enter lengthand width of the rectangle :
//4
//2
//8
//enter radius of the circle :
//1
//3.14159

//enter lengthand width of the rectangle :
//1
//- 3
//ERROR
//2
//2
//4
//enter radius of the circle :
//-4
//ERROR
//3
//28.2743




