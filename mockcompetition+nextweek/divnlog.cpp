#include <iostream>
using namespace std;

int main() {

	int numcases, x, y, ox, oy;
	while((cin >> numcases) && numcases) {
		cin >> ox >> oy;
		while (numcases--) {
			cin >> x >> y;
			x -= ox;
			y -= oy;
			if (x == 0 | y == 0) {
				cout << "divisa" << endl;
			}
			else if (x > 0 && y > 0) {
				cout << "NE" << endl;
			}
			else if (x > 0 && y < 0) {
				cout << "SE" << endl;
			}
			else if (x < 0 && y > 0) {
				cout << "NO" << endl;
			}
			else {
				cout << "SO" << endl;
			}
		}
	}

	return 0;
}