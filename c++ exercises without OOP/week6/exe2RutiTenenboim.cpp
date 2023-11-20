//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week6 Exe2
//one-dimensional arrays.
//The program has 2 sets. The first contains a maximum of 500 places and the
//second a maximum of 100 places. The program then picks up the number of places
//in the first array and the members. and in the second array. 
//After that, the program must check and print the number of times the members of 
//the second array appear consecutively in the members of the first array.

#include<iostream>
using namespace std;

int main()
{
	int vector1[500];//Defining the first array.
	int vector2[100];//Defining the second array.
	cout << "enter size of first array:" << endl;
	int num1, num2;//Defining variables that express the size of the array.
	cin >> num1;
	while (num1 <= 0||num1>500)//Input integrity check on the num1.
	{
		cout << "ERROR" << endl;
		cin >> num1;
	}
	cout << "enter first array values:" << endl;
	for (int i = 0; i < num1; i++)//The reception of the members of the array.
	{
		cin >> vector1[i];
	}
	cout << "enter size of second array:" << endl;
	cin >> num2;
	while (num2 <= 0||num2>100)//Input integrity check on the num1.
	{
		cout << "ERROR" << endl;
		cin >> num2;
	}
	cout << "enter second array values:" << endl;
	for (int i = 0; i < num2; i++)//The reception of the members of the array.
	{
		cin >> vector2[i];
	}
	int counter = num2, help = 0, k = 0;//Setting Variables.
	for(int i=0;i<num1;i++)//Go over all the members of the first array.
	{
		k = i;//Resetting the variable K each time in order to compare it to the variable I that expresses the position in the first array.
		counter = num2;//Resetting the counter every time in order to compare it to the number of elements in the second array.
		for(int j=0;j<num2;j++)//Checking whether all members of the second array appear in sequence in the first array.
		{
			if (vector1[k] == vector2[j])//Checking whether the element in the first array is equal to the element in the second array.
			{
				counter--;//Subtraction from the counter in order to know at the end whether indeed all the numbers from the second array appeared in sequence.
			}
			k++;//Go to the next number.
		}
		if (counter == 0)//If the counter equals zero, that is, all the numbers appeared in a row, adding one to the help variable, in order to know at the end how many times the numbers appeared in a row.
			help++;
	}
	cout << "result: "<<help <<" times" <<endl;

	return 0;
}

//exemple:
//enter size of first array:
//11
//enter first array values :
//	1
//	2
//	1
//	2
//	1
//	2
//	1
//	2
//	1
//	2
//	1
//	enter size of second array:
//3
//enter second array values :
//	1
//	2
//	1
//	result : 5 times

//enter first array values:
//6
//5
//4
//3
//2
//1
//6
//5
//4
//3
//2
//1
//6
//5
//4
//3
//2
//1
//enter size of second array:
//4
//enter second array values :
//	5
//	4
//	3
//	2
//	result : 3 times


