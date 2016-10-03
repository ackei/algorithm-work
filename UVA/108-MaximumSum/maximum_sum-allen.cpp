#include <cstdio>
#include <cstring>

int N, sum_arr[105][105];

int max_sum(){
	int max_rect = -127 * 100 * 100;
	for (int xi = 0; xi < N; xi++) for (int yi = 0; yi < N; yi++)
		for (int xj = xi; xj < N; xj++) for (int yj = yi; yj < N; yj++){
			int rect = sum_arr[xj][yj];
			if (xi > 0) rect -= sum_arr[xi-1][yj];
			if (yi > 0) rect -= sum_arr[xj][yi-1];
			if (xi > 0 && yi > 0) rect += sum_arr[xi-1][yi-1];
			if (rect > max_rect){ 
				max_rect = rect;
			}
		}
	return max_rect;
}

int main(){
	while(scanf("%d",&N) != EOF){
	memset(sum_arr,0,sizeof sum_arr);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
			scanf("%d",&sum_arr[i][j]);
			if (i > 0) sum_arr[i][j] += sum_arr[i-1][j];
			if (j > 0) sum_arr[i][j] += sum_arr[i][j-1];
			if (i > 0 && j > 0) sum_arr[i][j] -= sum_arr[i-1][j-1];
		}
		printf("%d\n",max_sum());
	}
	return 0;
}
