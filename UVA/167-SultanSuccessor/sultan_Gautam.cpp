#include <iostream>
#include <cstdlib>
using namespace std;

// Finds just one solution to 8 queens problem
#define SIZE_CB 4


int row(int i)
{
	return i/SIZE_CB;
}

void sameRow(int i, bool chessBD[]) {
	int j = SIZE_CB*(i / SIZE_CB);
	int k = j + SIZE_CB;
	for (int l = j; l < k; chessBD[l++] = true);
}

void sameColumnBigger(int i, bool chessBD[]) {
	
	for (int j = i; j < SIZE_CB*SIZE_CB; j += SIZE_CB) 
	{ 
		chessBD[j] = true;	
	}

}

void sameColumnSmaller(int i, bool chessBD[]) {
	for (int j = i; j > -1; j -= SIZE_CB) {
		chessBD[j] = true;
	}
}

void sameMainDiagonalBigger(int i, bool chessBD[]) {

	for (int j = i; (j < SIZE_CB*SIZE_CB) && (row(j) == row(j-(SIZE_CB+1)) + 1) ; j += (SIZE_CB+1))
	{
		chessBD[j] = true;
	}
}

void sameMainDiagonalSmaller(int i, bool chessBD[]) {

	for (int j = i; (j > -1) && (row(j) == row(j+(SIZE_CB-1)) - 1) ; j -= (SIZE_CB+1))
	{
		chessBD[j] = true;
	}
}

void sameOffDiagonalBigger(int i, bool chessBD[]) {

	for (int j = i; (j < SIZE_CB*SIZE_CB) && (row(j) == row(j-(SIZE_CB-1)) + 1); j += (SIZE_CB-1)) 
	{
		chessBD[j] = true;
	}
}

void sameOffDiagonalSmaller(int i, bool chessBD[]) {

	for (int j = i; (j > -1) && (row(j) == row(j-(SIZE_CB-1)) - 1); j -= (SIZE_CB-1)) 
	{
		chessBD[j] = true;
	}
}

int main() {

	int size = SIZE_CB*SIZE_CB;
	bool chessBD[size]; 
	int queens[SIZE_CB];
	for (int i = 0; i < size; chessBD[i++] = false);
	srand(time(0));
	for (int j = 0; j < SIZE_CB; j++)
	{
		int k;
		bool allfilled = true;
		for (k = 0; chessBD[k]; k = rand()%size);
		cout << k << " ";
		chessBD[k] = true;
		queens[j] = k;
		sameRow(k, chessBD);
		sameColumnBigger(k, chessBD);
		sameColumnSmaller(k, chessBD);
		sameMainDiagonalBigger(k, chessBD);
		sameMainDiagonalSmaller(k, chessBD);
		sameOffDiagonalBigger(k, chessBD);
		sameOffDiagonalSmaller(k, chessBD);

		for (int i = 0; i < size; i++)
		{
			if (!chessBD[i])
			{
				allfilled = false;
			}
		}


		if (allfilled)
			break;
	}
	
	cout << endl;

	return 0;

}
