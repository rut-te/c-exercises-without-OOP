//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week12 Exe1
//structs
//the program calculate some calculations about details of products in the store, according to the data that the user entered.

#include <iostream>
#include <cstring>
using namespace std;
struct Item {
	int code=0;
	char name[20];
	int amount=0;
	int minamount=0;
	float price=0;
};//Defining the structure of an item in the store. The structure is called an Item
enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT };//Definition enum, for the user's choice of what to do with the items in the store
void addItem(Item store[], int maxItems, int & numItems);//Defining a function that adds an item
void findPrice(Item store[],  int numItems);//Defining a function that finds the price of an item
void sold(Item store[], int numItems);//Defining a function that calculates the sale of items
void order(Item store[], int numItems);//Define a function that calculates an order of items
void print(Item store[], int numItems);//Defining a function that prints the items in the store with all their details
int main()
{
	Item* store;//Defining an item type pointer
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;//Receiving the maximum number of items
	store = new Item[maxItems];//Allocating a dynamic array of type Item with the maximum size of the items
	do {
		cout << "enter 0-5:\n";
		cin >> choice;//Accepting the user's choice
		switch (choice) {
		case EXIT: break;
		case ADD: addItem(store, maxItems,numItems);//Adding an item to the array
			break;
		case FIND: findPrice(store, numItems);//Finding the price of an item
			break;
		case SOLD: sold(store, numItems);//Buying an item
			break;
		case ORDER: order(store, numItems);//Order an item
			break;
		case PRINT: print(store, numItems);//Printing the array
			break;
		default: cout << "ERROR" << endl;//default
		}
	} while (choice != 0);
	delete [] store;//The release of the dynamic array of items
	return 0;
}
void addItem(Item store[], int maxItems, int & numItems)//function that adds an item
{	
	bool flag = false;
	int i;
	if (numItems == 0)//In case this is the first item in the array
	{
		cout << "enter code :" << endl;
		cin >> store[0].code;
		cout << "enter name :" << endl;
		cin >> store[0].name;
		cout << "enter amount : " << endl;
		cin >> store[0].amount;
		cout << "enter minimum amount :" << endl;
		cin >> store[0].minamount;
		cout << "enter price :" << endl;
		cin >> store[0].price;
		numItems++;//After receiving the values of the item, increasing the number of existing items by 1
	}
	else //In case this is not the first item in the array
	{
		if (numItems < maxItems)//If the number of existing items is less than the maximum number of items that can be in the array
		{
			cout << "enter code :" << endl;
			cin >> store[numItems].code;//Receiving the item code
			cout << "enter name :" << endl;
			cin >> store[numItems].name;//Receiving the name of the item
			for (i = 0; i < numItems; i++)//Go through the array and check if the item code is present in the array
			{
				if (store[numItems].code == store[i].code)//If so making the sign true
				{
					flag = true;
					break;
				}
			}
			if (flag)//If the code exists
			{
				
				if(strcmp(store[numItems].name,store[i].name)==0)//Checking if the item name is also the same
				{
					cout << "enter amount : " << endl;
					cin >> store[numItems].amount;//Receipt of item quantity
					cout << "enter minimum amount :" << endl;
					cin >> store[numItems].minamount;//Receiving the minimum quantity of the item
					cout << "enter price :" << endl;
					cin >> store[numItems].price;//Receiving the price of the item
					store[i].amount += store[numItems].amount;
					store[i].minamount = store[numItems].minamount;
					store[i].price = store[numItems].price;
					
				}
				else//If the name is changed an error is printed
				{
					cout << "ERROR" << endl;
				}
			}
			else//In the event that the item does not exist in the array, the absorption of the rest of the details about it
			{
				cout << "enter amount : " << endl;
				cin >> store[numItems].amount;
				cout << "enter minimum amount :" << endl;
				cin >> store[numItems].minamount;
				cout << "enter price :" << endl;
				cin >> store[numItems].price;
				numItems++;//After receiving the values of the item, increasing the number of existing items by 1
			}
		}
		else//If the number of existing items is greater than or equal to the maximum number of items that can be in the array
		{
			cout << "ERROR" << endl;
		}
	}
}
void findPrice(Item store[], int numItems)//function that finds the price of an item
{
	int code,i;
	bool flag = false;//Defining a boolean variable marked false
	cout << "enter code: " << endl;
	cin >> code;//Receiving the requested item code
	for (i = 0; i < numItems; i++)//Go over the array of items
	{
		if (store[i].code == code)//Checking whether the requested item exists in the array, if so, turning the mark to true
		{
			flag = true;
			break;
		}
	}
	if (flag)//In case the sign is true, meaning the item exists, its price will be printed
		cout << "price: " << store[i].price << endl;
	else//If the item does not exist, an error is printed
		cout << "ERROR" << endl;
}
void sold(Item store[], int numItems)//function that calculates the sale of items
{
	int code,amount,i;
	cout << "enter code :" << endl;
	cin >> code;//Receiving the requested item code
	cout << "enter amount :" << endl;
	cin >> amount;//Receipt of the quantity of the requested item
	for (i = 0; i < numItems; i++)//Go over the array of items
	{
		if (store[i].code == code)
		{
			store[i].amount -= amount;//Subtracting the quantity purchased from the quantity in stock
			break;
		}
	}
	if (store[i].amount < 0)//If the quantity ordered is greater than the quantity in stock, the quantity in stock is calculated as 0 and not as a minus
		store[i].amount = 0;
}
void order(Item store[], int numItems)//function that calculates an order of items
{
	for (int i = 0; i < numItems; i++)//A loop that goes through the entire array of items
	{
		if (store[i].amount < store[i].minamount)//Checking if the quantity is less than the minimum quantity
		{
			cout << "item name :" << store[i].name << endl;
			cout << "code :" << store[i].code << endl;
			cout<<"amount to order :"<< store[i].minamount + 5 - store[i].amount<<endl;//Calculate the order quantity so that it is 5 more than the minimum
			store[i].amount = store[i].minamount + 5;//Quantity calculation after ordering
		}
	}
}
void print(Item store[], int numItems)//function that prints the items in the store with all their details
{
	for (int i = 0; i < numItems; i++)//A loop that goes through the entire array of items and prints each item and all its details
	{
		cout << "code: "<<store[i].code << endl;
		cout << "name: "<<store[i].name << endl;
		cout << "amount: "<<store[i].amount << endl;
		cout << "minamount: "<<store[i].minamount << endl;
		cout << "price: "<<store[i].price << endl;
	}
}

//exemple:
//enter max number of items :
//5
//enter 0 - 5 :
//	1
//	enter code :
//11
//enter name :
//r
//enter amount :
//3
//enter minimum amount :
//1
//enter price :
//4
//enter 0 - 5 :
//	1
//	enter code :
//33
//enter name :
//w
//enter amount :
//5
//enter minimum amount :
//7
//enter price :
//8
//enter 0 - 5 :
//	5
//	code : 11
//	name : r
//	amount : 3
//	minamount : 1
//	price : 4
//	code : 33
//	name : w
//	amount : 5
//	minamount : 7
//	price : 8
//	enter 0 - 5 :
//	1
//	enter code :
//11
//enter name :
//r
//enter amount :
//6
//enter minimum amount :
//8
//enter price :
//9
//enter 0 - 5 :
//	5
//	code : 11
//	name : r
//	amount : 9
//	minamount : 8
//	price : 9
//	code : 33
//	name : w
//	amount : 5
//	minamount : 7
//	price : 8
//	enter 0 - 5 :
//	2
//	enter code :
//11
//price : 9
//enter 0 - 5 :
//	3
//	enter code :
//33
//enter amount :
//2
//enter 0 - 5 :
//	5
//	code : 11
//	name : r
//	amount : 9
//	minamount : 8
//	price : 9
//	code : 33
//	name : w
//	amount : 3
//	minamount : 7
//	price : 8
//	enter 0 - 5 :
//	4
//	item name : w
//	code : 33
//	amount to order : 9
//	enter 0 - 5 :
//	0
