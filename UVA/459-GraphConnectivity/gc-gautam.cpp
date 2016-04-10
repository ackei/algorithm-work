#include <iostream>
#include <string>
using namespace std;


int main() {


	char maxLetter; 
	cin >> maxLetter;
	int num = (int)maxLetter - (int)'A' + 1;

	int array[num]; for (int i = 0; i < num; array[i] = i++);
	int ans = num;

	string edge;
	while (cin >> edge) {
		if (edge == "") { break;}
		else {
			int node1 = (int)(edge.c_str()[0]) - (int)'A';
			int node2 = (int)(edge.c_str()[1]) - (int)'A';
			if (array[node1] != array[node2]) {
				int max = ((array[node1] > array[node2]) ? array[node1] : array[node2]);
				int min = ((array[node1] < array[node2]) ? array[node1] : array[node2]);
				for (int i = 0 ; i < num; i++) {
					if (array[i] == max) {
						array[i] = min;
					}
				}
				ans--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

