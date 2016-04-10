#include <cstdio>

int main(){
	int TC,start = 0;
	while (scanf("%d",&TC),TC){			
		int divX,divY;
		scanf("%d %d",&divX,&divY);
		for (int i = 0; i < TC; i++){
			int testX,testY;
			scanf("%d %d",&testX,&testY);
			testX -= divX;
			testY -=divY;
			if (start++) printf("\n");
			if (testX > 0 && testY > 0)
				printf("NE");
			else if (testX > 0 && testY < 0)
				printf("SE");
			else if (testX < 0 && testY > 0)
				printf("NO");
			else if (testX < 0 && testY < 0)
				printf("SO");
			else
				printf("divisa");
		}
	}
}
