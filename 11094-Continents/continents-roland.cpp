#include<cstdio>
#include<random>
#include<algorithm>
using namespace std;

char map[24][24], land, water;
int M, N, best, mx, my;

int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};

default_random_engine generator;
uniform_int_distribution<int> distribution(0, 3);

int conquer(int x, int y){
    if(x < 0 || M <= x) return 0;
    if(y < 0) y = N-1; if(N <= y) y = 0;
    if(map[x][y] != land) return 0;
    map[x][y] = water; int ans = 1;
    for(int i = 0; i < 4; ++i)
        ans += conquer(x + dx[i], y + dy[i]);
    return ans;
}

int main(){

    while(scanf("%d %d", &M, &N) != EOF){
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                scanf(" %c", &map[i][j]);
        scanf("%d %d", &mx, &my);
        land = map[mx][my]; best = 0; water = '\0';
        for(int i = 0; i < M; ++i) for(int j = 0; j < N; ++j)
            if(map[i][j] != land){
                water = map[i][j]; goto campaign;
            }
        campaign:;
        if(water == '\0'){
            printf("%d\n", 0);
            continue;
        }
        conquer(mx, my);
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                best = max(best, conquer(i, j));
        printf("%d\n", best);
    }
}
