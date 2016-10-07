#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int rows[8], rd, cd, lineCounter;

bool place(int r, int c){
	for (int i = 0; i < c; i++){
		if (rows[i] == r || abs(r-rows[i]) == (c-i))
			return false;
	}
	rows[c] = r;
	return true;
}

void backtrack(int c){
	if (c == 8 && rows[cd] == rd){
		printf("%2d      %d",lineCounter++,rows[0]+1);
		for (int i = 1; i < 8; i++) printf(" %d",rows[i]+1);
		printf("\n");
	}
	for (int r = 0; r < 8; r++){
		if (place(r,c)){
			rows[c] = r;
			backtrack(c+1);
		}
	}
}

int main(){
	scanf("%d %d",&rd,&cd); rd--; cd--;
	memset(rows,0,sizeof rows);
	lineCounter = 1;
	printf("SOLN       COLUMN\n");
	printf(" #      1 2 3 4 5 6 7 8\n\n");
	backtrack(0);

	return 0;
}
