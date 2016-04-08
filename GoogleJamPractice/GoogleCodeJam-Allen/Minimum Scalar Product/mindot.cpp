#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool greaterThan(int i, int j){
	return i > j;
}

long long dotProduct(const vector<long long>& v1, const vector<long long>& v2, int size){
	long long sum = 0;
	for (int i = 0; i < size; i++){
		sum += (v1[i] * v2[i]);
	}
	
	return sum;
}

int main(){
	int TC, size, c = 1, num;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d",&size);
		vector<long long> v1, v2;
		for (int i = 0; i < size; i++){
			scanf("%d", &num);
			v1.push_back(num);
		}
		for (int i = 0; i < size; i++){
			scanf("%d", &num);
			v2.push_back(num);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end(),greaterThan);
		printf("Case #%d: %lld\n", c++, dotProduct(v1,v2,size));
	}
	return 0;
}
