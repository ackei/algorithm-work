#include<cstdio>
#include<algorithm>
using namespace std;

typedef unsigned long long int  ull;

ull lengthTable[64];

char swtch(char x){
    if(x == '0') return '1';
    else return '0';
}

char recurse(ull K, int n){
    if(n == 1) return '0';
    if(K <= lengthTable[n-1]){
        return recurse(K, n-1);
    } else if (K == (lengthTable[n-1] + 1)){
        return '0';
    } else {
        K = 2*lengthTable[n-1] - K + 2;
        return swtch(recurse(K, n-1));
    }
}

char googol(ull K){
    int idx = 1;
    while(K > lengthTable[idx]) ++idx;
    return recurse(K, idx);
}

int main(){

    lengthTable[0] = 0;
    for(int i = 1; i < 64; ++i)
        lengthTable[i] = 2*lengthTable[i-1] + 1;
    ull T, K, C = 1;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu", &K);
        printf("Case #%llu: %c\n", C++, googol(K));
    }

}
