#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector< vi > vvi;

vvi adjlist;

vi visited;
vi top_sort;

void dfs(int s){
	visited[s] = 1;
	for (int i = 0; i < adjlist[s].size(); i++){
		if (!visited[adjlist[s][i]])
			dfs(adjlist[s][i]);
	}
	top_sort.push_back(s);
}

int main(){
	int K, C, M, P;
	scanf("%d",&K);
	while (K--){
		scanf("%d %d %d",&C,&M,&P);
		adjlist.clear();
		visited.clear();
		top_sort.clear();
		adjlist.assign(M,vi());
		visited.assign(M,0);
		int A, B;
		while (P--){
			scanf("%d %d",&A,&B);
			adjlist[A-1].push_back(B-1);
		}
		for (int i = 0; i < M; i++){
			if (!visited[i])
				dfs(i);
		}
		vi order(M,0);
		vvi parent(M,vi());
		for (int i = M-1; i >= 0; i--){
			int curr = top_sort[i];
			if (parent[curr].size() == 0)
				order[curr] = 1;
			else{
				sort(parent[curr].begin(),parent[curr].end());
				int tmpsize = parent[curr].size();
				int p = parent[curr][tmpsize-1];
				int q = parent[curr][tmpsize-2];
				if (p == q)
					order[curr] = p+1;
				else
					order[curr] = p;
			}
			for (int j = 0; j < adjlist[curr].size(); j++){
				int neighbor = adjlist[curr][j];
				parent[neighbor].push_back(order[curr]);
			}
		}
		printf("%d %d\n",C,order[top_sort[0]]);
	}

	return 0;
}
