#include<map>
#include<cstdio>
#include<utility>
using namespace std;

typedef unsigned long long int ull;

map<pair<ull, ull>, double> memo;
ull T, N, K, A, B, C;

double expt(ull X){
    return A*(X&K)/100.0 + B*(X|K)/100.0 + C*(X^K)/100.0;
}

double RNG(ull X, ull M){
    if(M == 1) return expt(X);
    pair<ull, ull> key = make_pair(X, M);
    if(memo.count(key)) return memo[key];
    double xAk = RNG(X&K, M-1), xOk = RNG(X|K, M-1), xXk = RNG(X^K, M-1);
    memo[key] = A*xAk/100.0 + B*xOk/100.0 + C*xXk/100.0;
    return memo[key];
}

int main(){
    ull X, TT = 1;
    scanf("%llu", &T);
    while(T--){
        memo.clear();
        scanf("%llu %llu %llu %llu %llu %llu", &N, &X, &K, &A, &B, &C);
        for(ull i = 2; i <= N; ++i) RNG(X, i);
        printf("Case #%llu: %.10lf\n", TT++, RNG(X, N));
    }
}
