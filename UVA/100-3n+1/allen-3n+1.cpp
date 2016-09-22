#include <cstdio>
#include <algorithm>

using namespace std;

int cycleLength(int n){
	int count = 1;
	int num = n;
	while (n != 1){
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
		count++;
	}
	return count;
}

int main(){
	
	int i, j, low, high;
	while (scanf("%d %d",&i,&j) != EOF) {
		if (i < j){
			low = i;
			high = j;
		}
		else{
			low = j;
			high = i;
		}
		int count = low;
		int maxSoFar = cycleLength(count);
		while (count <= high){
			maxSoFar = max(maxSoFar,cycleLength(count++));
		}
		printf("%d %d %d\n", i, j, maxSoFar);
	}

	return 0;
}
