#include <iostream>
#include <vector>
using namespace std;

class SA {

	public:
		SA(int n) { 
			this->array = new int[n]; 
			this->size = 0;
			this->capacity = n; 
		}	
		void insert(int n) {
			if (this->size < this->capacity) {
				int i;
				for (i = 0; i < size; i++) {
					if (this->array[i] > n) { break; }
				}
				for (int j = size; j > i; j--) {
					this->array[j] = this->array[j-1];
				}
				this->array[i] = n;
				this->size++;
			}
		}
		int findTopIndex(int k) { 
			int i;
			for (i = 0; i < this->size; i++) {
				if (this->array[i] > k) { break; }
			}
			return i - 1;
		}
		int operator[](int i) {
			return array[i];
		}		
		int size;

	private:
		int* array;
		int capacity;
};

int main() {

	int numCases;
	cin >> numCases; //cout << "NumCases: " << numCases << endl;
	while (numCases--) {
		int total, numGarments, numgarm;
		cin >> total; cin >> numGarments;// cout << "NumGarments: " << numGarments << endl;
		vector<SA> gi; numgarm = numGarments;
		while (numGarments--) {
			int numElements;
			cin >> numElements; //cout << "NumElements: " << numElements << endl;
			SA temp(numElements);
			while (numElements--) {
				int value;
				cin >> value;
				temp.insert(value);
			}
			gi.push_back(temp);
		}

		//cout << "Creating Table" << endl;
		int DPTable[total+1][numgarm];
		
		//cout << "Initial Conditions" << endl;
		for (int i = 0; i < total+1; i++) {
			if (gi[0].findTopIndex(i) == -1) {
				DPTable[i][0] = 1 << 30;
			}
			else {
				DPTable[i][0] = i - gi[0][gi[0].findTopIndex(i)];
			}			
		}

		//cout << "Recursion" << endl;
		for (int k = 1; k < numgarm; k++) {
			for (int i = 0; i < total+1; i++) {
				//cout << i << " " << k << endl;
				if (gi[k].findTopIndex(i) == -1) {
					DPTable[i][k] = 1 << 30;
				}
				else {
					int temp = DPTable[i - gi[k][0]][k-1];
					for (int j = 0; j <= gi[k].findTopIndex(i); j++) {
						if ( DPTable[i - gi[k][j]][k-1] < temp) {
							temp = DPTable[i-gi[k][j]][k-1];
						}
					}
					DPTable[i][k] = temp;
				}
			}
		}
		
		if (DPTable[total][numgarm-1] == (1 << 30)) { cout << "no solution" << endl; }
		else { cout << total - DPTable[total][numgarm-1] << endl; }

	}
	return 0;
}

