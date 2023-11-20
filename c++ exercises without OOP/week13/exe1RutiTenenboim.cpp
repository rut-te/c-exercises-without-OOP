//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week13 Exe1
//files
//The program receives numerical data from two input files and prints to the 
//screen the number of the file whose average data is the highest

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
float avarage(ifstream& fin);//Defining a function that calculates an average from a file
int main()
{
	ifstream fin1("grade1.txt");//Defining a variable for reading from file1 and opening the file
	if (!fin1)//Check in case the file failed to open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}
	ifstream fin2("grade2.txt");//Defining a variable for reading from file2 and opening the file
	if (!fin2)//Check in case the file failed to open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}
	float avarage1 = avarage(fin1);//A function call for the first file
	float avarage2 = avarage(fin2);//A function call for the second file
	if (avarage1 == avarage2)//Testing in case the average is the same
		cout << "The avarage are equal" << endl;
	else//Testing in case the average is different
	{
		cout << "highest average found in file ";
		if (avarage1 > avarage2)
			cout << "1" << endl;//Print 1 in case the average of the first file is the largest
		else
			cout << "2" << endl;//Print 2 in case the average of the second file is the largest
	}
	fin1.close();//Closing the 1st file
	fin2.close();//Closing the 2st file
	return 0;
}
float avarage(ifstream& fin)//function that calculates an average from a file
{
	int num,counter=1;
	fin >> num;//Reading from the file
	float avarage=num;//Calculation that the average is equal to the value of the number taken from the file
	while (!fin.eof())//Go through the entire file
	{
		fin >> num;//Reading from the file
		avarage += num;//Adding the read number to the average
		counter++;//Calculate how many numbers were called
	}
	int favarage = avarage / counter;//Calculate the average by dividing all the numbers called by the number of numbers called
	return favarage;//Returning the final average
}

//exemple:
//highest average found in file 2
