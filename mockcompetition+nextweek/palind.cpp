#include <iostream>
#include <string>
using namespace std;

bool pal_recur(string s) {
	int x = s.length();
	if (x == 1 || x == 0) { return true;}
	if (s[0] == s[x-1]) {
		return pal(s.substr(1, x-2));
	}
	else {
		return false;
	}
}

bool pal_loop(string s) {
	int x = s.length();
	while (int i = 0; i < (x/2); i++) {
		if (s[i] != s[x-i-1]) {
			return false;
		}
	}
	return true;

}

int main() {

	string s = "";
	while (cin >> s) {
		cout << pal(s) << endl;
	}
	return 0;
}