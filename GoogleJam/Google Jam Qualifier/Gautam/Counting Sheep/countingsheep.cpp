#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

template<class T>
class dgtaccum {
	private:
		bool b[10];
	public:
		dgtaccum() {
			for (int i = 0; i < 10; b[i++] = 0);
		}
		bool operator() (const T& x) {
			T y = x; 
			T z;
			while (y != 0) {	
				z = y%10;
				b[z] = 1;	
				y = y/10;
			}
			return accumulate(b, b+10, 1, logical_and<bool>());
		}

};

int main() {

	int numcases; cin >> numcases;
	for (int i = 0; i < numcases; i++) {
		int N;
		cin >> N;
		int size = 1000;
		vector<int> multiples(size);
		for (int i = 0; i < size; i++, multiples[i] = N*i);
		vector<int>::iterator it = find_if(multiples.begin(), multiples.end(), dgtaccum<int>()); 
		string ans = (it == multiples.end() ? "INSOMIA" : to_string(*it)); 
		cout << "Case #" << i+1 << ": " << ans << endl;
	}

	return 0;
}
