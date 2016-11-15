#include <cstdio>
#include <vector>
#include <cstring>

int board[8][8];
vector<int> poss[8][8];	

int dr[8] = {1,2,-1,2,1,-2,-1,-2};
int dc[8] = {2,1,2,-1,-2,1,-2,-1};

void place(int r, int c, int i, int j){
	if (r < 0 || r > 7 || c < 0 || c > 7)
		return;
	if (board[r][c] == -1){
		poss[r][c].push_back(board[i][j]+1);
		poss[r][c].push_back(board[i][j]-1);
	}
}

void backtrack(int r, int c){
	
}

int main(){
	int TC, c;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d",&c);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				scanf("%d",&board[i][j]); poss[i][j].clear();
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				for (int k = 0; k < 8; k++)
					if (board[i][j] > -1)
						place(i+dr[k],j+dc[k],i,j);
			}
		}

					
	}	
	return 0;
}
