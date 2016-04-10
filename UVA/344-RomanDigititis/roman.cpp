#include<cstdio>
using namespace std;

int numchars[101][5] = {0};

#define CS 0
#define LS 1
#define XS 2
#define VS 3
#define IS 4

void charsIn(int N){
    int n = N;
    if(n == 100){ ++numchars[N][CS]; n -= 100; }
    if(n >= 90){ ++numchars[N][XS]; ++numchars[N][CS]; n -= 90; }
    if(n >= 50){ ++numchars[N][LS]; n-= 50; }
    if(n >= 40){ ++numchars[N][XS]; ++numchars[N][LS]; n-=40; }
    if(n >= 10){ numchars[N][XS] += n / 10; n = n % 10; }
    if(n == 9){ ++numchars[N][IS]; ++numchars[N][XS]; n -= 9; }
    if(n >= 5){ ++numchars[N][VS]; n-=5; }
    if(n == 4){ ++numchars[N][IS]; ++numchars[N][VS]; n-=4; }
    if(n){ numchars[N][IS] += n; }
    numchars[N][CS] += numchars[N-1][CS];
    numchars[N][LS] += numchars[N-1][LS];
    numchars[N][XS] += numchars[N-1][XS];
    numchars[N][VS] += numchars[N-1][VS];
    numchars[N][IS] += numchars[N-1][IS];
}

int main(){
    for(int i = 1; i <= 100; ++i) charsIn(i);
    int N;
    while(scanf("%d", &N) && N){
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", N, numchars[N][IS], numchars[N][VS], numchars[N][XS], numchars[N][LS], numchars[N][CS]);
    }
}
