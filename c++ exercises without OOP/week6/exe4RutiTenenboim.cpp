//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week6 Exe4
//one-dimensional arrays.
//The program defines an array of decimal numbers of size 6. The program receives 6 
//decimal numbers. The program then creates a new array of size 6 in which the
//ordinal values of the members of the first array appear in ascending order.

#include<iostream>
using namespace std;

int main()
{
	float numbers[6];//Array definition.
	cout << "enter 6 numbers between 0 and 1:" << endl;
	for (int i = 0; i < 6; i++)//The reception of the members of the array.
	{
		cin >> numbers[i];
		if (numbers[i] <= 0 || numbers[i] >= 1)//Input integrity check.
		{
			cout << "ERROR" << endl;
			i = -1;//Resetting the variable I in order to start receiving the numbers again.
		}
	}
	int indices[6];//Defining an additional array.
	int smallest = -2,i=0;//Defining variables for the continuation of the program.
	for (int j = 0; j < 6; j++)//Over all the indices of the array numbers.
	{
		smallest = -2, i = 0;//Returning the initial value of the variables at each iteration.
		while (smallest!=(i-1))//A loop that continues as long as the variable smallest is not equal to i-1.
		{
			bool flag = true;//Setting a flag variable that marked true.
			for (int k = 0; k < 6; k++)//Check what is the smallest number.
			{
				if (numbers[i] > numbers[k])//If there is a number in the array smaller than the current number(i), turning the flag to false.
					flag = false;
			}
			if (flag)//If the flag is true, the variable is equal to i, i.e. the position of the small variable.
			{
				smallest = i;
			}
			i++;//Move to the next number in the array numbers.
		}
		
		indices[j] = smallest;//Placement in an array member indices.
		numbers[smallest] += 10;//Increasing the number in the smallest (=i) place by 10, so that it is not the smallest number.
	}
	cout << "sorted indices:" << endl;
	for (auto x : indices)//Printing the new array.
		cout << x << " ";
	
	return 0;
}

//exemple:
//enter 6 numbers between 0 and 1:
//0.9
//0.05
//0.1
//0.4
//0.2
//0.3
//sorted indices :
//1 2 4 5 3 0

//enter 6 numbers between 0 and 1:
//0.9
//0.5
//2.7
//ERROR
//0.9
//0.05
//0.1
//0.4
//0.2
//0.3
//sorted indices :
//1 2 4 5 3 0
