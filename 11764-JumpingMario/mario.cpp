#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

template<class T>
class cdiff {
	private:
		T c;
	public:
		cdiff(T x) { c = x; }
		T operator() (const T& x) { 
			T temp = x - c;
			c = x; 
			return temp; 
		}

};

int main() {

	int numcases;
	cin >> numcases;
	for (int i = 0; i < numcases; i++) {
		int size; cin >> size;
		vector<int> array(size);
		for (int j = 0; j < size; cin >> array[j++]);
		transform(array.begin(), array.end(), array.begin(), cdiff<int>(array[0]));
		int up = count_if(array.begin(), array.end(), bind2nd(greater<int>(), 0));
		int down = count_if(array.begin(), array.end(), bind2nd(less<int>(), 0));
		cout << "Case " << i+1 << ": " << up << " " << down << endl;
	}
	return 0;
}
