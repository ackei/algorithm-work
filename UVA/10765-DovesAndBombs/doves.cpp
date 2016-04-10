#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

#define UNVISITED -1

int n, m, timer, root, dfs_num[1 << 14], dfs_low[1 << 14],
    dfs_parent[1 << 14], pigeon_num[1 << 14];

vector<vector<int> > adjList;

void dfs(int u){

    int v;
    dfs_low[u] = dfs_num[u] = timer++;
    for(int i = 0; i < adjList[u].size(); ++i){
        v = adjList[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u]) ++pigeon_num[u];
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if(dfs_parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }

}

bool lt(pair<int, int> s1, pair<int, int> s2){
    if(s1.second > s2.second) return true;
    else if(s1.second == s2.second && s1.first <= s2.first) return true;
    else return false;
}

int main(){

    int x, y;
    vector<pair<int, int> > stations;
    while(scanf("%d %d", &n, &m), n && m){
        adjList.clear(); adjList.resize(n); timer = 1; stations.clear();
        fill(dfs_num, dfs_num + n, UNVISITED); fill(pigeon_num, pigeon_num + n, 1);
        while(scanf("%d %d", &x, &y), x != -1 && y != -1){
            adjList[x].push_back(y); adjList[y].push_back(x);
        }
        pigeon_num[0] = 0; dfs(0);
        for(int i = 0; i < n; ++i){ stations.push_back(make_pair(i, pigeon_num[i])); }
        sort(stations.begin(), stations.end(), lt);
        for(int i = 0; i < m; ++i){ printf("%d %d\n", stations[i].first, stations[i].second); }
        printf("\n");
    }

}
