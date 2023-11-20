//Ruti Tenenboim 214360778
//Mavo Lemadaei Hamachshev.
//Week4 Exe1
//The program generates ten integers between 1 and 1000 (inclusive),
//prints the numbers and whether they are sorted or not.

#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int i = 0,help=0;
	bool flag = true;
	int num = rand() % (1000) + 1;//Lottery of numbers between one and a thousand, inclusive.
	cout << num << " ";
	help = num;
	while (i < 9)//A loop that lottery 10 numbers between one and a thousand, inclusive.
	{
		num = rand() % (1000) + 1;//placement un num
		cout << num << " ";
		if (num<help)//Checking whether the numbers are not sorted.
			flag = false;
		help = num;//placement help
		i++;//The promotion of the i.
	}
	if (flag)
		cout << endl<<"sorted list" << endl;//
	else
		cout << endl<<"not sorted list" << endl;//


	return 0;
}


//exemple:
//690 476 710 373 942 31 717 455 752 878
//not sorted list