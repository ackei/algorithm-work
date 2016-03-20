#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define F first
#define S second

typedef unsigned long long int ull;
typedef map<int, ull>::iterator miter;

int main(){
    int T, C=1, N, K, r;
    scanf("%d", &T);
    while(T--){
        //printf("Processing test case %d\n", T);
        map<int, ull> lists[4], plists[2]; ull ctr = 0;
        scanf("%d %d", &N, &K);
        for(int i = 0; i < 4; ++i) for(int j = 0; j < N; ++j){
            scanf("%d", &r);
            if(lists[i].count(r)) ++lists[i][r];
            else lists[i][r] = 1;
        }
        for(miter a = lists[0].begin(); a != lists[0].end(); ++a)
            for(miter b = lists[1].begin(); b != lists[1].end(); ++b)
                if(plists[0].count(a->F^b->F)) plists[0][a->F^b->F] += a->S*b->S;
                else plists[0][a->F^b->F] = a->S*b->S;
        for(miter c = lists[2].begin(); c != lists[2].end(); ++c)
            for(miter d = lists[3].begin(); d != lists[3].end(); ++d)
                if(plists[1].count(c->F^d->F^K)) plists[1][c->F^d->F^K] += c->S*d->S;
                else plists[1][c->F^d->F^K] = c->S*d->S;

        for(miter it = plists[0].begin(); it != plists[0].end(); ++it)
            if(plists[1].count(it->F)) ctr += it->S*plists[1][it->F];

        printf("Case #%d: %llu\n", C++, ctr);
    }
}
