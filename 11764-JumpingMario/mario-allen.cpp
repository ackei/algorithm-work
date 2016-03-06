#include <cstdio>

int main(){
	int TC, count, num, current, next;
	scanf("%d",&TC);
	count = 1;
	while (count <= TC){
		int low = 0, high = 0;
		scanf("%d %d ",&num, &current);
		for (int i = 1; i < num; i++){
			scanf("%d ", &next);
			if (next < current)
				low++;
			else if (next > current)
				high++;
			current = next;
		}
		printf("Case %d: %d %d\n", count++, high, low);
	}
	return 0;
}
