#include <stdio.h>

int main(){
	unsigned int M[256];
	while (scanf("%1X",M) != EOF){
		int i;
		for (i = 1; i < 256; i++){
			scanf("%1X",&M[i]);
		}
		int A, B, tmp;
		i = 0;
		A = 0;
		B = 0;
		int exit = 0;
		while (i < 256){
			switch(M[i]){
				case 0:
					A = M[16 * M[i+1] + M[i+2]];
					i+=3;
					break;
				case 1:
					M[16 * M[i+1] + M[i+2]] = A;
					i+=3;
					break;
				case 2:;
					tmp = A;
					A = B;
					B = tmp;
					i++;
					break;
				case 3:;
					tmp = A+B;
					A = tmp % 16;
					B = tmp / 16;
					i++;
					break;
				case 4:
					A = (A + 1) % 16;
					i++;
					break;
				case 5:
					A = (A + 15) % 16;
					i++;
					break;
				case 6:
					if (!A)
						i = 16 * M[i+1] + M[i+2];
					else
						i+=3;
					break;
				case 7:
					i = 16 * M[i+1] + M[i+2];
					break;
				case 8:
					exit = 1;
					break;
			}
			if (exit)
				break;
		}
		for (int i = 0; i < 256; i++){
			printf("%1X",M[i]);
		}
		printf("\n");
	}
}
