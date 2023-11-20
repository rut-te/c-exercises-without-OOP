//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week10 Exe2
//string
//The program accepts a sentence string, and turns it into a reversed sentence string.

#include <iostream>
#include <cstring>
using namespace std;
int const SIZE = 81;//Defining a constant variable of size 81
void reverse(char sentence[]);//Defining a function that inverts the sentence
int main()
{
	char sentence[SIZE];//Defining a static array of size 81
	cout << "Enter a string: " << endl;
	cin.getline(sentence, (SIZE-1));//receiving the sentence untill the first enter
	reverse(sentence);//Sending the array containing the received sentence to a function that will transform it
	cout << "After reverse:";
	cout << sentence << endl;//Print the reverse string

	return 0;
}
void reverse(char sentence[])//function that inverts the sentence
{
	char temp;
	int i=0,counter=0,j=0,size=0;
	while (counter< (SIZE - 1) &&sentence[counter]!='\0')//A loop that exists as long as there are members in the array, and there hasn't been yet enter
	{
		while (sentence[counter] != ' ' && sentence[counter] != '\0')//A loop that exists as long as the member is not empty, nor is it enter
		{
			counter++;//Checking which index the current word reaches
		}
		size = (counter - i) / 2;//Calculation of how many reversals should be performed in a word
		for (j=0; j < size; j++)//Making the exchange between the letters in the word
		{
			temp = sentence[i];
			sentence[i]=sentence[counter - j - 1];
			sentence[counter - j - 1] = temp;
			i++;
		}
		i = counter + 1;//change the value of the variable into the index after the replaced word
		if (sentence[counter] != '\0')//Go to the index of the first letter in the word
			counter ++;
	}
}


//exemple:
//Enter a string :
//hello rut
//After reverse : olleh tur

//Enter a string :
//This is a silly88 sentence
//After reverse : sihT si a 88yllis ecnetnes