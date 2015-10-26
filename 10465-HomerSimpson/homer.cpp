#include<cstdio>
#include<limits>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

short memo[10000][10000];
short m, n, t, bestIdx, bestTr;

short eat(short p, short r){
    if(r < m && r < n) return r >= 0 ? r : 0;
    if(memo[p][r] != -1) return memo[p][r];
    short &ans = memo[p][r] = numeric_limits<short>::max();
    if(r >= m) ans = min(ans, eat(p+1, r-m));
    if(r >= n) ans = min(ans, eat(p+1, r-n));
    if(ans < bestTr || (ans == bestTr && bestIdx < p)){
        bestTr = ans;
        bestIdx = p;
    }
    return ans;
}

int main(){

    while(scanf("%hd %hd %hd", &m, &n, &t) != EOF){
        bestIdx = 0;
        bestTr = numeric_limits<short>::max();
        fill(&memo[0][0], &memo[0][0] + 10000*10000, -1);
        short tr = eat(1, t);
        if(tr){
            printf("%hd %hd\n", bestIdx, tr);
        } else {
            printf("%hd\n", bestIdx);
        }
    }

}
