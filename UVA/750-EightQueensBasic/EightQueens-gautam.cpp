#include <iostream>
using namespace std;

// Use a 0-7 scale

int dist(int i, int j) {

	if (i > j) { return i-j; }
	else { return j-i; }

}

int count, r, c;

void printSeq(int array[8]) {
	cout <<  " " << count++ << "      ";
	for (int j = 0; j < 8; j++) {
		if (j < 7) 
			cout << array[j] + 1 << " ";
		else
			cout << array[j] + 1 << endl;
	}
}

void EQ(int queenIndex, int array[8]) {

	if (queenIndex == c) { array[c] = r; EQ(++queenIndex, array); }

	for (int i = 0; i < 8; i++) {
		if (i == r) { continue; }
		
		// Check with previous queen configs
		bool check = true;
		
		for (int j = 0; j < queenIndex; j++) {
			if (j == c) { continue; }
			check =  check && (dist(array[j], i) != dist(j, queenIndex)) && (i != array[j]);
			//cout << check <<  endl;
		}
		check = check && (i != r);

		if (check) {
			array[queenIndex++] = i;
			if (queenIndex < 8) { EQ(queenIndex, array); }
			if (queenIndex == 8) { printSeq(array); }
		}
	}
}


int main() {

	int numDataSets; cin >> numDataSets;
	while (numDataSets--) {
		cin >> r; cin >> c;
		r = r-1; c = c-1;
		int array[8]; 
		count = 1;
		EQ(0, array);
	}
	return 0;
}
