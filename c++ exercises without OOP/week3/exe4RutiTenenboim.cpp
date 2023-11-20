//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe4
//reads three numbers. Checks whether the numbers can form a triangle.
//If not, prints:cannot form a triangle . If so, it checks whether it is an 
//equilateral triangle, isosceles, or just a triangle and prints the result.

#include<iostream>
using namespace std;

int main()
{
	cout << "enter 3 numbers:"<<endl;
	int x, y, z;
	cin >> x >> y >> z;
	if (x <= 0 || y <= 0 || z <= 0)//Input integrity check.
		cout << "error";
	else
	{
		if (x + y > z && x + z > y && y + z > x)//Checking whether the triangle is correct.
		{
			if (x == y && x == z)//Checking whether the triangle is equilateral.
				cout << "equilateral triangle";
			if (x == y && x != z || x == z && x != y || y == z && y != x)//Checking whether the triangle is isosceles.
				cout << "isosceles triangle";
			if (x != y && x != z && y != z)//Checking whether the triangle is just a triangle.
				cout << "scalene triangle";
		}
		else
			cout << "cannot form a triangle";
	}
	return 0;
}


//exemple:
//enter 3 numbers:
//5
//5
//5
//equilateral triangle

//enter 3 numbers:
//5
//7
//5
//isosceles triangle

//enter 3 numbers:
//3
//4
//5
//scalene triangle

//enter 3 numbers:
//1
//7
//5
//cannot form a triangle