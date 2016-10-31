#include <stdio.h>

int main(){
	int A[35];
	int n, i = 0, size = 0;
	int start = 0;
	int current = A[0];
	int uplen = 0, downlen = 0, upcount = 0, downcount = 0;
	int currlen = 0, status = start;
	while (scanf("%d",&n),n){
		size = 1;
		i = 0;
		A[i++] = n;
		while (scanf("%d",&n),n){
			size++;
			A[i++] = n;
		}
		start = 0;
		current = A[0];
		for (i = 1; i < size; i++){
			if (A[i] < current){
				start = -1; 
				break;
			}
			else if (A[i] > current){
				start = 1; 
				break;
			}
		}
		uplen = 0, downlen = 0, upcount = 0, downcount = 0;
		currlen = 0, status = start;
		if (status == 0){
			printf("Nr values = %d:  %.6f %.6f\n",size,0.0,0.0);
		}
		else{
			for (i = 1; i < size; i++){
				currlen++;
				if (status == -1){
					if (A[i] > A[i-1]){
						downlen += currlen - 1;
						currlen = 1;
						downcount++;
						status = 1;
					}	
				}
				else if (status == 1){
					if (A[i] < A[i-1]){
						uplen += currlen - 1;
						currlen = 1;
						upcount++;
						status = -1;
					}	
				}
			}
			if (currlen > 0){
				if (status == -1){
					downlen += currlen; 
					downcount++;
				}
				else{
					uplen += currlen; 
					upcount++;
				}
			}
			printf("Nr values = %d:  %.6f %.6f\n",size, upcount ? (float)uplen/upcount : 0.0, downcount ? (float)downlen/downcount : 0);
		}
	}
}
