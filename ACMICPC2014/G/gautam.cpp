#include <iostream>
using namespace std;



int main() {

	int numCases; cin >> numCases;
	while(numCases--) {
		int count, x,y;
		cin >> count; cin >> x; cin >> y;

		const int X = 1;
		const int Y = 2;

		int numx = x-1;
		int numy = y-1;

		int indexx = numx - X;
		int indexy = numy - Y;
		
		int index = (indexx < indexy) ? indexx : indexy;
		
		if (y > x) { cout << count << " " << 2 << " " << x << " " << y << "\n"; continue; } 
	
		if (index <= 0) { cout << count << " NO PATH" << "\n"; continue; }
		
		cout << count << " ";
			
		int i; int pathLength = 6; cout << pathLength << " ";
		for (i = 1; i < 4; i++) {
			cout << i << " ";
		} 
		int s = i-1 + (x - X);
		int w = s+1;
		int a = w - (y - Y);
		cout << a << " " << s << " " << w << "\n"; 
	}

	return 0;
}
