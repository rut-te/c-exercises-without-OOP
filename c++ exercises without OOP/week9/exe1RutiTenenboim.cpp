//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week9 Exe1
//Dynamic allocation
//the program calculate some calculations about buses, according to the data that the user entered.

#include<iostream>
using namespace std;
enum choices {EXIT, ADD, DELETE, PRINT, SEARCH, AVG_TRAVEL, AVG_STOPS,SHORTEST_TRAVEL};
void addLine(int**& buses, int& numBuses, int line, int stops, int durationOfRide);
void deleteLine(int**& buses, int& numBuses, int line);
int search(int** buses, int numBuses, int line);
float averageTravel(int** buses, int numBuses);
float averageStops(int** buses, int numBuses);
int shortest(int** buses, int numBuses);
void print(int** buses, int numBuses);
int main()
{
    int** buses= nullptr;
	int numBuses = 0;
	int line;
	int stops;
	int durationOfRide;
	int choice;
	do {
		cout << "enter 0-7" << endl;
		cin >> choice;
		switch (choice) {
		case ADD: // add a line to the array of buses
			cout << "enter the line to add" << endl;
			cin >> line;
			cout << "enter the number of stops" << endl;
			cin >> stops;
			cout << "enter the duration of the ride" << endl;
			cin >> durationOfRide;
			addLine(buses, numBuses, line, stops, durationOfRide);
			print(buses, numBuses); 
			break;
		case DELETE: // delete a line from the array of buses
			cout << "enter the line to delete" << endl;
			cin >> line;
			deleteLine(buses, numBuses, line);
			print(buses, numBuses);
			break;
		case PRINT: // print all lines
			print(buses, numBuses);
			break;
		case SEARCH: // search for a particular line
			cout << "enter the line to search for" << endl;
			cin >> line;
			cout << search(buses, numBuses, line) << endl;
			break;
		case AVG_TRAVEL: // calculate average travel time of all buses
			cout << averageTravel(buses, numBuses) << endl;
			break;
		case AVG_STOPS: // calcuate average stops of all buses
			cout << averageStops(buses, numBuses) << endl;
			break;
		case SHORTEST_TRAVEL:// calculate the bus with the shortest travel time
			cout << shortest(buses, numBuses) << endl;
			break;
		case EXIT: 
			break; // exit the program
		default: cout << "ERROR" << endl;
		}// switch
	} while (choice != 0);
	for (int i = 0; i < numBuses; i++)
		delete[] buses[i];
	if (numBuses > 0)
		delete[] buses;
	return 0;
}
void print(int** buses, int numBuses) 
{
	for (int i = 0; i < numBuses; i++) { // for each bus that is present in the database
	//int * oneBus = *(buses + i);// store the bus’ data in oneBus
		for (int j = 0; j < 3; j++) { // prints the 3 pieces of data of the bus
			cout << *(*(buses + i) + j) << " ";
			//cout << *(oneBus + j);
			//cout << " ";
		}
		cout << endl;
	}
}
void addLine(int**& buses, int& numBuses, int line, int stops, int durationOfRide)
{
	if (numBuses != 0)
	{
		if (search(buses, numBuses, line) == -1)
		{
			int** newMat = new int* [numBuses + 1];
			if (!newMat)
			{
				cout << "ERROR" << endl;
			}
			int i = 0, copy = 0, help = 0;
			for (; i < numBuses; i++)
			{
				if (line > buses[i][0] || copy == 1)
				{
					newMat[i] = buses[help];
					help++;
				}
				else
				{
					newMat[i] = new int[3];
					newMat[i][0] = line;
					newMat[i][1] = stops;
					newMat[i][2] = durationOfRide;
					copy = 1;
				}
			}
			if (help + 1 == i)
			{
				newMat[i] = buses[i - 1];
			}
			else
			{
				newMat[i] = new int[3];
				newMat[i][0] = line;
				newMat[i][1] = stops;
				newMat[i][2] = durationOfRide;
			}
			delete[] buses;
			buses = newMat;
			numBuses++;
		}
	}
	else
	{
		buses = new int* [1];
		*buses = new int[3];
		buses[0][0] = line;
		buses[0][1] = stops;
		buses[0][2] = durationOfRide;
		numBuses++;
	}

}
void deleteLine(int**& buses, int& numBuses, int line)
{
	if (search(buses, numBuses, line) != -1)
	{
		int i = 0,j=0;
		int** newMat = new int* [numBuses - 1];
		for (; i < numBuses; i++)
		{
			if (buses[i][0] != line)
			{
				newMat[j] = buses[i];
				j++;
			}
		}
		delete[] buses;
		buses = newMat;
		numBuses--;
	}

}
int search(int** buses, int numBuses, int line)
{
	for (int i = 0; i < numBuses; i++)
	{
		if (buses[i][0] == line)
			return i;
	}
	return -1;
}
float averageTravel(int** buses, int numBuses)
{
	float time = 0;
	if (numBuses == 0)
		return 0;
	for (int i = 0; i < numBuses; i++)
	{
		time += *(*(buses + i) + 2);
	}
	return time/numBuses;
}
float averageStops(int** buses, int numBuses)
{
	float stops = 0;
	if (numBuses == 0)
		return 0;
	for (int i = 0; i < numBuses; i++)
	{
		stops += *(*(buses + i) + 1);
	}
	return stops/numBuses;
}
int shortest(int** buses, int numBuses)
{
	bool flag = false;
	int help = buses[0][2];
	int i;
	for (i = 0; i < numBuses; i++)
	{
		if (help > buses[i][2])
		{
			help = buses[i][2];
			flag = true;
		}
	}
	if (!flag)
		return buses[0][0];
	return buses[i][0];
}

//exemple:
//enter 0 - 7
//1
//enter the line to add
//2
//enter the number of stops
//34
//enter the duration of the ride
//56
//2 34 56
//enter 0 - 7
//1
//enter the line to add
//6
//enter the number of stops
//67
//enter the duration of the ride
//90
//2 34 56
//6 67 90
//enter 0 - 7
//3
//2 34 56
//6 67 90
//enter 0 - 7
//1
//enter the line to add
//3
//enter the number of stops
//40
//enter the duration of the ride
//30
//2 34 56
//3 40 30
//6 67 90
//enter 0 - 7
//4
//enter the line to search for
//2
//0
//enter 0 - 7
//4
//enter the line to search for
//3
//1
//enter 0 - 7
//5
//58.6667
//enter 0 - 7
//6
//47
//enter 0 - 7
//7
//3
//enter 0 - 7
//2
//enter the line to delete
//3
//2 34 56
//6 67 90
//enter 0 - 7
//7
//2
//enter 0 - 7
//6
//50.5
//enter 0 - 7
//5
//73
//enter 0 - 7
//8
//ERROR
//enter 0 - 7
//0
