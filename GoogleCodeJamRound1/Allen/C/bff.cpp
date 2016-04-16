#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int bff[1010];
bool seen[1010];

int max_length(vector<vector<int> >& adjacency_list, int start){
	if (adjacency_list[start].size() == 0)
		return 0;
	else{
		int deepest = 0;
		for (int i = 0; i < adjacency_list[start].size(); i++){
			int depth = 1 + max_length(adjacency_list, adjacency_list[start][i]);
			if (depth > deepest)
				deepest = depth;
		}
		return deepest;
	}

}

int main(){
	int TC, c = 1;
	scanf("%d",&TC);
	while (TC--){
		memset(bff,0,sizeof bff);
		memset(seen,0,sizeof seen);
		int N, id;
		scanf("%d",&N);
		for (int i = 0; i < N; i++){
			scanf("%d ",&id);
			bff[i] = id-1;
		}
		vector<vector<int> > cycles;
		for (int i = 0; i < N; i++){
			vector<int> chain;
			int current_chain = 1;
			int current_id = i;
			int next_id = bff[i];
			while (!seen[next_id]){
				chain.push_back(current_id);
				seen[current_id] = true;
				current_id = bff[current_id];
				next_id = bff[current_id];
			}
			vector<int> cycle;
			bool in_cycle = false;
			for (int j = 0; j < chain.size(); j++){
				if (chain[j] == next_id)
					in_cycle = true;
				if (in_cycle)
					cycle.push_back(chain[j]);
			}
			cycles.push_back(cycle);
		}
		// Terrible adjacency list represenation
		vector<vector<int> > adjacency_list;
		for (int i = 0; i < N; i++){
			vector<int> temp;
			for (int j = 0; j < N; j++){
				if (bff[j] == i)
					temp.push_back(j);
			}
			adjacency_list.push_back(temp);
		}
		int longest_chain = 0;
		for (int i = 0; i < cycles.size(); i++){
			int size = cycles[i].size();
			vector<int> max_depths;
			for (int j = 0; j < size; j++){
				max_depths.push_back(max_length(adjacency_list, cycles[i][j]));
			}	
			int total_sum = 0;
			for (int j = 0; j < max_depths.size(); j++){
				total_sum += max_depths[j];
			}
			int chain = total_sum + size;
			if (chain > longest_chain)
				longest_chain = chain;
		}

		printf("Case #%d: %d\n",c++,longest_chain);
	}	
}
