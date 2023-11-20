//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week13 Exe2
//files
//The program receives the name of a file from the user, the program creates
// a new file named frequencyDigits.txt and prints in this file the frequencies
//of the digits that appear in the input file

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	int arr[10]={0};//An array of numbers from 0 to 9 that represents the numbers that appear in the file and contains the number of times the number appears
	char name[101];//An array designed to receive the file name
	cin.getline(name,100);//Receiving the file name
	strcat_s(name, 101, ".txt");//Concatenate the file extension to the file name
	ifstream fin(name);//Defining a variable for reading from the file that the user entered and opening the file
	if (!fin)//Check in case the file failed to open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}
	ofstream fout("frequencyDigits.txt");//Setting a variable for writing to the file and opening the file
	if (!fout)//Check in case the file failed to open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}
	int counter=0,i,k;
	char temp;
	fin>>temp; //Reading the first character in the file
	while (!fin.eof())//Go through the entire file
	{
		if (temp >= 48 && temp < 58)//Checking whether the variable is a number between 0 and 9
		{
			for (int k = 48; k < 58; k++)//Go over the ASCII value of the numbers between 0 and 9
			{
				if (temp == k)//If the called token is equal to the current hash value
				{
					arr[k - 48] += 1;//Adding 1 to the place in the array equal to the called sign
				}
			}
		}
		fin >> temp;//Reading the next sign
	}
	
	fout << "digit  frequenty" << endl;//Print headers to the file
	cout << "digit  frequenty" << endl;//Print titles to the black screen
	for (i = 0; i < 10; i++)//Printing the array that contains the digits and the number of times they appeared to the black screen and to the file
	{
		fout <<"  " <<i << "     " << arr[i] << endl;
		cout << "  "<<i << "     " << arr[i] << endl;
	}
	fin.close();//Closing the read file
	fout.close();//Closing the write file
	return 0;
}

//exemple:
//information
//digit  frequenty
// 0     0
// 1     3
// 2     1
// 3     1
// 4     0
// 5     1
// 6     0
// 7     1
// 8     1
// 9     1
