#include <iostream>
#include <string>
using namespace std;

void function(string* a, int x, int y, int i, int j) {

	if ((i - 1) >= 0) {
		if ((j - 1) >= 0) {
			if (a[i-1][j-1] != '*') { a[i-1][j-1] += 1 ; }
		}
		if (a[i-1][j] != 0) { a[i-1][j] += 1; }
		if ((j+1) < y) {
			if (a[i-1][j+1] != '*') { a[i-1][j+1] += 1; }
		}
	}

	if ((j - 1) >= 0) {
		if (a[i][j-1] != '*') { a[i][j-1] += 1; }
	}
	if ((j+1) < y) {
		if (a[i][j+1] != '*') { a[i][j+1] += 1; }
	}

	if ((i+1) < x) {
		if ((j - 1) >= 0) {
			if (a[i+1][j-1] != '*') { a[i+1][j-1] += 1; }
		}
		if (a[i+1][j] != '*') { a[i+1][j] += 1; }
		if ((j+1) < y) {
			if(a[i+1][j+1] != '*') { a[i+1][j+1] += 1; }
		}
	}	

}

int main() {

	int x,y;
	while(cin >> x >> y, x && y) {
		
		string a[100];
		for (int i = 0; i < x; i++) { cin >> a[i]; }

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < a[i].length(); j++) {
				if (a[i][j] != '*') {
					a[i][j] = '0';
				}
			}	
		}
		
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < a[i].length(); j++) {
				if (a[i][j] == '*') {
					function(a, x, y, i, j);
				}
			}	
		}
	
		for (int i = 0; i < x; i++) { cout << a[i] << endl; }

	}

	return 0;
}
