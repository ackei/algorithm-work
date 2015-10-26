#include<cstdio>
#include<limits>
#include<algorithm>
#include<cstring>
#include<map>
#include<utility>
using namespace std;

map<pair<short, short>, short> memo;
short m, n, t, bestIdx, bestTr;

short eat(short p, short r){
    if(r < m && r < n) return r >= 0 ? r : 0;
    if(memo.count(pair<short, short>(p, r))) return memo[pair<short, short>(p, r)];
    short ans = numeric_limits<short>::max();
    if(r >= m) ans = min(ans, eat(p+1, r-m));
    if(r >= n) ans = min(ans, eat(p+1, r-n));
    if(ans < bestTr || (ans == bestTr && bestIdx < p)){
        bestTr = ans;
        bestIdx = p;
    }
    memo.insert(pair<pair<short, short>, short>(pair<short,short>(p, r), ans));
    return ans;
}

int main(){

    while(scanf("%hd %hd %hd", &m, &n, &t) != EOF){
        bestIdx = 0;
        bestTr = numeric_limits<short>::max();
        memo.clear();
        short tr = eat(1, t);
        if(tr){
            printf("%hd %hd\n", bestIdx, tr);
        } else {
            printf("%hd\n", bestIdx);
        }
    }

}
