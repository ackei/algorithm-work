#include <cstdio>

int main(){
	int size;
	int num[12];
	while (scanf("%d ", &size), size){
		for (int i = 0; i < size; i++){
			scanf("%d ", &num[i]);
		}
		for (int a = 0; a < size-5; a++)
			for (int b = a+1; b < size - 4; b++)
				for (int c = b+1; c < size - 3; c++)
					for (int d = c+1; d < size - 2; d++)
						for (int e = d+1; e < size - 1; e++)
							for (int f = e+1; f < size; f++)
								printf("%d %d %d %d %d %d\n",num[a],num[b],num[c],num[d],num[e],num[f]);
		printf("\n");
	}
}
