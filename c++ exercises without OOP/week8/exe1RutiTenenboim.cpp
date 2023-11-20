//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week8 Exe1
//pointers
//The program receives two arrays: big, small. The program must return the skip
//The minimum of small inside big.If it is not found, the program must return -1

#include<iostream>
using namespace std;
int minimalSkipping(int* big,int sizeBig, int* small, int sizeSmall);//Declaration of the function that calculates the minimum skip
int main()
{
	int big[80] = {};//Setting up the big array
	int num1;//The size of the large array
	cout << "Enter the size of big:" << endl;
	cin >> num1;
	cout << "Enter " << num1 << " numbers:" << endl;
	for (int i = 0; i < num1; i++)//Receiving the numbers of the large array
		cin >> *(big + i);
	int small[80] = {};//Setting up the small array
	int num2;//The size of the small array
	cout << "Enter the size of small:" << endl;
	cin >> num2;
	cout << "Enter " << num2 << " numbers:" << endl;
	for (int i = 0; i < num2; i++)//Receiving the numbers of the small array
		cin >> *(small + i);
	int temp=minimalSkipping(big, num1, small, num2);//Calling the function that calculates the minimum skip and saving its returned value in an auxiliary variable
	cout << "Size of jump:" << endl;//Minimum skip printing
	cout << temp;
	
	
	return 0;
}
int minimalSkipping(int* big, int sizeBig ,int* small, int sizeSmall)//Implementation of the function that calculates the minimum skip
{
	int flag;
	int help1=0, help2=0,help3=0,n=0;
	for (int k = 0; k <=(sizeBig/sizeSmall); k++)//A loop that goes through all the possible differences between the numbers.
	{
		
		int i = 0;//A variable that represents the place in the small array
		
			for (int j=0; j < sizeBig&&i<sizeSmall; j++)//A loop that goes through the big array
			{
				flag = true;
				if (*(big+j) == *(small+i))//Check if the numbers are the same
				{
					help1 = j;
					help2 = i;
					help2++;
					for (int min = 0; min <=k; min++)//Adding to the auxiliary variable according to the number of the difference the loop holds
						help1++;
					
					while (help1 < sizeBig && help2 < sizeSmall)//Checking if the numbers are not the same
					{
						if (*(big+help1) != *(small+help2))
						{
							flag = false;
						}
						
						for (int min = 0; min <= k; min++)//Adding to the auxiliary variable according to the number of the difference the loop holds
							help1++;
						help2++;
					}
					if (flag==true && help2>=sizeSmall)//In case the minimum skip is found, returning the value of K. That is, the value held by the skip loop
						return k;
				}
				
			}
	}
	return -1;//In case the minimum skip is not found, returning the value -1
}

//exemple:
//Enter the size of big:
//5
//Enter 5 numbers:
//11 1 2 8 5
//Enter the size of small :
//3
//Enter 3 numbers :
//	1 2 8
//	Size of jump :
//0

//Enter the size of big :
//17
//Enter 17 numbers :
//	1 2 2 1 5 8 2 5 4 3 5 8 3 5 1 2 7
//	Enter the size of small :
//3
//Enter 3 numbers :
//	1 2 3
//	Size of jump :
//2

//Enter the size of big :
//11
//Enter 11 numbers :
//	1 2 2 3 5 8 3 5 1 2 7
//	Enter the size of small :
//3
//Enter 3 numbers :
//	1 2 3
//	Size of jump :
//-1
