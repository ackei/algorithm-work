#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int A[N][N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&A[i][j]);
			if (i > 0)
				A[i][j] += A[i-1][j];
			if (j > 0)
				A[i][j] += A[i][j-1];
			if (i > 0 && j > 0)
				A[i][j] -= A[i-1][j-1];
		}
	}
	int maxsum = -1270000;
	for (int x1 = 0; x1 < N; x1++) for (int y1 = 0; y1 < N; y1++){
		for (int x2 = x1; x2 < N; x2++) for (int y2 = y1; y2 < N; y2++){
			int sum = A[x2][y2];
			if (x1 > 0)
				sum -= A[x1-1][y2];
			if (y1 > 0)
				sum -= A[x2][y1-1];
			if (x1 > 0 && y1 > 0)
				sum += A[x1-1][y1-1];
			if (sum > maxsum)
				maxsum = sum;
		}
	}
	printf("%d\n",maxsum);
}

