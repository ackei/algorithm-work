#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

ull md = 1001113;

int main() {
	
	ull arr[105][105];
	arr[0][0] = arr[1][0] = arr[1][1] = 1;
	for (int i = 2; i < 105; i++) {
		arr[i][0] = arr[i][i] = 1;
		for (int k = 1; k < i; k++) {
			arr[i][k] = (k+1)*arr[i-1][k] + (i-k+1)*arr[i-1][k-1];
			arr[i][k] %= md;	
		}
	}


	int TC;
	cin >> TC;
	while(TC--) {
		ull C, N, n, K;
		cin >> C >> N >> K;
		n = N - 1;
		cout << C << " " << arr[n][K] << endl;
	}

	return 0;
}
