//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week7 Exe3
//Two-dimensional arrays and algorithms: search, sorting and merging
//The program that defines a two-dimensional array (matrix) of 10 × 10 integers.
//The program must receive from the user 100 positive integers for the matrix.After receiving the values, the program prints the
//values ​​of the matrix, with each row appearing in a separate row.The program sorts the two halves of the matrix,
//upper right triangleand lower left triangle, using insertion sort in non - descending order.For each of the triangles,
//the sorting will be done as follows : the smallest number will appear in the upper left box of the triangle, the following 
//numbers will appear in order along the rows, row by row, until the largest number appears in the lower right box of the triangle.
//The diagonal of the triangle remains unchanged.The program must print the elements of the sorted matrix, with each row appearing 
//in a separate line on the screen.

#include<iostream>
using namespace std;
const int SIZE = 10;//Defining a constant variable that expresses the size of the array
void print(int mat[][SIZE]);//Declaration of a function that prints the array
void insertionSort(int arr[],int size);//Declaration of a function that sorts the matrix
int main()
{
	int mat[SIZE][SIZE];//matrix definition
	cout << "enter the values:" << endl;
	for (int i = 0; i < SIZE; i++)//Receiving the numbers
	{
		for (int j = 0; j < SIZE; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] <= 0)//Input integrity check
			{
				cout << "ERROR" << endl;
				cin >> mat[i][j];
			}
		}
	}
	cout << "before sorted:" << endl;
	print(mat);//A call to the print function
	int arr1[(SIZE * SIZE - SIZE) / 2]={0};//Defining an auxiliary array 1
	int arr2[(SIZE * SIZE - SIZE )/ 2]={0};//Defining an auxiliary array 2
	int k = 0, m = 0;
	for (int i = 0; i < SIZE; i++)//Dividing the matrix into two arrays according to the triangles
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i != j)//If the number is not part of the main diagonal
			{
				if (j > i)//If it belongs to the right triangle, place in array 1
				{
					arr1[k] = mat[i][j];
					k++;
				}
				else//If it belongs to the left triangle, place in array 2
				{
					arr2[m] = mat[i][j];
					m++;
				}
			}
		}
	}
	
	insertionSort(arr1, (SIZE * SIZE - SIZE) / 2);//Calling the sort function for array1
	insertionSort(arr2, (SIZE * SIZE - SIZE )/ 2);//Calling the sort function for array2
	cout << "sorted matrix:" << endl;
	k = 0, m = 0;
	for (int i = 0; i < SIZE; i++)//Print the matrix after sorting
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i != j)
			{
				if (j > i)//Printing the right triangle
				{
					cout << arr1[k]<<"  ";
					k++;
				}
				else//Printing the left triangle
				{
					cout << arr2[m] << "  ";
					m++;
				}
			}
			else//Print the main diagonal
				cout << mat[i][j] << "  ";
			
		}
		cout << endl;
	}


	return 0;
}
void print(int mat[][SIZE])//The print function
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void insertionSort(int arr[],int size)//Income sorting function
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] >=temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

//exemple:
//82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54
//64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36
//46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18
//28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99
//10 20 30 40 50 60 70 80 90 100
//before sorted :
//1 11 21 31 41 51 61 71 81 91
//2 12 22 32 42 52 62 72 82 92
//3 13 23 33 43 53 63 73 83 93
//4 14 24 34 44 54 64 74 84 94
//5 15 25 35 45 55 65 75 85 95
//6 16 26 36 46 56 66 76 86 96
//7 17 27 37 47 57 67 77 87 97
//8 18 28 38 48 58 68 78 88 98
//9 19 29 39 49 59 69 79 89 99
//10 20 30 40 50 60 70 80 90 100
//sorted matrix :
//1  11  21  22  31  32  33  41  42  43
//2  12  44  51  52  53  54  55  61  62
//3  4  23  63  64  65  66  71  72  73
//5  6  7  34  74  75  76  77  81  82
//8  9  10  13  45  83  84  85  86  87
//14  15  16  17  18  56  88  91  92  93
//19  20  24  25  26  27  67  94  95  96
//28  29  30  35  36  37  38  78  97  98
//39  40  46  47  48  49  50  57  89  99
//58  59  60  68  69  70  79  80  90  100