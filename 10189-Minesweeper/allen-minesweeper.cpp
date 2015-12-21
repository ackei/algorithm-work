#include <cstdio>
#include <cstring>

int answer[100][100];

void increase(int i, int j){
	if (i < 0 || j < 0 || i > 99 || j > 99 || answer[i][j] < 0)
		return;
	else{
		answer[i][j]++;
	}
}

void increaseSurrounding(int i , int j){
	increase(i-1,j-1);
	increase(i-1,j);
	increase(i-1,j+1);
	increase(i,j-1);
	increase(i,j+1);
	increase(i+1,j-1);
	increase(i+1,j);
	increase(i+1,j+1);
}

int main(){
	int num = 1, rows, cols;
	while (scanf("%d %d", &rows, &cols) && rows && cols){
		if (num > 1) 
			printf("\n");
		memset(answer,0,sizeof answer);
		char mineElt;
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				scanf(" %c",&mineElt);
				if (mineElt == '*'){
					answer[i][j] = -1;
					increaseSurrounding(i,j);
				}
			}
		}	
		printf("Field #%d:\n", num++);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				int check = answer[i][j];
				if (check < 0)
					printf("*");
				else
					printf("%d",check);
			}
			printf("\n");
		}
	}
	return 0;
}
