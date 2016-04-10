#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){

    int M;
    while(scanf("%d", &M) != EOF){
        vector<pair<int, int> > ones;
        vector<pair<int, int> > threes;
        int i, j, clr;
        for(i = 0; i < M; ++i){
            for(j = 0; j < M; ++j){
                scanf("%1d", &clr);
                if(clr == 1) ones.push_back(make_pair(i, j));
                if(clr == 3) threes.push_back(make_pair(i, j));
            }
        }
        priority_queue<int> Q;
        for(i = 0; i < ones.size(); ++i){
            int minDist = M*M;
            for(j = 0; j < threes.size(); ++j){
                int dist = abs(ones[i].first - threes[j].first) +
                           abs(ones[i].second - threes[j].second);
                if(dist < minDist) minDist = dist;
            }
            Q.push(minDist);
        }
        printf("%d\n", Q.top());
    }

}
