#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long smallest(vector<long long> x, vector<long long> y) {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long long ans = 0; 
	for (int i = 0 ; i < x.size(); i++) {
		ans += x[i]*y[x.size() - i - 1];	
	}
	return ans;
}

int main() {

	int numcases, temp2;
	cin >> temp2;
	numcases = temp2;
	while (numcases--) {
		int size;
		vector<long long> x,y;
		cin >> size;
		for (int i = 0; i < size; i++) {
			long long temp;
			cin >> temp;
			x.push_back(temp);
		}

		for (int i = 0; i < size; i++) {
			long long temp;
			cin >> temp;
			y.push_back(temp);
		}
		
		long long ans = smallest(x,y);
		cout << "Case #" << temp2 - numcases << ": " << ans << endl;
	}

	return 0;
}
