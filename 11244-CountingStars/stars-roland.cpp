#include<cstdio>
using namespace std;

int R, C,
    dx[8] = {1, 1, 0, -1, -1, -1, 0, 1},
    dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char sky[1 << 7][1 << 7];

int floodfill(int x, int y){
    if(x < 0 || R <= x || y < 0 || C <= y) return 0;
    if(sky[x][y] != '*') return 0;
    int ans = 1; sky[x][y] = '.';
    for(int i = 0; i < 8; ++i)
        ans += floodfill(x + dx[i], y + dy[i]);
    return ans;
}

int main(){

    char tile; int stars;
    while(scanf("%d %d", &R, &C), R && C){
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j){
                scanf(" %c", &tile);
                sky[i][j] = tile;
            }
        stars = 0;
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                stars += floodfill(i, j) == 1 ? 1 : 0;
        printf("%d\n", stars);
    }
}
