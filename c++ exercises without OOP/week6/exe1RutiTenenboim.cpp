//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week6 Exe1
//one-dimensional arrays.
//The program receives a list of 15 numbers. The program checks whether all the
//numbers from one to fifteen exist. If so, the program prints GOOD. 
//If not, the program prints NOT GOOD.

#include<iostream>
using namespace std;
const int N = 15;//Defining a const variable, which expresses the number of members in the array.
int main()
{
	int counter = N;
	int arr[N];//Array definition.
	cout << "enter 15 numbers:" << endl;
	for (int i = 0; i < N; i++)//Receiving the array numbers.
	{
		cin >> arr[i];
	}
	bool flag ,help=true;//Defining variables for truth checking.
	for (int i = 0; i < N; i++)//Over all the members of the array.
	{
		flag = false;
		for (int j = 1; j <=N; j++)//Go over the numbers from 1 to 15.
		{
			if (arr[i] == j)//Checking whether the number exists in the array member.
			{
				for (int k = 0; k < i; k++)//Checking whether the aforementioned number has already appeared in the previous members.
				{
					if (arr[k] == j)//Checking whether the aforementioned number has already appeared in a previous member, turning the mark into a lie.
						help=false;
				}
				if (help == true)//Check whether the number did not appear, flag will be correct. And if he appeared a flag would not be wrong.
					flag = true;
				else
					flag = false;
			}
			
		}
		if (flag)//If flag is correct, you downloaded one from counter.
			counter-=1;
	}
	if (counter)//If the counter equals zero, printing is good. Otherwise the print is not good.
		cout << "NOT GOOD." << endl;
	else
		cout << "GOOD" << endl;

	
	return 0;
}

//exemple:
//enter 15 numbers:
//15
//8
//9
//7
//1
//3
//4
//2
//10
//14
//6
//5
//13
//12
//11
//GOOD

//enter 15 numbers:
//15
//8
//9
//16
//1
//3
//4
//2
//10
//14
//6
//5
//13
//12
//11
//NOT GOOD.
