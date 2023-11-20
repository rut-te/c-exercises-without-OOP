//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week10 Exe3
//string
//The program arranges strings in lexicographic order, and performs operations 
//on them according to the user's choice.

#include <iostream>
#include <cstring>
using namespace std;
void  newStr(char** &lexicon, int &size, char newWord[]);//Defining a function that adds a word to the dictionary
void  delStr(char** &lexicon, int &size, char delWord[]);//Defining a function that deletes a word from the dictionary
void  printAll(char** lexicon, int size);//Defining a function that prints all the words in the dictionary
char* searchStr(char** lexicon, int size, char searchWord[]);//Defining a function that returns whether a certain word exists in the dictionary or not
void  printChar(char** lexicon, int size,char letter);//Defining a function that prints all the words in the dictionary that start with a certain letter
int main()
{
	char** lexicon=nullptr;//Pointer-to-pointer definition for creating a dynamic matrix
	int choise,size=0;
	char tav;
	char word[80];//Defining a static array of size 80
	cout << "Enter 0-5:" << endl;
	cin >> choise;
	while (choise != 5)//A loop that continues as long as the input is not 5
	{
		switch (choise)
		{
		case 0:
			cout << "Enter the word:" << endl;
			cin >> word;//Receiving the word to insert into an array
			newStr(lexicon,size,word);//Sending to the add function
			printAll(lexicon,size);//Sending to the printer function
			break;
		case 1:
			cout << "Enter the word to delete:" << endl;
			cin >> word;//Receiving the word to delete into an array
			delStr(lexicon, size, word);//Sending to the deleted function
			printAll(lexicon, size);//Sending to the printer function
			break;
		case 2:
			cout << "Enter the word to search for:" << endl;
			cin >> word;//Entering the search word into an array
			char* ans;//Setting a pointer that will receive the address of the member with the word search
			ans= searchStr(lexicon, size, word);//Sending the word to the function and putting the answer in the pointer
			if (ans != nullptr)//If there is a return address, print found. If not print not found
				cout << "Found" << endl;
			else
				cout << "Not found" << endl;
			break;
		case 3:
			cout << "Enter the char:" << endl;
			cin >> tav;//Receiving the word, the letter that begins the words you want to print
			printChar(lexicon, size, tav);//Sending the character to the function that prints the words that start with that character
			break;
		case 4:
			printAll(lexicon, size);//Sending the array to the print function
			break;
		default:
			break;
		}
		cout << "Enter 0-5:" << endl;
		cin >> choise;

	}
	for (int i = 0; i < size; i++)//Release of dynamic allocations
	{
		delete[]lexicon[i];
	}
	delete[]lexicon;//Release of dynamic allocation
	return 0;
}
void  newStr(char** &lexicon, int& size, char newWord[])//function that adds a word to the dictionary
{
	if (searchStr(lexicon, size, newWord) == nullptr)//Checking whether the word does not exist in the dictionary
	{
		int len;
		if(size)//If members already exist in the array
		{ 
			char** newMat = new char* [size + 1];//Defining a new dynamic array one size larger than the array of words
			if (!newMat)
			{
			    cout << "ERROR" << endl;
				return;
			}
		
			bool flag = false;
			for (int i = 0, j = 0; i < (size + 1); i++)//Copying all the words to the new array and adding the new word in its appropriate place according to the dictionary order
			{
				if (j < size)
				{
					if (strcmp(newWord, lexicon[j]) == 1 || flag == true)
					{
						newMat[i] = lexicon[j];
						j++;
					}
					else
					{
						len = strlen(newWord);
						newMat[i] = new char[len + 1];
						if (!newMat[i])
						{
							cout << "ERROR";
							delete[] newMat;
							return;
						}
						strcpy_s(newMat[i], len + 1, newWord);
						flag = true;
					}
				}
				else
				{
					len = strlen(newWord);
					newMat[i] = new char[len + 1];
					if (!newMat[i])
					{
						cout << "ERROR";
						delete[] newMat;
						return;
					}
					strcpy_s(newMat[i], len + 1, newWord);
					flag = true;
				}

			}
			delete[]lexicon;
			lexicon = newMat;
			size++;
		}
		else//In case this is the first word that enters the array, you added it to a new dynamic array of size 1
		{
			len = strlen(newWord);
			lexicon = new char* [1];
			if (!lexicon)
			{
				cout << "ERROR" << endl;
				return;
			}
			lexicon[0] = new char[len + 1];
			if (!lexicon[0])
			{
				delete[]lexicon;
				cout << "ERROR" << endl;
				return;
			}
			strcpy_s(lexicon[0], len + 1, newWord);
			size++;
		}
	}
}
void  delStr(char** &lexicon, int& size, char delWord[])//Defining a function that deletes a word from the dictionary
{
	if (searchStr(lexicon, size, delWord) != NULL)//Checking whether the word you want to delete exists in the dictionary
	{
		for (int i = 0; i < size; i++)//Over the entire dictionary
		{
			if (strcmp(delWord, lexicon[i]) == 0)//Search for the word you want to delete within the array
			{
				delete[]lexicon[i];//delete the word
				lexicon[i] = nullptr;
			}
		}
		char** newMat = new char*[size - 1];//Defining a dynamic array of one size less than the array of words means that we will get the members of the array without the member we deleted
		if (!newMat)
		{
			cout << "ERROR" << endl;
		}
		for (int j = 0,k=0; j < size - 1; k++)//Copying the words in the dictionary to the new array
		{
			if (lexicon[k] != nullptr)
			{
				newMat[j] = lexicon[k];
				j++;
			}
		}
		delete[]lexicon;
		lexicon = newMat;
		size--;
	}
}
void  printAll(char** lexicon, int size)//function that prints all the words in the dictionary
{
	for (int i = 0; i < size; i++)//loop that prints all the words in the dictionary
	{
		cout << lexicon[i] << endl;
	}
}
char* searchStr(char** lexicon, int size, char searchWord[])//function that returns whether a certain word exists in the dictionary or not
{
	for (int i = 0; i < size; i++)//Over the entire dictionary
	{
		if (strcmp(lexicon[i], searchWord) == 0)//If the word is found, its address is returned, otherwise it is returned nullptr
			return lexicon[i];
	}
	return nullptr;
}
void  printChar(char** lexicon, int size, char letter)//function that prints all the words in the dictionary that start with a certain letter
{
	for (int i = 0; i < size; i++)//Going through the entire dictionary and printing the words that start with the character that the function received
	{
		if (lexicon[i][0] == letter)
			cout << lexicon[i]<<endl;
	}
}

//exemple:
//Enter 0 - 5:
//0
//Enter the word :
//ruti
//ruti
//Enter 0 - 5 :
//	0
//	Enter the word :
//aba
//aba
//ruti
//Enter 0 - 5 :
//	0
//	Enter the word :
//mom
//aba
//mom
//ruti
//Enter 0 - 5 :
//	0
//	Enter the word :
//shevi
//aba
//mom
//ruti
//shevi
//Enter 0 - 5:
//0
//Enter the word :
//tuti
//aba
//mom
//ruti
//shevi
//tuti
//Enter 0 - 5:
//1
//Enter the word to delete :
//	ruti
//	aba
//	mom
//	shevi
//	tuti
//	Enter 0 - 5:
//2
//Enter the word to search for :
//	aba
//	Found
//	Enter 0 - 5 :
//	2
//	Enter the word to search for :
//	ruti
//	Not found
//	Enter 0 - 5 :
//	3
//	Enter the char :
//	s
//	shevi
//	Enter 0 - 5 :
//	3
//	Enter the char :
//	a
//	aba
//	Enter 0 - 5 :
//	0
//	Enter the word :
//aima
//aba
//aima
//mom
//shevi
//tuti
//Enter 0 - 5:
//3
//Enter the char :
//	a
//	aba
//	aima
//	Enter 0 - 5 :
//	4
//	aba
//	aima
//	mom
//	shevi
//	tuti
//	Enter 0 - 5:
//5
