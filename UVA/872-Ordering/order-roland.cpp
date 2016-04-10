#include<map>
#include<string>
#include<cstdio>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

int T;
bool hasCycle;
char vars[26];
map<char, bool> avl;
map<char, vector<char> > adj;
map<char, int> in_deg;
map<char, int> dfs_color;
vector<char> order;

#define UNVISITED 0
#define DISCOVERED 1
#define EXPLORED 2

void dfs(char u){
    char v;
    dfs_color[u] = DISCOVERED;
    for(int i = 0; i < adj[u].size(); ++i){
        v = adj[u][i];
        if(dfs_color[v] == DISCOVERED){
            hasCycle = true; return;
        }
        dfs(v);
        if(hasCycle) return;
    }
    dfs_color[u] = EXPLORED;
}

void kahn(){
    bool choice = false;
    for(int i = 0; i < 26; ++i)
        if(avl[vars[i]]){
            avl[vars[i]] = false;
            choice = true;
            order.push_back(vars[i]);
            for(int j = 0; j < adj[vars[i]].size(); ++j)
                if(--in_deg[adj[vars[i]][j]] == 0)
                    avl[adj[vars[i]][j]] = true;
            kahn();
            for(int j = 0; j < adj[vars[i]].size(); ++j){
                ++in_deg[adj[vars[i]][j]]; avl[adj[vars[i]][j]] = false;
            }
            order.pop_back();
            avl[vars[i]] = true;
        }
    if(!choice){
        for(int i = 0; i < order.size(); ++i){
            printf("%c", order[i]);
            if(i < order.size() - 1) printf(" ");
        }
        printf("\n");
    }
}

int main(){
    string line, rel; char var, x, y;
    for(char C = 'A'; C <= 'Z'; ++C) vars[C-'A'] = C;
    scanf("%d ", &T);
    while(T--){
        avl.clear(); adj.clear(); in_deg.clear(); dfs_color.clear(); hasCycle = false;
        getline(cin, line);
        stringstream ss1(line);
        while(ss1 >> var){
            avl[var] = true;
            in_deg[var] = 0;
            dfs_color[var] = UNVISITED;
        }
        getline(cin, line);
        stringstream ss2(line);
        while(ss2 >> rel){
            x = rel[0]; y = rel[2];
            adj[x].push_back(y);
            ++in_deg[y];
            avl[y] = false;
        }
        for(map<char, int>::iterator it = dfs_color.begin(); it != dfs_color.end(); ++it)
            if(it->second == UNVISITED) dfs(it->first);
        if(!hasCycle) kahn();
        else printf("NO\n");
        if(T) printf("\n");
        scanf(" ");
    }
}
