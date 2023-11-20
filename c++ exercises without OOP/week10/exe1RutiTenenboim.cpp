//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week10 Exe1
//string
//The program receives a word and encrypts it using the AT BS method.

#include <iostream>
#include <cstring>
using namespace std;
int const SIZE = 81;//Defining a constant variable of size 81
void crypto(char str[]);//Defining the function that performs the encryption
int main()
{
	cout << "Enter a string:" << endl;
	char str[SIZE];//Defining a static array of size 81
	cin >> str;//Receiving the word to be encrypted into the array
	cout << "After crypto:" << endl;
	crypto(str);//Sending the array to the encrypting function
	cout << str << endl;//Printing the encrypted array
	
	return 0;
}
void crypto(char str[])//the function that performs the encryption
{
	int sum ;
	for(int i=0;str[i]!='\0';i++)//A loop that goes through the entire array up to the first /0
	{
		if (str[i] >= 'a' && str[i] <= 'z')//Checking whether the character is of the lowercase type
		{
			sum=str[i]-'a';//A sum equal to the value of the current character minus the value of the character a
			str[i] = 'z' - sum;//The execution of the encryption - the convenient character is equal to the character whose value is z value minus sum
		}
	}
	
}

//exemple:
//Enter a string :
//bamba
//After crypto :
//yznyz

//Enter a string :
//baA ? ba
//After crypto :
//yzA ? yz

