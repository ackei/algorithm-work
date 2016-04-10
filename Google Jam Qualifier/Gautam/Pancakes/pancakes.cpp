#include <iostream>
#include <numeric>
#include <string>
using namespace std;

template<class T, class C>
class accflips {

	public:
		accflips(C first) {
			c = first;
		}
		T operator() (T num, C nc) {
			if (nc != c) { num++; }
			c = nc;
			return num;
		}
	private:
		C c;
};

int main() {

	int numcases; cin >> numcases;
	for (int i = 0; i < numcases; i++) {
		string s; cin >> s;
		char last = s[s.length()-1];
		int t = ((last == '+') ? 0:1);
		int answer = accumulate(s.begin(), s.end(), t, accflips<int, char>(s[0]));
		cout << "Case #" << i+1 << ": " << answer << endl;
	}
	return 0;
}
