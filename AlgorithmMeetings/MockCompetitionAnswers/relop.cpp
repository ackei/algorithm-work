#include <iostream>
using namespace std;

int main() {

	int x,y,z;

	cin >> x;

	while (x--) {
		cin >> y; cin >> z;
		if (y > z) {
			cout << ">" << endl;
		}
		else if (y < z) {
			cout << "<" << endl;
		}
		else {
			cout << "=" << endl;
		}
	}

	return 0;
}
