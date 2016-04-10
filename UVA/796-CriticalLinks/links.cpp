#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define UNVISITED -1

bool pair_lt(pair<int, int> left, pair<int, int> right){
        if(left.first < right.first) return true;
        else if(left.first <= right.first && left.second <= right.second) return true;
        else return false;
}

int N, timer;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<vector<int> > adjList;
vector<pair<int, int> > bridges;

void dfs(int u){
    int v;
    dfs_low[u] = dfs_num[u] = timer++;
    for(int i = 0; i < adjList[u].size(); ++i){
        v = adjList[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;

            dfs(v);

            if(dfs_low[v] > dfs_num[u]){
                if(u < v) bridges.push_back(make_pair(u, v));
                else bridges.push_back(make_pair(v, u));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if(dfs_parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){

    int svr, nc, d;
    pair<int, int> edge;

    while(scanf("%d", &N) != EOF){
        adjList.clear(); adjList.resize(N); dfs_num.clear(); dfs_num.resize(N, UNVISITED);
        dfs_low.clear(); dfs_low.resize(N); dfs_parent.clear(); dfs_parent.resize(N);
        timer = 1; bridges.clear();
        for(int i = 0; i < N; ++i){
            scanf("%d (%d)", &svr, &nc);
            for(int j = 0; j < nc; ++j){ scanf("%d", &d); adjList[svr].push_back(d); }
        }
        for(int u = 0; u < N; ++u){ if(dfs_num[u] == UNVISITED){ dfs(u); } }
        sort(bridges.begin(), bridges.end(), pair_lt);
        printf("%d critical links\n", (int)bridges.size());
        for(int i = 0; i < bridges.size(); ++i){
            edge = bridges[i];
            printf("%d - %d\n", edge.first, edge.second);
        }
        printf("\n");
    }

}
