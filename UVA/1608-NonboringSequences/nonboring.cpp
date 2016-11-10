#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool boring(int start, int end, int* a, int size){
	if (end <= start)
		return false;
	map<int,int> int_idx;
	for (int i = 0; i < size; i++){
		if (int_idx.find(a[i]) != int_idx.end())
			int_idx.erase(a[i]);
		else
			int_idx[a[i]] = i;
	}
	vector<int> idxs;
	for (map<int,int>::iterator it = int_idx.begin(); it != int_idx.end(); it++){
		idxs.push_back(it->second);
	}
	if (idxs.size() == 0){
		return true;
	}
	sort(idxs.begin(),idxs.end());
	int prev = 0;
	for (int i = 0; i < idxs.size(); i++){
		if (boring(prev,idxs[i]-1,a,idxs[i]-prev))
			return true;
		prev = idxs[i]+1;
	}
	return false;
}

int main(){
	int TC;
	scanf("%d",&TC);
	while (TC--){
		int n;
		scanf("%d",&n);
		int a[n];
		for (int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		if (boring(0,n-1,a,n))
			printf("boring\n");
		else
			printf("non-boring\n");
	}
	return 0;
}
