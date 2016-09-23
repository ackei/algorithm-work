#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

#define UNVISITED -1

int N, timer, dfs_low[1 << 7], dfs_num[1 << 7], dfs_parent[1 << 7], rootChildCounter, root, criticalCounter;
vector<int> adjList[1 << 7];

void dfs(int u){
    int v; dfs_low[u] = dfs_num[u] = timer++;
    bool counted = false;
    for(int i = 0; i < adjList[u].size(); ++i){
        v = adjList[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(u == root) ++rootChildCounter;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u] && !counted && u != root){
                ++criticalCounter;
                counted = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if(dfs_parent[v] != u){ // This is a back edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    string line;
    char* cline;
    int u, v;
    while(scanf("%d", &N), N){
        for(int i = 1; i <= N; ++i){ adjList[i].clear(); }
        while(scanf("%d", &u), u){
            getline(cin, line); stringstream ss(line);
            while(ss >> v){ adjList[u].push_back(v); adjList[v].push_back(u); }
        }
        timer = 1; fill(dfs_num, dfs_num + N + 1, UNVISITED); criticalCounter = 0;
        for(u = 1; u <= N; ++u){
            if(dfs_num[u] == UNVISITED){
                root = u; rootChildCounter = 0;
                dfs(u);
                if(rootChildCounter > 1) ++criticalCounter;
            }
        }
        printf("%d\n", criticalCounter);
    }
}
