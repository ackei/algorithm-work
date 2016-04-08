#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <cstdint>
using namespace std;

template<class S>
class revbytes {
	public:
		// Assume S is a 4-byte type, C is 1 byte type
		string operator() (S num) {
			S x = num;
			char *cptr = reinterpret_cast<char*>(&x);
			char temp = cptr[0]; cptr[0] = cptr[3]; cptr[3] = temp;
			temp = cptr[1]; cptr[1] = cptr[2]; cptr[2] = temp;
			S y = *(reinterpret_cast<S*>(cptr));
			string ans = to_string(num) + " converts to " + to_string(y);
			return ans;
		}

};

int main() {

	vector<int32_t> array;
	copy(istream_iterator<int32_t>(cin),istream_iterator<int32_t>(),back_inserter(array));	
	vector<string> narray(array.size());
	transform(array.begin(), array.end(), narray.begin(), revbytes<int32_t>());
	copy(narray.begin(), narray.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}
