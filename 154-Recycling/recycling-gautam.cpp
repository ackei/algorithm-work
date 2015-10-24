#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int convColorToInt(char c) {
	
	if (c == 'r') { return 0; }
	if (c == 'o') { return 1; }
	if (c == 'y') { return 2; }
	if (c == 'g') { return 3; }
	if (c == 'b') { return 4; }

	return -1;
}

int convWasteToInt(char c) {

	if (c == 'P') { return 0; }
	if (c == 'G') { return 1; }
	if (c == 'S') { return 2; }
	if (c == 'A') { return 3; }
	if (c == 'N') { return 4; }

	return -1;
}

int checkDifference(int* v1, int* v2, int size) {
	
	int count = 0;
	for (int i = 0; i < size; i++) {
		int x = *(v1 + i);
		int y = *(v2 + i);
	
		if (x != y) { count++; }
	}
	return count;
}

// Values -> 100 x 5
// Matrix of Differences -> n x n 

int main() {

	string unwanted;
	do {
		char color, waste;
		int values[500], numcities = 0, bininfo = 0;
		while (scanf("%c/%c,", &color, &waste)) {
			
			if (color == 'e') { break; }
			else if (color == '#') { return 0; }
			else if (color == '\n') { continue; }
			else if ((convColorToInt(color) != -1) && (convWasteToInt(waste) != -1)) {
				values[ 5*numcities + convWasteToInt(waste) ] = convColorToInt(color);
				bininfo++;
				if (bininfo == 5) {
					bininfo = 0;
					numcities++;
				}
			}
			else {
				cout << "Something is wrong " << color << " " << waste << endl;
			}
		}

		int mat[numcities*numcities], scores[numcities], ans = 0, ansScore = 5*numcities; 
		for (int i = 0; i < numcities*numcities; mat[i++] = 0);

		for (int i = 0; i < numcities; i++) {
			for (int j = i+1; j < numcities; j++) {
				mat[numcities*i + j] = mat[numcities*j + i] = checkDifference(&values[5*i], &values[5*j], 5);
				//cout << i <<  " " << j << " " << checkDifference(&values[5*i], &values[5*j], 5) << endl;
			}
		}

	
		for (int i = 0; i < numcities; i++) {
			int temp = 0;
			for (int j = 0; j < numcities; j++) {
				temp += mat[numcities*i + j];
			}
			if (temp < ansScore) { ans = i; ansScore = temp; }


		}

		cout << ans+1 << endl;


	} while(getline(cin, unwanted));

	return 0;
}
