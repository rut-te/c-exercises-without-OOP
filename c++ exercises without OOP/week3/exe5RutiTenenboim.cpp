//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week3 Exe5
//Reads three numbers and saves the largest in biggest, the middle in middle,
//and the smallest in smallest,and prints them in ascending order.

#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers:" << endl;
	cin >> num1 >> num2 >> num3;
	if (num1 <= num2 && num1 <= num3)//checking if num1 is the smallest.
		smallest = num1;
	else if (num2 < num1 && num2 <= num3)//checking if num2 is the smallest.
			smallest = num2;
		else smallest = num3;//checking if num3 is the smallest.
	if (num1 <= num2 && num1 >= num3 || num1<= num3 && num1>= num2)//checking if num1 is the middle.
		middle = num1;
	else if (num2 < num1 && num2 >= num3 || num2<= num3 && num2> num1)//checking if num2 is the middle.
			middle = num2;
		else middle = num3;//checking if num3 is the middle.
	if (num1 >= num2 && num1 >= num3)//checking if num1 is the biggest.
		biggest = num1;
	else if (num2 >num1 && num2 >=num3)//checking if num2 is the biggest.
			biggest = num2;
		else biggest = num3;//checking if num3 is the biggest.
	cout << smallest << " " << middle << " " << biggest<<endl;
	return 0;
}


//exemple:
//enter 3 numbers:
//2
//9
//4
//2 4 9

//enter 3 numbers:
//9
//6
//1
//1 6 9