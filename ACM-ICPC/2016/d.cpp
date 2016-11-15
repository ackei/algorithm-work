#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

int main() {

	int TC;
	cin >> TC;
	while(TC--) {
		int C;
		ull N;
		cin >> C >> N;
		
		ull i = 0, M = N, p = 1, q = 1;

		while(M != 1) {
			M = (M >> 1);
			i++;
		} 
		while(i--) {
			if (N & (1 << i)) {
				p = p + q;
			}
			else {
				q = p + q;
			}
		}

		printf("%d %llu/%llu\n", C, p, q);

		
	}
	
	return 0;

}
