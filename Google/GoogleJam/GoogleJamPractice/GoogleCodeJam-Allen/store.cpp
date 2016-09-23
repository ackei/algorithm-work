#include <cstdio>

int main(){
	int TC, credit, numItems, price;
	scanf("%d",&TC);
	int c = 1;
	while (TC--){
		int items[2005];
		scanf("%d",&credit);
		scanf("%d",&numItems);
		for (int i = 0; i < numItems; i++){
			scanf("%d",&price);
			items[i] = price;
		}
		bool done = false;
		for (int i = 0; i < numItems; i++){
			for (int j = i + 1; j < numItems; j++){
				if (items[i] + items[j] == credit){
					printf("Case #%d: %d %d\n",c++,i+1,j+1);
					done = true;
					break;
				}
			}
			if (done)
				break;
		}
	}
	return 0;
}
