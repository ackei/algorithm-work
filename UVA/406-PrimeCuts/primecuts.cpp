#include <iostream>
using namespace std;


void fillPrimes(int& N, int* primes, int& size) {

	//cout << "Initial Primes" << endl;
	primes[0] = 1;
	primes[1] = 2;
	size = 2;

	//cout << "Filling Primes" << endl;
	for (int i = 3; i < N; i++) {
		
		for(int j = 1; i%(primes[j]) ; j++) 
		{ 
			if (j == size-1) {
				primes[size++] = i;
				j = 0;
			}
		}
	}
}

void primeCuts(int N, int C, int* primes, int size) {

	fillPrimes(N, primes, size);
	//cout << "Completed Function Call" << endl;

	cout << N << " " << C << ": ";

	if (C < size/2) {
		if (size%2) {
			int k = size/2;
			for (int i = k - C + 1; i < k+C; i++)
			{
				cout << primes[i] << " ";
			}
		}
		else
		{
			int k = size/2;
			for (int i = k - C; i < k+C; i++) {
				cout << primes[i] << " ";
			}
		}
	}
	else {

		for (int i = 0; i < size; i++) {
				cout << primes[i] << " ";
			}

	}

	cout << endl;

}

int main() {

	int n, C, size = 1000, primes[size];
	
	while(cin >> n && cin >> C) {
		primeCuts(n, C, primes, size);	
	}

	return 0;

}
