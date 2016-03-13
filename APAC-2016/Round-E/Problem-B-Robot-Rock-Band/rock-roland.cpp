#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int main(){
    int T, C=1, N, K, r;
    scanf("%d", &T);
    while(T--){
        vector<int> lists[4]; int ctr = 0; map<int, int> memo;
        scanf("%d %d", &N, &K);
        for(int j = 0; j < N; ++j){
            scanf("%d", &r); lists[0].push_back(r); memo[r] = 0;
        }
        for(int i = 1; i < 4; ++i) for(int j = 0; j < N; ++j){
            scanf("%d", &r); lists[i].push_back(r);
        }
        for(int i = 0; i < N; ++i){
            if(memo[lists[0][i]]){
                ctr += memo[lists[0][i]];
                continue;
            }
            for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) for(int m = 0; m < N; ++m)
                if((lists[0][i]^lists[1][j]^lists[2][k]^lists[3][m]) == K){
                    ++memo[lists[0][i]];
                    ++ctr;
                    //printf("%d %d %d %d\n", i, j, k, m);
                }
        }
        printf("Case #%d: %d\n", C++, ctr);
    }
}
