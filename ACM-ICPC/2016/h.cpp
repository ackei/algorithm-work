#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

int main(){
	int TC, c, N;
	scanf("%d",&TC);
	while (TC--){
		nums.clear();
		scanf("%d %d", &c, &N);
		nums.assign(N,0);
		for (int i = 0; i < N; i++){
			scanf("%d",&nums[i]);
		}
		vector<int> sorted_nums(nums);
		sort(sorted_nums.begin(),sorted_nums.end());
		int answer = 0;
		int curr = 0;
		for (int i = 0; i < N; i++){
			if (nums[i] != sorted_nums[curr])
				answer++;
			else{
				curr++;
			}
		}
		printf("%d %d\n",c,answer);
	}
	return 0;
}
