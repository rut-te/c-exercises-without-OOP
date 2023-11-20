//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week7 Exe4
//Two-dimensional arrays and algorithms: search, sorting and merging
//The program that defines a two-dimensional array of 5 ª 10 characters.
//The program must receive ten words(character by character), each word with only 5 letters(each word will appear in a separate 
//row in the matrix).That is, according to the order of their appearance in the dictionary(lexicon).The program must print the sorted words.

#include<iostream>
using namespace std;
const int SIZE_L =10, SIZE_R =5;//Defining a constant variable that expresses the size of the array
void bubbleSort( char mat[][SIZE_R]);//Declaring a bubble sort function

int main()
{
	char mat[SIZE_L][SIZE_R];//matrix definition
	cout << "enter 10 words:" << endl;
	for (int i = 0; i < SIZE_L; i++)//Reading the matrix values
	{
		for (int j = 0; j < SIZE_R; j++)
		{
			cin >> mat[i][j];
		}
	}
	bubbleSort(mat);//Summoning the sorting function
	cout << "after sorting:" << endl;
	for (int i = 0; i < SIZE_L; i++)//Print the matrix after sorting
	{
		for (int j = 0; j < SIZE_R; j++)
			cout << mat[i][j];
		cout << " ";
	}
	cout << endl;
	return 0;
}
void bubbleSort(char mat[][SIZE_R])//Bubble sort function
{
	int j = 0;
	char temp[SIZE_R];//Setting up a help array
	for (int m = 0; m < SIZE_L - 1; m++)
	{
		for (int i = 0; i < SIZE_L - 1 - m; i++)
		{
			while (mat[i][j] == mat[i + 1][j] && j < SIZE_R)
					
				j++;
			if (mat[i][j] > mat[i + 1][j])
			{
				for (int k = 0; k < SIZE_R; k++)
					temp[k] = mat[i][k];

				for (int k = 0; k < SIZE_R; k++)
					mat[i][k] = mat[i + 1][k];

				for (int k = 0; k < SIZE_R; k++)
					mat[i + 1][k] = temp[k];
							
			}
			j = 0;
					
		}
			
	}
}

//exemple:
//enter 10 words:
//house apple teach array teach books point float apply begin
//after sorting :
//apple apply array begin books float house point teach teach