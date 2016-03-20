#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
    int TC, d, n, x, y, p, grid[1100][1100], best, best_x, best_y, acc;
    scanf("%d", &TC);
    while(TC--){
        best = 0, best_x = 0, best_y = 0;
        memset((void*)grid, 0, sizeof(int)*1100*1100);
        scanf("%d %d", &d, &n);
        for(int i = 0; i < n; ++i){
            scanf("%d %d %d", &x, &y, &p);
            grid[x][y] = p;
        }
        for(int i = 0; i < 1025; ++i)
            for(int j = 0; j < 1025; ++j){
                grid[i][j] += (i > 0 ? grid[i-1][j] : 0);
                grid[i][j] += (j > 0 ? grid[i][j-1] : 0);
                grid[i][j] -= ((i > 0 && j > 0) ? grid[i-1][j-1] : 0);
            }
        for(int i = d; i < 1025 - d; ++i)
            for(int j = d; j < 1025 - d; ++j){
                acc = grid[i+d][j+d];
                acc -= (i > d ? grid[i-d-1][j+d] : 0);
                acc -= (j > d ? grid[i+d][j-d-1] : 0);
                acc += ((i > d && j > d) ? grid[i-d-1][j-d-1] : 0);
                if(acc > best){
                    best_x = i;
                    best_y = j;
                    best = acc;
                }
            }
        printf("%d %d %d\n", best_x, best_y, best);
    }
}
