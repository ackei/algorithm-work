#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

/*
   Data structure to efficiently model disjoint sets
   Main purpose is for the two methods below:
   ~O(1) determine if element is in set
   O(1) to make union between two sets (using C++ sets takes O(n))
*/
class UnionFind{
	private: 
		vi p, rank;
	public:
		UnionFind(int N){
			rank.assign(N,0);
			p.assign(N,0);
			for (int i = 0; i < N; i++)
				p[i] = i;
		}
		
		int findSet(int i){
			return (p[i] == i) ? i : p[i] = findSet(p[i]);
		}
		
		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j){
			if (!isSameSet(i,j)){
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]){
					p[y] = x;
				}
				else{
					p[x] = p[y];
					if (rank[x] == rank[y])
						rank[y]++;
				}
			}
		}

		int numDisjointSets(){
			int total = 0;
			vector<bool> seen;
			seen.assign(p.size(),false);
			for (int i = 0; i < p.size(); i++){
				int n = findSet(i);
				if (!seen[n]){
					total++;
					seen[n] = true;
				}
			}
			return total;
		}

		int sizeOfSet(int i){
			int size = 0;
			int n = findSet(i);
			for (int j = 0; j < p.size(); j++){
				if (findSet(j) == n)
					size++;
			}
			return size;
		}
};

int main(){
	UnionFind set(10);
	set.unionSet(1,2);
	set.unionSet(2,3);
	set.unionSet(5,6);
	cout << set.numDisjointSets() << endl; // 0, {1,2,3},4,{5,6},7,8,9 = 7
	cout << set.sizeOfSet(1) << endl; // 3
	cout << set.sizeOfSet(3) << endl; // 3
	cout << set.sizeOfSet(4) << endl; // 1
	cout << set.sizeOfSet(6) << endl; // 2
	cout << set.isSameSet(1,4) << endl; // 0
	cout << set.isSameSet(2,3) << endl; // 1
	cout << set.isSameSet(5,6) << endl; // 1

	return 0;
}
