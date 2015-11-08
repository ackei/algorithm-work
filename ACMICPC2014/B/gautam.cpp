#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {

	int numCases;
	scanf("%i\n", &numCases);
	int count;
	
	while (numCases--) {
		vector<int> seq;
		int temp; char temp2;

		scanf("%i%c", &temp, &temp2);
		count = temp;

		while (scanf("%i%c", &temp, &temp2) != EOF) {
			
			if (temp2 == ' ') {
				seq.push_back(temp);
			}	
			else {
				seq.push_back(temp);
				break;	
			}

		
		}
		vector< vector<int> > table; 

		for (int i = 0; i < seq.size(); i++) {
			if ( seq[i] < seq[i+1] ) {
				vector<int> temp; 
				temp.push_back(seq[i]); temp.push_back(seq[i+1]); temp.push_back(1); temp.push_back(0);
				table.push_back(temp);
			}
			if ( seq[i] > seq[i+1]) {
				for (int j = 0; j < table.size(); j++) {
					if (table[j][3] == 0) {
						if (seq[i+1] <= table[j][0]) {
							table[j][3] = 1;
						}
						else if (seq[i+1] < table[j][1]) {
							table[j][2]++; table[j][1] = seq[i+1];
						}	
					}
				}
			}
		}		
		
		int sum = 0;
		for (int i = 0; i < table.size(); i++) {
			if (table[i][3] == 1) {
				sum += table[i][2];
			}
		}

		
		cout << count << " " << sum << "\n"; 
	}	

	return 0;
}
