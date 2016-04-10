#include<cstdio>
#include<vector>
using namespace std;

int N, T = 1;
vector<vector<char> > board;

int dr[6] = {-1, 0, 1, -1, 0, 1};
int dc[6] = {-1, -1, 0, 0, 1, 1};

bool top, bottom;

bool floodFillWhite(int i, int j){
    if(i < 0 || N <= i || j < 0 || N <= j) return false;
    if(board[i][j] != 'w') return false;
    board[i][j] = 'a';
    if(j == 0) bottom = true; if(j == N-1) top = true;
    if(top && bottom) return true;
    for(int k = 0; k < 6; ++k)
        if(floodFillWhite(i + dr[k], j + dc[k])) return true;
    return false;
}

bool floodFillBlack(int i, int j){
    if(i < 0 || N <= i || j < 0 || N <= j) return false;
    if(board[i][j] != 'b') return false;
    board[i][j] = 'a';
    if(i == 0) bottom = true; if(i == N-1) top = true;
    if(top && bottom) return true;
    for(int k = 0; k < 6; ++k)
        if(floodFillBlack(i + dr[k], j + dc[k])) return true;
    return false;
}

int main(){

    char c;
    while(scanf("%d", &N), N){
        board.clear(); board.resize(N);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j){
                scanf(" %c", &c); board[i].push_back(c);
            }
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j){
                top = bottom = false;
                if(board[i][j] == 'w' && floodFillWhite(i, j)){
                    printf("%d W\n", T++);
                    goto endwhile;
                }
                top = bottom = false;
                if(board[i][j] == 'b' && floodFillBlack(i, j)){
                    printf("%d B\n", T++);
                    goto endwhile;
                }
            }
        endwhile:;
    }

}
