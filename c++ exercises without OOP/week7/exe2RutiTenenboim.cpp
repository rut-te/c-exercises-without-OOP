//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week7 Exe2
//Two-dimensional arrays and algorithms: search, sorting and merging
//The program defines three one-dimensional arrays of integers of size 10, and takes the numbers into arrays.
//The program sends the arrays to a function that merges them into one function in non - ascending order.
//The program prints the sorted array.

#include<iostream>
using namespace std;
const int SIZE = 10;//Defining a constant variable that expresses the size of the array
void readCheck(int vec[], int SIZE);//Declaring a function that reads the array variables and performs an input integrity check
void mergedvec(int vec4[], int vec1[], int vec2[], int vec3[]);//Declaring a function that merges the three arrays
int main()
{
	int vec1[SIZE]={};//Array definition 1
	cout << "enter values for the first vector:" << endl;
	readCheck(vec1, SIZE);//A call to a function that reads the elements in the array
	int vec2[SIZE] = {};//Array definition 2
	cout << "enter values for the second vector:" << endl;
	readCheck(vec2, SIZE);//A call to a function that reads the elements in the array
	int vec3[SIZE] = {};//Array definition 3
	cout << "enter values for the third vector:" << endl;
	readCheck(vec3, SIZE);//A call to a function that reads the elements in the array
	int vec4[SIZE * 3]={};//Array definition 4
	mergedvec(vec4,vec1, vec2, vec3);//A call to the function that merges the elements of the arrays
	cout << "merged vector is:" << endl;
	for (int i = 0; i < (SIZE * 3); i++)//Printing after merging
		if (vec4[i])
			cout << vec4[i] << " ";

	
	return 0;
}
void readCheck(int vec[], int SIZE)//a function that reads the array variables and performs an input integrity check
{
	bool flag = true;
	while (flag)
	{
		cin >> vec[0];
		if (vec[0] == 0)
			break;
		for (int i = 1; i <= SIZE-1; i++)
		{
			cin >> vec[i];
			if (vec[i] > vec[i - 1]||vec[i]<0)
				flag = false;
			if (vec[i] == 0)
				break;
		}
		if (flag == false)
		{
			cout << "ERROR" << endl;
			flag = true;
			for (int j = 0; j < SIZE; j++)
				vec[j] = 0;
		}
		else
			flag = false;

	}
}
void mergedvec(int vec4[], int vec1[], int vec2[], int vec3[])//a function that merges the three arrays
{
	int i = 0,j=0,m=0,k=0;
		while (i < SIZE && j < SIZE && m < SIZE)//As long as the three arrays have not yet reached their end
		{


			if (vec1[i] >= vec2[j] && vec1[i] >= vec3[m])
			{
				vec4[k] = vec1[i];
				i++;
			}
			else
			{
				if (vec2[j] > vec3[m])
				{
					vec4[k] = vec2[j];
					j++;
				}
				else
				{
					vec4[k] = vec3[m];
					m++;
				}

			}
			k++;
		}
		if (i >= SIZE)//when only two arrays did not reach their end
		{
			while (j < SIZE && m < SIZE)
			{
				if (vec2[j] > vec3[m])
				{
					vec4[k] = vec2[j];
					j++;
				}
				else
				{
					vec4[k] = vec3[m];
					m++;
				}
				k++;
			}
		}
		else
		{
			if (j >= SIZE)
			{
				while (i < SIZE && m < SIZE)
				{
					if (vec1[i] > vec3[m])
					{
						vec4[k] = vec1[i];
						i++;
					}
					else
					{
						vec4[k] = vec3[m];
						m++;
					}
					k++;
				}
			}
			else
			{
				while (i < SIZE && j < SIZE)
				{
					if (vec1[i] > vec2[j])
					{
						vec4[k] = vec1[i];
						i++;
					}
					else
					{
						vec4[k] = vec2[j];
						j++;
					}
					k++;
				}
			}
		}
		if (j >= SIZE && m >= SIZE)//When only one array did not reach its end
		{
			while (i < SIZE)
			{
				vec4[k] = vec1[i];
				i++;
				k++;
			}
		}
		else
		{
			if (i >= SIZE && m >= SIZE)
			{
				while (j < SIZE)
				{
					vec4[k] = vec2[j];
					j++;
					k++;
				}
			}
			else
			{
				while (m < SIZE)
				{
					vec4[k] = vec3[m];
					m++;
					k++;
				}
			}
		}
			
	
}

//exemple:
//enter values for the first vector :
//6
//4
//2
//0
//enter values for the second vector :
//21
//19
//17
//14
//13
//12
//9
//6
//3
//2
//enter values for the third vector :
//3
//2
//1
//0
//merged vector is :
//21 19 17 14 13 12 9 6 6 4 3 3 2 2 2 1

//enter values for the first vector :
//4
//2
//0
//enter values for the second vector :
//5
//4
//7
//0
//ERROR
//5
//4
//- 3
//2
//0
//ERROR
//4
//3
//0
//enter values for the third vector :
//7
//6
//5
//4
//3
//2
//1
//0
//merged vector is :
//7 6 5 4 4 4 3 3 2 2 1