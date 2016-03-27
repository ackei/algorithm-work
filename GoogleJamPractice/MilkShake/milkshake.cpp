#include <iostream>
#include <vector>
using namespace std;


int otherindex(int m) {
	if (m & 1) {
		return m-1;
	}
	else {
		return m+1;
	}
}

bool foo(vector< vector<int> > clikes, int c, int last_m, int* milkshakes) {
	vector< vector<int> > temp = clikes;
	int other = otherindex(last_m);
	if (last_m != -1) {
		for (int i = c; i < temp.size(); i++) {
			for (vector<int>::iterator it = temp[i].begin(); it != temp[i].end(); it++) {
				if (*it == other) {
					temp[i].erase(it);
					it--;
				}
			}
			if (temp[i].size() == 0) {
				return false;
			}
		}


		milkshakes[last_m] = 1;
		milkshakes[other] = 0;
	}

	if (c == clikes.size())  { return true; }
	
	for (int j = 0; j < temp[c].size(); j++) {
		
		if (foo(temp, c+1, temp[c][j], milkshakes)) {
			return true;
		}	
	}

	if (last_m != -1) {
		milkshakes[last_m] = 0;
		milkshakes[other] = 0;
	}

	return false; 
	
}

int main() {

	int numcases;
	cin >> numcases; 
	for(int count = 0; count < numcases; count++) {
		int numc, numm;
		cin >> numm >> numc;   
		vector< vector<int> > likes;
		vector<int> temp;
		for (int i = 0 ; i < numc; i++) {
			likes.push_back(temp);
			int numlikes; 
			cin >> numlikes; 
			for (int j = 0 ; j < numlikes; j++) {
				int a, b; 
				cin >> a >> b;
				likes[i].push_back(((a-1) << 1) + b);
			}
		}
	
		int milkshakes[2*numm];	
		for (int i = 0; i < 2*numm; milkshakes[i++] = 0);
		cout << "Case #" << count+1 << ": ";	
		if (foo(likes, 0, -1, milkshakes)) {
			for (int i = 0; i < 2*numm; i += 2) {
				if ((milkshakes[i] == 0) && (milkshakes[i+1] == 1)) {
					cout << 1;
				}
				else {
					cout << 0;
				}
				if (i < 2*(numm-1)) { cout << " "; }
				else { cout << endl; } 
			}
		} 
		else {
			cout << "IMPOSSIBLE" << endl;
		}
		
	}
	return 0;
}
