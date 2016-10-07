#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<class T>
class incr {
	private:
		T c;
	public:
		incr() {
			c = 1;
		}
		T operator() (T x) {
			if (c == 1 && x == 1) { c = 1; x = 0; }	
			else if (c == 1 && x == 0) { c = 0; x = 1; }
			return x;
		}
};


int main() {

	int numcases; cin >> numcases;
	for (int i = 0; i < numcases; i++) {
		int numdigits, numanswers;
		cin >> numdigits >> numanswers;
		vector<bool> temp(numdigits);
		temp[0] = 1; temp[numdigits-1] = 1;
			for (int i = 0; i < (1 << (numdigits-2)); i++) {
				copy(temp.begin(), temp.end(), ostream_iterator<bool>(cout, " "));
				cout << endl;
				transform(++temp.rbegin(), temp.rend(), ++temp.rbegin(), incr<bool>());
			}
	}
}
