#include <iostream>
using namespace std;

int cyclelength(int n) {
	int seq = n;
	int count = 1;
	while (seq != 1) {
		if ((seq & 1) == 1) {
			seq = 3*seq + 1;
		}
		else {
			seq = seq / 2;
		}
		count++;
	}
	return count;
}

int main() {

	int x, y, max, min;
	while (cin >> x >> y) {
		max = (x > y) ? x : y;
		min = (x < y) ? x : y;

		int ans = cyclelength(min);
		for (int i = min+1 ; i < max+1; i++) {
			int temp = cyclelength(i);
			if (temp > ans) { ans = temp; } 
		}
		cout << x << " " << y << " " << ans << endl;

	}

	return 0;
}