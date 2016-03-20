#include <iostream>
#include <vector>
#include <string>
using namespace std;

void incr(char& c) {
	if (c != '*') { c++; }
}

int main() {

	int x,y;
	int count = 1;

	while (cin >> x >> y && x && y) {

		vector<string> num;
		// Create temp string
		string temp = "";
		while (y--) {
			temp += "0";
		}
		y = temp.length();
		temp += "00";

		num.push_back(temp);
		while (x--) {
			string temp2;
			cin >> temp2;
			for (int i = 0 ; i < temp2.length(); i++) { if (temp2[i] != '*') { temp2[i] = '0'; } }
			temp2 = "0" + temp2 + "0";
			num.push_back(temp2);
		}
		x = num.size()-1;
		num.push_back(temp);

		for (int i = 1 ; i < x+1 ; i++) {
			for (int j = 1; j < y+1; j++) {			
				if (num[i][j] == '*') {	
					incr(num[i-1][j]);
					incr(num[i+1][j]);
					incr(num[i-1][j+1]);
					incr(num[i+1][j+1]);
					incr(num[i][j+1]);
					incr(num[i-1][j-1]);
					incr(num[i+1][j-1]);
					incr(num[i][j-1]);
				}		
			}
		}
		if (count != 1) { cout << endl; }
		cout << "Field #" << count << ":" << endl;
		for (int i = 1 ; i < x+1 ; i++) {
			for (int j = 1; j < y+1; j++) {
				cout << num[i][j];
			}
			cout << endl;
		}

		count++;
	} 

	return 0;
}