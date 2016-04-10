#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

// 0-5000
long long table[50005/5][12];
int denom[12] = {0,1,2,4,10,20,40,100,200,400, 1000, 2000 };

long long tableVal(int i, int j) {
	if (i < 0 || j < 0) {
		return 0;
	}
	else { 
		return table[i][j];
	}
}

int main() {
	
	double d;
	while(cin >> d) {
		int index = (int)(round(d*100));
		if (index == 0) { break; }
		if (index%5 != 0) {
			cout << setw(6) << setprecision(2) << fixed << d << setw(17) << 0 << endl;
			continue;
		} 

		index /= 5;	
		
		// Initialization
		//memset(table, 0, sizeof table); 
		for (int i = 0; i < 10001; table[i++][0] = 0);
		for (int j = 0; j < 12; table[0][j++] = 1); 
		
		for (int i = 0; i <= index; i++) {
			for (int j  = 0; j < 12; j++) {
				table[i][j] = tableVal(i, j-1) + tableVal(i - denom[j], j);
			} 
		}

		cout << setw(6) << setprecision(2) << fixed << d << setw(17) << table[index][11] << endl;
	}

}
