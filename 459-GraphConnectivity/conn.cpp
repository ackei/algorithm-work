#include<vector>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        int numSets;
    public:
        UnionFind(int numElements){
            parent.assign(numElements, 0);
            rank.assign(numElements, 0);
            size.assign(numElements, 1);
            numSets = numElements;
            for(int i = 0; i < numElements; ++i){ parent[i] = i; }
        }
        int findSet(int x){
            if(parent[x] != x)
                parent[x] = findSet(parent[x]);
            return parent[x];
        }
        void unionSet(int x, int y){
            int rep_x = findSet(x), rep_y = findSet(y),
                sz_x = size[rep_x], sz_y = size[rep_y];
            if(rep_x == rep_y) return;
            if(rank[rep_x] < rank[rep_y]){
                parent[rep_x] = rep_y;
            } else if(rank[rep_x] == rank[rep_y]){
                parent[rep_x] = rep_y;
                ++rank[rep_y];
            } else {
                parent[rep_y] = rep_x;
            }
            --numSets;
            size[findSet(x)] = sz_x + sz_y;
        }
        int numDisjointSets(){ return numSets; }
        int sizeOfSet(int i){ return size[findSet(i)]; }
};

int main(){
    int N;
    string line;
    char K, s, d;
    scanf("%d ", &N);
    while(N--){
        scanf("%s ", &K);
        UnionFind ufds(K - 'A' + 1);
        while(getline(cin, line)){
            if(line.size() == 2){
                sscanf(line.c_str(), "%c%c", &s, &d);
                ufds.unionSet(s - 'A', d - 'A');
            } else {
                break;
            }
        }
        printf("%d\n", ufds.numDisjointSets());
    }
}
