#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {

	int n;
	string x1;
	string x2;
	string a = "";
		
	while (cin >> n, n) {

		getline(cin, a, '\n');
		
		cout << n << " " << a << endl;
	}
		
	return 0;
}
