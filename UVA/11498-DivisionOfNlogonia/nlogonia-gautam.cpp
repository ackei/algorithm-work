#include <iostream>
#include <cstdio>
#define PRINT false
using namespace std;

int main () {

#if PRINT
cout << "Enter number of points: ";
#endif
	int n, i, j, x,y; bool newline = false;
	while(scanf("%i", &n), n) {
#if PRINT
cout << "Enter Division Point Coordinates: ";
#endif
		scanf("%i %i", &i, &j);
		while (n--) {
	
			//if (newline) { printf("\n"); }
			//else { newline = true; }

#if PRINT
cout << "Enter Coordinate Here: ";
#endif
			scanf("%i %i", &x, &y);
			x -=i; y-= j;

			if (x == 0 || y == 0) {
				printf("divisa\n");
			}
			else if (x > 0 && y > 0)
			{
				printf("NE\n");
			}
			else if (x < 0 && y > 0) { 
				printf("NO\n");
			}
			else if (x > 0 && y < 0) {
				printf("SE\n");	
			}
			else {
				printf("SO\n");
			}

		}
	
	}


	return 0;
}
