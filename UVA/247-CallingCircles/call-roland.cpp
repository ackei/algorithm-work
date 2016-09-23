#include<map>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

#define UNVISITED 0
#define VISITED 1

int n, m;
set<string> V;
map<string, set<string> > adj;
map<string, set<string> > adj_rev;
map<string, int> dfs_num;
vector<string> top_sort;

void topo_dfs(string u){
    dfs_num[u] = VISITED; set<string>::iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); ++it)
        if(dfs_num[*it] == UNVISITED) topo_dfs(*it);
    top_sort.push_back(u);
}

void print_dfs(string u){
    dfs_num[u] = VISITED; set<string>::iterator it;
    for(it = adj_rev[u].begin(); it != adj_rev[u].end(); ++it)
        if(dfs_num[*it] == UNVISITED){
            print_dfs(*it); printf(", ");
        }
    printf("%s", u.c_str());
}

int main(){

    int T = 1;
    string from, to;
    while(cin >> n >> m, n || m){
        if(T > 1) printf("\n");
        adj.clear(); dfs_num.clear(); top_sort.clear(); V.clear();
        for(int i = 0; i < m; ++i){
            cin >> from >> to;
            if(!V.count(from)){
                V.insert(from); set<string> from_list, from_rev;
                adj[from] = from_list; dfs_num[from] = UNVISITED;
                adj_rev[from] = from_rev;
            }
            if(!V.count(to)){
                V.insert(to); set<string> to_list, to_rev;
                adj[to] = to_list; dfs_num[to] = UNVISITED;
                adj_rev[to] = to_rev;
            }
            adj[from].insert(to);
            adj_rev[to].insert(from);
        }
        set<string>::iterator it;
        for(it = V.begin(); it != V.end(); ++it)
            if(dfs_num[*it] == UNVISITED) topo_dfs(*it);
        printf("Calling circles for data set %d:\n", T++);
        for(it = V.begin(); it != V.end(); ++it)
            dfs_num[*it] = UNVISITED;
        for(int i = top_sort.size() - 1; 0 <= i; --i)
            if(dfs_num[top_sort[i]] == UNVISITED){
                print_dfs(top_sort[i]); printf("\n");
            }
    }
}
