#include <iostream>
using namespace std;

#define PRINT false

int main() {

	#if PRINT
	cout << "Enter number of pairs: ";
	#endif
	int n,i,j;
	cin >> n;
	while (n--) 
	{
		cin >> i; cin >> j;
		cout << ((i == j) ? "=" : (i > j) ? ">" : "<") << endl;
	}

	return 0;
}
